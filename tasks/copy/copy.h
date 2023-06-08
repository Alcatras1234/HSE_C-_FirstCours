#pragma once

template <typename T, typename U>
U Copy(T src_begin, T src_end, U dest) {
    for (T i = src_begin; i != src_end; ++i) {
        *dest = *i;
        ++dest;
    }
    return dest;
}

template <typename T, typename U>
U CopyBackward(T src_begin, T src_end, U dest) {
    while (src_begin != src_end) {
        --dest;
        --src_end;
        *dest = *src_end;
    }
    return dest;
}