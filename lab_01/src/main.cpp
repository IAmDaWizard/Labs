#include <iostream>
#include <cstddef>
#include "../include/matrix_operations.h"
#include "../include/main.h"
#include "../include/algorithm.h"

int main() {
    aom *matrices = initialize_matrices();
    while (true) {
        int n{};
        std::cout << "\nWhat do you want to do?\n\n";
        std::cout << "1. Create a matrix.   2. Fill the matrix by a value. \n\n";
        std::cout << "3. Print a matrix.    4. Swap two rows of a matrix. \n\n";
        std::cout << "5. Swap two columns of an array.   6. Delete a matrix. \n\n";
        std::cout << "7. Fill a position of a matrix by a value.    8. Fill a matrix by myself. \n\n";
        std::cout << "0. Exit. \n\n";
        std::cout << "Enter a value: ";

        if (!(std::cin >> n)) { std::cin.clear(); }
        if (n == 0) {
            int i{};
            for (; i < matrices->n; i++) {
                matrix_delete(matrices->array[i], matrices->rows[i]);
            }
            delete[] matrices->rows;
            delete[] matrices->cols;
            delete[] matrices->array;
            delete matrices;
            break;
        }
        if (n == 1) {
            size_t a{}, b{};
            std::cout << "Enter a number of rows: ";
            if (!(std::cin >> a)) { std::cin.clear(); }
            std::cout << "Enter a number of columns: ";
            if (!(std::cin >> b)) { std::cin.clear(); }
            int **matrix = matrix_create(a, b);
            matrices->array[matrices->n] = matrix;
            matrices->rows[matrices->n] = a;
            matrices->cols[matrices->n++] = b;
            if (matrices->n == matrices->len) {
                int ***old_array = matrices->array;
                std::size_t *rows = matrices->rows;
                std::size_t *cols = matrices->cols;
                matrices->len *= 2;
                int new_len = matrices->len;

                int ***new_array = new int **[new_len]{};
                std::size_t *new_rows = new std::size_t[new_len]{};
                std::size_t *new_cols = new std::size_t[new_len]{};

                for (int i{}; i < new_len / 2; i++) {
                    new_array[i] = old_array[i];
                    new_rows[i] = rows[i];
                    new_cols[i] = cols[i];
                }
                matrices->array = new_array;
                matrices->rows = new_rows;
                matrices->cols = new_cols;
                delete[] old_array;
                delete[] rows;
                delete[] cols;
            }
        } else if (n == 2) {
            int a{}, b{};
            std::cout << "Enter a number of matrix you want to fill: ";
            if (!(std::cin >> a)) { std::cin.clear(); }
            if (matrices->n < a || a < 1) {
                std::cout << "There's no matrix with this number! \n";
                continue;
            }
            std::cout << "Enter a value you want to fill by your matrix: ";
            if (!(std::cin >> b)) { std::cin.clear(); }
            int **matr = matrices->array[a - 1];
            matrix_fill(matr, matrices->rows[a - 1], matrices->cols[a - 1], b);
        } else if (n == 3) {
            int a{};
            std::cout << "Enter a number of matrix you want to print: ";
            if (!(std::cin >> a)) { std::cin.clear(); }
            if (matrices->n < a || a < 1) {
                std::cout << "There's no matrix with this number! \n";
                continue;
            }
            int **matr = matrices->array[a - 1];
            matrix_print(matr, matrices->rows[a - 1], matrices->cols[a - 1]);
        } else if (n == 4) {
            std::size_t a{}, b{};
            std::cout << "Enter numbers of rows you want to swap: ";
            if (!(std::cin >> a >> b)) { std::cin.clear(); }
            int i{};
            std::cout << "Enter a number of matrix you want to change: ";
            if (!(std::cin >> i)) { std::cin.clear(); }
            if (matrices->n < i || i < 1) {
                std::cout << "There's no matrix with this number! \n";
                continue;
            }
            if (a < 1 || b < 1 || a > matrices->rows[i - 1] || b > matrices->rows[i - 1]) {
                std::cout << "There's no row with this number!\n";
                continue;
            }
            matrix_row_swap(matrices->array[i - 1], matrices->cols[i - 1], a - 1, b - 1);
        } else if (n == 5) {
            std::size_t a{}, b{};
            std::cout << "Enter numbers of columns you want to swap: ";
            if (!(std::cin >> a >> b)) { std::cin.clear(); }
            int i{};
            std::cout << "Enter a number of matrix you want to change: ";
            if (!(std::cin >> i)) { std::cin.clear(); }
            if (matrices->n < i || i < 1) {
                std::cout << "There's no matrix with this number! \n";
                continue;
            }
            if (a < 1 || b < 1 || a > matrices->cols[i - 1] || b > matrices->cols[i - 1]) {
                std::cout << "There's no column with this number!\n";
                continue;
            }
            matrix_col_swap(matrices->array[i - 1], matrices->rows[i - 1], a - 1, b - 1);
        } else if (n == 6) {
            int a{};
            std::cout << "Enter a number of matrix you want to delete: ";
            if (!(std::cin >> a)) { std::cin.clear(); }
            if (matrices->n < a || a < 1) {
                std::cout << "There's no matrix with this number! \n";
                continue;
            }
            int **matr = matrices->array[a - 1];
            matrix_delete(matr, matrices->rows[a - 1]);
            matrices->array[a - 1] = nullptr;

            int len = matrices->n, i{a - 1};
            for (; i < len - 1; i++) {
                matrices->array[i] = matrices->array[i + 1];
                matrices->cols[i] = matrices->cols[i + 1];
                matrices->rows[i] = matrices->rows[i + 1];
            }
            matrices->array[len - 1] = nullptr;
            matrices->rows[len - 1] = 0;
            matrices->cols[len - 1] = 0;
            matrices->n--;
        } else if (n == 7) {
            int a{}, row{}, column{}, value{};
            std::cout << "Enter a number of the matrix: ";
            if (!(std::cin >> a)) { std::cin.clear(); }
            if (matrices->n < a || a < 1) {
                std::cout << "There's no matrix with this number! \n";
                continue;
            }
            std::cout << "Enter a row: ";
            if (!(std::cin >> row)) { std::cin.clear(); }
            std::cout << "Enter a column: ";
            if (!(std::cin >> column)) { std::cin.clear(); }
            std::cout << "Enter a value: ";
            if (!(std::cin >> value)) { std::cin.clear(); }
            if (row < 1 || row > matrices->rows[a - 1] || column < 1 || column > matrices->cols[a - 1]) {
                std::cout << "There's no element with these coordinates! \n";
                continue;
            }
            matrices->array[a - 1][row - 1][column - 1] = value;
        } else if (n == 8) {
            int a{};
            std::cout << "Enter a number of the matrix: ";
            if (!(std::cin >> a)) { std::cin.clear(); }
            if (matrices->n < a || a < 1) {
                std::cout << "There's no matrix with this number! \n";
                continue;
            }
            self_completion(matrices->array[a - 1], matrices->rows[a - 1], matrices->cols[a - 1]);
        } else std::cout << "Choose an operation with a correct sequence number\n";
    }


    return 0;
}
