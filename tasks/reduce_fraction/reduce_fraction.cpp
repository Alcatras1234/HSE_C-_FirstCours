#include "reduce_fraction.h"

#include "math.h"

int64_t ReduceFraction(int64_t numerator, int64_t denominator) {
    int64_t sum = 0;
    int64_t a1 = numerator;
    int64_t a2 = denominator;
    int64_t i = a1;
    while (true) {
        if (a1 % i == 0 && a2 % i == 0) {
            break;
        }
        i--;
    }
    sum = a1 / i + a2 / i;
    return sum;
}
