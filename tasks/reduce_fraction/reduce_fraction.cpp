#include "reduce_fraction.h"

#include "math.h"

int64_t ReduceFraction(int64_t numerator, int64_t denominator) {
    int64_t sum = 0;
    int64_t a1 = numerator;
    int64_t a2 = denominator;
    if (numerator == 1 || denominator == 1) {
        sum += numerator + denominator;
    }
    int64_t i = 2;
    while (a1 != 1 || a2 != 1) {
        if (a1 % i == 0 && a2 % i == 0) {
            a1 /= i;
            a2 /= i;
        }
        i++;
    }
    sum += a1 + a2;
    return sum;
}
