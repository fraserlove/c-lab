/*
 * Pipeline.c
 *
 *  Created on: 26 Mar 2021
 *      Author: jonl
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Pipeline.h"

#define MAX_PIPELINE_SIZE 1000

Pipeline* new_Pipeline() {
    Pipeline* this = malloc(sizeof(Pipeline));
    this->stages = malloc(MAX_PIPELINE_SIZE * sizeof(Function));
    this->pipes = malloc(MAX_PIPELINE_SIZE * sizeof(Pipe));
    this->size = 0;
    return this;
}


bool Pipeline_add(Pipeline* this, Function f) {
    if (this->size < MAX_PIPELINE_SIZE) {
        this->stages[this->size] = f;
        if (pipe(this->pipes[this->size++]) < 0) {
            perror("pipe");
            exit(1);
        }
        return true;
    }
    return false;
}


void Pipeline_execute(Pipeline* this) {
    pid_t cpid;

    for (int i = 0; i < this->size; i++) {
        if ((cpid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        else if (cpid == 0) {
            if (i < this->size - 1) {
                this->stages[i](this->pipes[i][0], this->pipes[i+1][1]);
            }
            else {
                this->stages[i](this->pipes[i][0], 0);
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

