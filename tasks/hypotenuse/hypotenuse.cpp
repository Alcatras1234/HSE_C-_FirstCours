#include "hypotenuse.h"

double CalculateHypotenuse(int64_t a, int64_t b) {
    double c = sqrt(a * a + b * b);
    return c;
};
