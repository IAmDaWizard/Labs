#include "algorithm.hpp"

#include <gtest/gtest.h>

#include "matrix_operations.hpp"

TEST(MatrixTest, RowSwap) {
    int** matrix = matrix_create(3, 3);
    ASSERT_NE(matrix, nullptr);

    matrix_fill(matrix, 3, 3, 7);
    for (int i = 0; i < 3; i++) {
        ASSERT_NE(matrix[i], nullptr);
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(matrix[i][j], 7);
        }
    }
    matrix[1][1] = 4;
    matrix_row_swap(matrix, 3, 0, 1);

    EXPECT_EQ(matrix[0][1], 4);
    matrix_row_swap(matrix, 3, 1, 1);
    EXPECT_EQ(matrix[0][1], 4);
    matrix_delete(matrix, 3);
}

TEST(MatrixTest, ColumnSwap) {
    int** matrix = matrix_create(4, 4);
    ASSERT_NE(matrix, nullptr);

    matrix_fill(matrix, 4, 4, 9);
    for (int i = 0; i < 4; i++) {
        ASSERT_NE(matrix[i], nullptr);
        for (int j = 0; j < 4; j++) {
            EXPECT_EQ(matrix[i][j], 9);
        }
    }
    matrix[0][0] = 7;
    matrix_col_swap(matrix, 4, 0, 1);

    EXPECT_EQ(matrix[0][1], 7);
    matrix_col_swap(matrix, 4, 1, 1);
    EXPECT_EQ(matrix[0][1], 7);
    matrix_delete(matrix, 4);
}

TEST(MatrixTest, RowSwapFirstAndLast) {
    int** matrix = matrix_create(3, 2);
    ASSERT_NE(matrix, nullptr);
    matrix[0][0] = 1;
    matrix[2][0] = 5;
    matrix_row_swap(matrix, 2, 0, 2);
    EXPECT_EQ(matrix[0][0], 5);
    EXPECT_EQ(matrix[2][0], 1);
    matrix_delete(matrix, 3);
}

TEST(MatrixTest, ColumnSwapFirstAndLast) {
    int** matrix = matrix_create(2, 3);
    ASSERT_NE(matrix, nullptr);
    matrix[0][0] = 2;
    matrix[0][2] = 8;
    matrix_col_swap(matrix, 2, 0, 2);
    EXPECT_EQ(matrix[0][0], 8);
    EXPECT_EQ(matrix[0][2], 2);
    matrix_delete(matrix, 2);
}
