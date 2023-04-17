#include "hypotenuse.h"

double CalculateHypotenuse(int64_t a, int64_t b) {
    double c = sqrt(pow(static_cast<double_t>(a), 2) + pow(static_cast<double_t>(b), 2));
    return c;
};
