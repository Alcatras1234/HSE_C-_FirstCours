#include "reduce_fraction.h"

int64_t ReduceFraction(int64_t numerator, int64_t denominator) {
    int64_t sum = 0;
    int64_t numerator1 = numerator;
    int64_t denominator1 = denominator;
    int64_t gsd = INT64_MAX;
    while (gsd > 0) {
        gsd = numerator1 % denominator1;
        numerator1 = denominator1;
        denominator1 = gsd;
    }
    sum = numerator / numerator1 + denominator / numerator1;
    return sum;
}
