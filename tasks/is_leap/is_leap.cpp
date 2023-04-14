#include "is_leap.h"

bool IsLeap(int year) {
    const int first_magicnumber = 400;
    const int second_magicnumber = 100;
    if (year % 4 == 0 && year % second_magicnumber != 0) {
        return true;
    }
    if (year % first_magicnumber == 0) {
        return true;
    }
    return false;
}
