#include "is_leap.h"

bool IsLeap(int year) {
    const int FOURHUNDRED = 400;
    const int HUNDRED = 100;
    if (year % 4 == 0 && year % HUNDRED != 0) {
        return true;
    }
    if (year % FOURHUNDRED == 0) {
        return true;
    }
    return false;
}
