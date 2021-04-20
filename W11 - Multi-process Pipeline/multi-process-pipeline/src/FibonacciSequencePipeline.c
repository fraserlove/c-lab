#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "Pipeline.h"

static int max_ints;
int n1, n2;

static void fibSetup(int input, int output) {
    n1 = 1;
    n2 = 0;
    close(input);
    printf("fibSetup: process %i, parent %i\n", getpid(), getppid());
    write(output, &n1, sizeof(int));
    write(output, &n2, sizeof(int));
}

static void runFibonacci(int input, int output) {
    read(input, &n1, sizeof(int));
    read(input, &n2, sizeof(int));
    int fib = n1 + n2;
    printf("Fibonacci: process %i, parent %i: fib = %i\n", getpid(), getppid(), fib);
    write(output, &fib, sizeof(int));
    write(output, &n1, sizeof(int));
}


static void cleanupExit(Pipeline *p) {
    if (p) {
        Pipeline_free(p);
    }
    exit(-1);
}

int main() {
    scanf("%i", &max_ints);
    printf("Setting up pipeline to calculate %i numbers in the Fibonacci Sequence\n", max_ints);

    Pipeline *p = new_Pipeline();
    if (p == NULL) cleanupExit(p);
    if (!Pipeline_add(p, fibSetup)) cleanupExit(p);
    for (int i = 0; i < max_ints; i++) {
        if (!Pipeline_add(p, runFibonacci)) cleanupExit(p);
    }
    Pipeline_execute(p);

    Pipeline_free(p);
    return 0;
}
