#include "caesar_cipher.h"

#include <valarray>

std::string Decipher(const std::string& cipher, size_t shift) {
    std::string decihper;
    std::string copy = cipher;
    size_t size = cipher.size() - 1;
    const int ascii_max = 90;
    const int twentysix = 26;
    for (int i = 0; i < size; ++i) {
        if (static_cast<char>(copy[i] + shift) > ascii_max) {
            int shift2 = static_cast<char>(copy[i] + shift - twentysix);
            decihper[i] = static_cast<char>('A' + shift2);
        }
        decihper[i] = static_cast<char>(copy[i] + shift);
    }
    return decihper;
}
