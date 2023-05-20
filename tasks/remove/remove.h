#pragma once

template <typename T, typename U>
T FindFirst(T begin, T end, U value) {
    while (begin != end) {
        if (*begin == value) {
            break;
        } else {
            ++begin;
        }
    }
    return begin;
}

template <typename T, typename U>
T Remove(T begin, T end, U value) {
    T first = FindFirst(begin, end, value);
    if (first != end) {
        for (T i = first + 1; i != end; ++i) {
            if (*i != value) {
                *first = *i;
                first += 1;
            }
        }
    }
    return first;
}