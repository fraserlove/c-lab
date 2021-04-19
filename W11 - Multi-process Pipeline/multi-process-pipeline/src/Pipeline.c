#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Pipeline.h"

Pipeline* new_Pipeline() {
    Pipeline* this = malloc(sizeof(Pipeline));
    this->stages = malloc(MAX_PIPELINE_SIZE * sizeof(Function));
    this->pipes = malloc(MAX_PIPELINE_SIZE * sizeof(Pipe));
    this->size = 0;
    return this;
}


bool Pipeline_add(Pipeline* this, Function f) {
    if (this->size < MAX_PIPELINE_SIZE) { // Only add a new process to the pipeline if there is sufficient space for it
        this->stages[this->size] = f;
        if (pipe(this->pipes[this->size++]) < 0) { // Creating a new pipe for the new stage to communicate with
            perror("pipe() failed"); // Exit if there is an error when creating a pipe
            exit(1);
        }
        return true;
    }
    return false;
}


void Pipeline_execute(Pipeline* this) {
    pid_t cpid;
    for (int i = 0; i < this->size; i++) {
        if ((cpid = fork()) < 0) { // Create new child process
            perror("fork() failed"); // Exit process if a new child process was unable to be created
            exit(1);
        }
        else if (cpid == 0) {  // Child
            if (i < this->size - 1) {
                // Input of function is read end of current pipe and output is into the write end of the next pipe
                this->stages[i](this->pipes[i][0], this->pipes[i+1][1]);
            }
            else {
                // On the last pipe we can discard the write end
                this->stages[i](this->pipes[i][0], 0);
            }
        }
        else {  // Parent
            wait(NULL); // Wait for child process to finish execution
            return;
        }
    }
}


void Pipeline_free(Pipeline* this) {
    free(this->stages);
    free(this->pipes);
    free(this);
}
