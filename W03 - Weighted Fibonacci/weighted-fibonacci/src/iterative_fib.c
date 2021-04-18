
#include "fib.h"
#include "safe_maths.h"

long long fibcalc(long long n) {
    long long res = 0;
    long long i1 = 1;
    long long i2 = 0;
    for (long long i = 1; i < n; i++) {
        res = safe_add(i1, safe_add(i2, i2)); // equivalent to i1 + 2 * i2;
        i2 = i1;
        i1 = res;
    }
    return (n == 1) ? i1 : res;
}