#include "is_leap.h"

bool IsLeap(int year) {
    const int fourhundred = 400;
    const int hundred = 100;
    if (year % 4 == 0 && year % hundred != 0) {
        return true;
    }
    if (year % fourhundred == 0) {
        return true;
    }
    return false;
}
