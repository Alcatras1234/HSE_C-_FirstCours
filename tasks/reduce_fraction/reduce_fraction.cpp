#include "reduce_fraction.h"

int64_t ReduceFraction(int64_t numerator, int64_t denominator) {
    int64_t sum = 0;
    int64_t a1 = numerator;
    int64_t a2 = denominator;
    int64_t gsd = INT64_MAX;
    while (gsd > 0) {
        gsd = a1 % a2;
        a1 = a2;
        a2 = gsd;
    }
    sum = numerator / a1 + denominator / a1;
    return sum;
}
