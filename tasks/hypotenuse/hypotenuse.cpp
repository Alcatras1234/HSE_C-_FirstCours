#include "hypotenuse.h"

double CalculateHypotenuse(int64_t a, int64_t b) {
    double c = static_cast<double_t>(sqrt((pow(a, 2)) + (pow(b, 2))));
    return c;
};
