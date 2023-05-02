#include "caesar_cipher.h"

#include <valarray>

std::string Decipher(const std::string& cipher, size_t shift) {
    std::string decihper = " ";
    std::string copy = cipher;
    size_t size = cipher.size() - 1;
    for (int i = 0; i < size; ++i) {
        decihper += static_cast<char>(copy[i] + shift);
    }
    return decihper;
}
