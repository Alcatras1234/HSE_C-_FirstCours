#pragma once

template <typename T>
T Unique(T begin, T end) {
    if (begin == end) {
        return end;
    }
    T end_second = begin;
    while (begin != end) {
        ++begin;
        if (*end_second != *begin) {
            *(++end_second) = *begin;
        }
    }
    return end_second;
}