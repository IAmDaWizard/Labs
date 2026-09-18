#include "algorithm.hpp"

void matrix_row_swap(int** m, std::size_t cols, std::size_t r1, std::size_t r2) {
    if (m == nullptr) {
        return;
    }
    int* cur = m[r1];
    m[r1] = m[r2];
    m[r2] = cur;
}

void matrix_col_swap(int** m, std::size_t rows, std::size_t c1, std::size_t c2) {
    if (m == nullptr) {
        return;
    }
    std::size_t i{};
    for (; i < rows; i++) {
        int cur = m[i][c1];
        m[i][c1] = m[i][c2];
        m[i][c2] = cur;
    }
}
