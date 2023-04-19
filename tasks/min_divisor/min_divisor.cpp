#include "min_divisor.h"

#include "math.h"

int64_t MinDivisor(int64_t number) {
    int64_t mindiv = 1;
    int64_t sqrtmindiv = static_cast<int64_t>(round(sqrt(number)));
    for (int64_t i = 2; i <= sqrtmindiv; ++i) {
        if (number % i == 0) {
            mindiv = i;
            break;
        }
    }
    if (mindiv == 1) {
        mindiv = number;
    }
    return mindiv;
}
