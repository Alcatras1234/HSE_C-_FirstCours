#include "caesar_cipher.h"

#include <ctype.h>

#include <valarray>

std::string Decipher(const std::string& cipher, size_t shift) {
    std::string decihper;
    std::string copy = cipher;
    size_t size = cipher.size() - 1;
    const int ascii_max = 90;
    const int twentysix = 26;
    const int sixtyfive = 65;
    for (int i = 0; i < size; ++i) {
        if (std::isalpha(copy[i])) {
            if (static_cast<char>(copy[i] + shift) > ascii_max) {
                int shift2 = static_cast<char>(copy[i] + shift - twentysix);
                decihper[i] = static_cast<char>(sixtyfive + shift2);
            } else {
                decihper[i] = static_cast<char>(copy[i] + shift);
            }
        }
    }
    return decihper;
}
