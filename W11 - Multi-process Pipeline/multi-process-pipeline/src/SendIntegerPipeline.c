#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "Pipeline.h"

int in;

static void sendInt(int input, int output) {
    close(input);
    printf("sendInt: process %i, parent %i\n", getpid(), getppid());
    write(output, &in, sizeof(int));
    printf("Sent: %d\n", in);
}


static void receiveInt(int input, int output) {
    close(output);
    printf("receiveInt: process %i, parent %i\n", getpid(), getppid());
    int out;
    read(input, &out, sizeof(int));
    printf("Received: %d\n", out);
}

static void cleanupExit(Pipeline *p) {
    if (p) {
        Pipeline_free(p);
    }
    exit(-1);
}

int main() {
    scanf("%d", &in);
    printf("Setting up pipeline to send integer %d from parent to child process.\n", in);

    Pipeline *p = new_Pipeline();

    if (p == NULL) cleanupExit(p);
    if (!Pipeline_add(p, sendInt)) cleanupExit(p);
    if (!Pipeline_add(p, receiveInt)) cleanupExit(p);
    Pipeline_execute(p);

    Pipeline_free(p);
    return 0;
}
