#include "const_diagonal.h"

void BuildDiagonalArray(TableType table) {
    int number = 0;
    for (int i = 0; i < COLUMNS; ++i) {
        for (int j = 0; j - i <= 0; ++j) {
            table[j][i - j] = number;
            ++number;
        }
    }
    for (int i = 1; i < LINES; ++i) {
        for (size_t j = i; j < COLUMNS; ++j) {
            table[j][COLUMNS - j + i - 1] = number;
            ++number;
        }
    }
}
