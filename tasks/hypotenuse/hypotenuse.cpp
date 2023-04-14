#include "hypotenuse.h"

double CalculateHypotenuse(int64_t a, int64_t b) {
    double c = sqrt(static_cast<double_t>(pow(a, 2)) + static_cast<double_t>(pow(b, 2)));
    return c;
};
