#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Pipeline.h"

#define MAX_PIPELINE_SIZE 1000

typedef int Pipe[2];

Pipeline* new_Pipeline() {
    Pipeline* this = malloc(sizeof(Pipeline));
    this->stages = malloc(MAX_PIPELINE_SIZE* sizeof(Function));
    this->size = 0;
    return this;
}


bool Pipeline_add(Pipeline* this, Function f) {
    if (this->size + 1 < MAX_PIPELINE_SIZE) {
        this->stages[this->size++] = f;
        return true;
    }
    return false;
}


void Pipeline_execute(Pipeline* this) {
    Pipe pipes[this->size];
    pid_t cpid;
    for (int i = 0; i < this->size; i++) {
        if (pipe(pipes[i]) < 0) {
            perror("pipe");
            exit(1);
        }
    }

    for (int i = 0; i < this->size; i++) {
        if ((cpid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        else if (cpid == 0) {
            if (i < this->size - 1) {
                this->stages[i](pipes[i][0], pipes[i+1][1]);
            }
            else {
                this->stages[i](pipes[i][0], 0);
            }
        }
        else {
            wait(NULL);
            exit(0);
        }
    }
}


void Pipeline_free(Pipeline* this) {
    free(this->stages);
    free(this);
}