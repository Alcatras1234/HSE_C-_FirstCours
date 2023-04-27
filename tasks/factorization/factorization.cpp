#include "factorization.h"

std::vector<std::pair<int64_t, int>> Factorize(int64_t x) {
    std::vector<std::pair<int64_t, int>> pare = std::vector<std::pair<int64_t, int>>();
    int64_t copy = x;
    for (int64_t i = 2; i * i <= x; ++i) {
        int count = 0;
        if (copy % i == 0) {
            while (copy % i == 0) {
                ++count;
                copy = copy / i;
            }
            pare.emplace_back(i, count);
        }
    }
    if (copy != 1) {
        pare.emplace_back(copy, 1);
    }
    if (pare.empty()) {
        pare.emplace_back(x, 1);
    }
    return pare;
}
