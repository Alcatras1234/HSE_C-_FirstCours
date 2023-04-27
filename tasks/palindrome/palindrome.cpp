#include "palindrome.h"

bool IsPalindrome(const std::string& str) {
    std::__cxx11::basic_string<char>::size_type left = 0;
    std::__cxx11::basic_string<char>::size_type right = str.size() - 1;
    if (str.empty()) {
        return true;
    }
    while (left < right) {
        if (str[left] == ' ') {
            ++left;
        } else if (str[right] == ' ') {
            --right;
        } else if (str[left] == str[right]) {
            ++left;
            --right;
        } else {
            return false;
        }
    }
    return true;
}
