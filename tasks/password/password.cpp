#include "password.h"

#include <ctype.h>

bool ValidatePassword(const std::string& password) {
    int upchar = 0;
    int lowerchar = 0;
    int number = 0;
    int other = 0;
    const int THERTYTHREE = 33;
    const int ONEHUNDREDTWENTYSIX = 126;
    const std::__cxx11::basic_string<char>::size_type low_length = 8;
    const std::__cxx11::basic_string<char>::size_type max_length = 14;
    if (password.length() >= low_length && password.length() <= max_length) {
        for (std::__cxx11::basic_string<char>::size_type i = 0; i < password.length(); ++i) {
            int passwordchar = password[i];
            if (passwordchar < THERTYTHREE) {
                if (passwordchar > ONEHUNDREDTWENTYSIX) {
                    return false;
                }
            }
            if (std::islower(passwordchar)) {
                lowerchar = 1;
            } else if (std::isupper(passwordchar)) {
                upchar = 1;
            } else if (std::isdigit(passwordchar)) {
                number = 1;
            } else {
                other = 1;
            }
        }
    }
    if (number + other + upchar + lowerchar >= 3) {
        return true;
    }
    return false;
}
