#include "caesar_cipher.h"

#include <ctype.h>

#include <valarray>

std::string Decipher(const std::string& cipher, size_t shift) {
    std::string decihper;
    std::string copy = cipher;
    size_t size = cipher.size();
    const int chara = 65;
    const int twentysix = 26;
    for (size_t i = 0; i < size; ++i) {
        int symbol = copy[i];
        if (std::isalpha(symbol)) {
            if (static_cast<char>(symbol - shift) < chara) {
                int shift2 = static_cast<char>(symbol - shift) + twentysix;
                decihper += static_cast<char>(shift2);
            } else {
                decihper += static_cast<char>(symbol - shift);
            }
        }
    }
    return decihper;
}
