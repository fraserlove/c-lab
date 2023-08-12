#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

long long safe_add(long long a, long long b) {
    if ((a > 0 && b > LLONG_MAX) || (a < 0 && b < LLONG_MIN - a)) {
        printf("\nOverflow\n");
        exit(0);
    }
    return a + b;
}