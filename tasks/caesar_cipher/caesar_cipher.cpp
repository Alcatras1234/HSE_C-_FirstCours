#include "caesar_cipher.h"

#include <ctype.h>

#include <valarray>

std::string Decipher(const std::string& cipher, size_t shift) {
    std::string decihper;
    size_t size = cipher.size();
    const int a_in_int = 65;
    const int alphabet_size = 26;
    for (size_t i = 0; i < size; ++i) {
        int symbol = cipher[i];
        if (std::isalpha(symbol)) {
            if (static_cast<char>(symbol - shift) < a_in_int) {
                int shift2 = static_cast<char>(symbol - shift) + alphabet_size;
                decihper += static_cast<char>(shift2);
            } else {
                decihper += static_cast<char>(symbol - shift);
            }
        }
    }
    return decihper;
}
