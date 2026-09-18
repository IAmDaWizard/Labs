#include "../include/main.h"
#include <cstddef>
#include <iostream>

aom *initialize_matrices() {
  aom *matr = new aom;
  int ***array = new int **[100000]{};
  std::size_t *r = new size_t[100000]{};
  std::size_t *c = new size_t[100000]{};
  matr->array = array;
  matr->rows = r;
  matr->cols = c;
  return matr;
}

int **matrix_create(std::size_t rows, std::size_t cols) {
  int **matrix = new int *[rows];
  for (std::size_t i = 0; i < rows; i++) {
    matrix[i] = new int[cols];
  }
  return matrix;
}

void matrix_delete(int **m, std::size_t rows) {
  if (m == nullptr)
    return;
  for (std::size_t i{}; i < rows; i++) {
    delete[] m[i];
    m[i] = nullptr;
  }
  delete[] m;
}

void matrix_fill(int **m, std::size_t rows, std::size_t cols, int value) {
  if (m == nullptr)
    return;
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      m[i][j] = value;
    }
  }
}

void matrix_print(const int *const *m, std::size_t rows, std::size_t cols) {
  if (m == nullptr)
    return;
  std::cout << '\n';
  for (std::size_t i{}; i < rows; i++) {
    for (std::size_t j{}; j < cols; j++) {
      std::cout << m[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

void self_completion(int **m, std::size_t rows, std::size_t cols) {
  if (m == nullptr)
    return;
  for (int i{}; i < rows; i++) {
    std::cout << "Row " << i + 1 << ": ";
    for (int j{}; j < cols; j++)
      if (!(std::cin >> m[i][j]))
        std::cin.clear();
  }
}
