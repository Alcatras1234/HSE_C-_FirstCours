#pragma once

template <typename Iterator>
void Reverse(Iterator begin, Iterator end) {
    while (begin != end && begin != --end) {
        auto temp = *begin;
        *begin = *end;
        *end = temp;
        ++begin;
    }
}

template <typename Iterator>
void Rotate(Iterator begin, Iterator mid, Iterator end) {
    reverse(begin, mid);
    reverse(mid, end);
    reverse(begin, end);
}