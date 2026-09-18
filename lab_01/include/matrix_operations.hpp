#ifndef LABS_MATRIX_OPERATIONS_H
#define LABS_MATRIX_OPERATIONS_H
#pragma once
#include <cstddef>
#include "main.hpp"

aom* initialize_matrices();

int **matrix_create(std::size_t rows, std::size_t cols);

void matrix_delete(int **m, std::size_t rows);

void matrix_fill(int **m, std::size_t rows, std::size_t cols, int value);

void matrix_print(const int *const*m, std::size_t rows, std::size_t cols);

void self_completion(int** m, std::size_t rows, std::size_t cols);
#endif //LABS_MATRIX_OPERATIONS_H
