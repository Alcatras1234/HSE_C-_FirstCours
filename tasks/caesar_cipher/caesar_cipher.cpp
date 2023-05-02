#include "caesar_cipher.h"

std::string Decipher(const std::string& cipher, size_t shift) {
    std::string decihper = "";
    int size = cipher.size() - 1;
    for (int i = 0; i < size; ++i) {
        decihper += cipher[i] + shift;
    }
    return decihper;
}
