#include "hypotenuse.h"

double CalculateHypotenuse(int64_t a, int64_t b) {
    double c = sqrt(double_t(pow(a, 2)) + double_t(pow(b, 2)));
    return c;
};
