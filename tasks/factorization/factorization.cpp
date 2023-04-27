#include "factorization.h"

std::vector<std::pair<int64_t, int>> Factorize(int64_t x) {
    std::vector<std::pair<int64_t, int>> a = std::vector<std::pair<int64_t, int>>();
    int64_t copy = x;
    for (int64_t i = 2; i * i <= x; ++i) {
        int count = 0;
        if (copy % i == 0) {
            while (copy % i == 0) {
                ++count;
                copy = copy / i;
            }
            a.emplace_back(i, count);
        }
    }
    if (copy != 1) {
        a.emplace_back(copy, 1);
    }
    if (a.empty()) {
        a.emplace_back(x, 1);
    }
    return a;
}
