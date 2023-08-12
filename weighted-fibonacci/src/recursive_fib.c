#include "fib.h"
#include "safe_maths.h"

long long fibcalc(long long n) {
    if (n < 2) {
        return n;
    } else {
        return safe_add(fibcalc(n-1), safe_add(fibcalc(n-2), fibcalc(n-2))); // equivalent to fibcalc(n-1) + 2 * fibcalc(n-2);
    }
}
