#include "next_even.h"

int64_t NextEven(int64_t n) {
    int64_t a = n % 2 == 0 ? n + 2 : n + 1;
    return a;
}
