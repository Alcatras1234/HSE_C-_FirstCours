#include "min_divisor.h"

#include "math.h"

int64_t MinDivisor(int64_t number) {
    int64_t a = 1;
    int64_t sqrta = static_cast<int64_t>(round(sqrt(number)));
    for (int64_t i = 2; i <= sqrta; ++i) {
        if (number % i == 0) {
            a = i;
            break;
        }
    }
    if (a == 1) {
        a = number;
    }
    return a;
}
