#include "password.h"

#include <ctype.h>

bool ValidatePassword(const std::string& password) {
    int upchar = 0;
    int lowerchar = 0;
    int number = 0;
    int other = 0;
    if (password.length() >= 8 && password.length() <= 14) {
        for (std::__cxx11::basic_string<char>::size_type i = 0; i < password.length(); ++i) {
            int passwordchar = password[i];
            if (passwordchar < 33) {
                if (passwordchar > 126) {
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
