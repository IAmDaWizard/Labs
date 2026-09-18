#include "matrix_operations.hpp"

#include <sstream>

#include <gtest/gtest.h>

TEST(MatrixTest, InitializeMatrices) {
    aom* matr = initialize_matrices();
    ASSERT_NE(matr, nullptr);
    EXPECT_EQ(matr->len, 100000);
    ASSERT_EQ(matr->n, 0);
    ASSERT_NE(matr->array, nullptr);
    ASSERT_NE(matr->rows, nullptr);
    ASSERT_NE(matr->cols, nullptr);
    int** matrix = matrix_create(3, 3);
    ASSERT_NE(matrix, nullptr);
    matr->array[matr->n] = matrix;
    matr->rows[matr->n] = 3;
    matr->cols[matr->n++] = 3;
    EXPECT_EQ(matr->n, 1);
    EXPECT_EQ(matr->len, 100000);
    EXPECT_EQ(matr->array[0], matrix);
    EXPECT_EQ(matr->rows[0], 3);
    EXPECT_EQ(matr->cols[0], 3);
    matrix_delete(matrix, 3);
    delete[] matr->array;
    delete[] matr->rows;
    delete[] matr->cols;
    delete matr;
}

TEST(MatrixTest, MatrixCreate) {
    int** matrix = matrix_create(3, 3);
    EXPECT_NE(matrix, nullptr);
    int** matrix_2 = matrix_create(100, 100);
    EXPECT_NE(matrix_2, nullptr);
    int** matrix_3 = matrix_create(1000, 234);
    EXPECT_NE(matrix_3, nullptr);
    int** matrix_4 = matrix_create(345, 72);
    EXPECT_NE(matrix_4, nullptr);
    matrix_delete(matrix, 3);
    matrix_delete(matrix_2, 100);
    matrix_delete(matrix_3, 1000);
    matrix_delete(matrix_4, 345);
}

TEST(MatrixTest, MatrixDelete) {
    int** matrix = matrix_create(3, 3);
    ASSERT_NE(matrix, nullptr);
    matrix_fill(matrix, 3, 3, 7);
    matrix_delete(matrix, 3);
}

TEST(MatrixTest, MatrixFill) {
    int** matrix = matrix_create(3, 3);
    ASSERT_NE(matrix, nullptr);
    matrix_fill(matrix, 3, 3, 7);
    for (int i = 0; i < 3; i++) {
        ASSERT_NE(matrix[i], nullptr);
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(matrix[i][j], 7);
        }
    }
    matrix_delete(matrix, 3);
}

TEST(MatrixTest, MatrixPrint) {
    int** matrix = matrix_create(2, 2);
    ASSERT_NE(matrix, nullptr);
    matrix_fill(matrix, 2, 2, 7);
    testing::internal::CaptureStdout();
    matrix_print(matrix, 2, 2);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\n7 7 \n7 7 \n");
    matrix_delete(matrix, 2);
}

TEST(MatrixTest, SelfCompletion) {
    int** matrix = matrix_create(2, 2);
    ASSERT_NE(matrix, nullptr);
    std::istringstream input("1 2 3 4");
    std::streambuf* old_cin = std::cin.rdbuf(input.rdbuf());
    testing::internal::CaptureStdout();
    self_completion(matrix, 2, 2);
    std::string output = testing::internal::GetCapturedStdout();
    std::cin.rdbuf(old_cin);
    EXPECT_EQ(matrix[0][0], 1);
    EXPECT_EQ(matrix[0][1], 2);
    EXPECT_EQ(matrix[1][0], 3);
    EXPECT_EQ(matrix[1][1], 4);
    EXPECT_EQ(output, "Row 1: Row 2: ");
    matrix_delete(matrix, 2);
}
