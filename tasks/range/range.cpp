#include "range.h"

std::vector<int> Range(int from, int to, int step) {
    int from1 = from;
    int to1 = to;
    std::vector<int> vecrange;
    if (from1 == to1) {
        return vecrange;
    }
    if (from < to && step > 0) {
        for (int i = from1; i < to1; i = i + step) {
            vecrange.push_back(i);
        }
    } else if (from > to && step < 0) {
        for (int i = from1; i > to1; i = i + step) {
            vecrange.push_back(i);
        }
    } else {
        return vecrange;
    }
    return vecrange;
}
