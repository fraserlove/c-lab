#include <stdio.h>
#include <stdlib.h>

#include "fib.h"

void print_fib() {
    int n;
    printf("Length? ");
    scanf("%i", &n);

    if (n < 0) {
        printf("Invalid input\n");
        exit(0);
    }

    printf("[");
    for (int i = 0; i < n - 1; i++) {
        printf("%llu, ", fibcalc(i));
    }
    if (n > 0)
        printf("%llu", fibcalc(n - 1));
    printf("]\n");
}