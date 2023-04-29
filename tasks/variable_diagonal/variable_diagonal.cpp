#include "variable_diagonal.h"

int** BuildDiagonalArray(size_t lines, size_t columns) {
    int** matrix = new int*[lines];
    for (size_t i = 0; i < lines; ++i) {
        matrix[i] = new int[columns];
    }
    int number = 0;
    for (size_t i = 0; i < columns; ++i) {
        for (size_t j = 0; j - i <= 0; ++j) {
            matrix[j][i - j] = number;
            ++number;
        }
    }
    for (size_t i = 1; i < lines; ++i) {
        for (size_t j = i; j < columns; ++j) {
            matrix[j][columns - j + i - 1] = number;
            ++number;
        }
    }
    return matrix;
}