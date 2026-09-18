# Lab 01 — Dynamic Matrices

The first C++ laboratory work.

The program is a console application for working with dynamically allocated integer matrices. Memory is managed manually using `new[]` and `delete[]`.

## Features

The program allows you to:

- create matrices of arbitrary size;
- fill a matrix with a specified value;
- fill a matrix manually;
- modify an individual matrix element;
- print a matrix to the console;
- swap two rows;
- swap two columns;
- delete created matrices;
- store multiple matrices simultaneously.

When the internal matrix storage becomes full, its capacity is automatically increased.

## Variant

**Variant 16**

Two main operations are implemented:

```cpp
void matrix_row_swap(int** m, std::size_t cols, std::size_t r1, std::size_t r2);
void matrix_col_swap(int** m, std::size_t rows, std::size_t c1, std::size_t c2);
```

### Row Swap

Rows are swapped by exchanging their pointers:

```cpp
int* cur = m[r1];
m[r1] = m[r2];
m[r2] = cur;
```

The elements of the rows are not copied.

### Column Swap

Columns are swapped element by element for each row of the matrix.

## Project Structure

```text
lab_01/
├── include/
│   ├── algorithm.hpp
│   ├── main.hpp
│   └── matrix_operations.hpp
│
├── src/
│   ├── algorithm.cpp
│   ├── main.cpp
│   └── matrix_operations.cpp
│
├── test/
│   ├── algorithm_test.cpp
│   └── matrix_operations_test.cpp
│
├── .clang-format
├── .gitignore
└── CMakeLists.txt
```

### `include/`

Contains function declarations and the data structures used by the program.

### `src/`

Contains the program implementation:

- `main.cpp` — console menu and user interaction;
- `matrix_operations.cpp` — matrix creation, deletion, filling, and printing;
- `algorithm.cpp` — row and column swap algorithms.

### `test/`

Contains unit tests written using GoogleTest.

## Memory Management

Matrices are allocated dynamically:

```cpp
int** matrix = new int*[rows];

for (std::size_t i = 0; i < rows; i++) {
    matrix[i] = new int[cols];
}
```

Memory is released in the reverse order:

```cpp
for (std::size_t i = 0; i < rows; i++) {
    delete[] m[i];
}

delete[] m;
```

Multiple matrices are stored using the `aom` structure, which contains an array of matrix pointers and information about their dimensions.

## Build

The project uses **CMake** and the **C++20** standard.

From the root `Labs` directory:

```bash
cmake -S . -B build
cmake --build build
```

Run the laboratory program:

```bash
./build/lab_01/lab01
```

## Testing

**GoogleTest** is used for testing.

Run all tests through CTest:

```bash
ctest --test-dir build --output-on-failure
```

The laboratory work contains **10 tests** covering:

- matrix storage initialization;
- matrix creation;
- matrix deletion;
- matrix filling;
- matrix printing;
- manual matrix filling;
- row swapping;
- column swapping;
- swapping the first and last rows;
- swapping the first and last columns.

## AddressSanitizer

AddressSanitizer is enabled during the build to detect errors related to dynamic memory management:

```text
-fsanitize=address
-fno-omit-frame-pointer
```

It can detect issues such as out-of-bounds memory access, `use-after-free`, and other memory-related errors.

## Formatting

`clang-format` is used to maintain a consistent code style.

Check formatting:

```bash
find lab_01/include lab_01/src lab_01/test -type f \( -name '*.hpp' -o -name '*.cpp' \) -exec clang-format --dry-run --Werror --style=file {} +
```

Format the source files:

```bash
find lab_01/include lab_01/src lab_01/test -type f \( -name '*.hpp' -o -name '*.cpp' \) -exec clang-format -i --style=file {} +
```

## Technologies Used

- C++20
- CMake
- GoogleTest
- CTest
- AddressSanitizer
- clang-format

## Conclusion

During this laboratory work, a console application for working with dynamic matrices in C++ was implemented. The work involved manual dynamic memory management using `new[]` and `delete[]`, working with multi-level pointers, and organizing the storage of multiple dynamically allocated matrices.

For Variant 16, row swapping was implemented by exchanging row pointers, while column swapping was implemented by exchanging the corresponding elements. The program logic was separated into individual source and header files.

CMake was used to build the project, while the correctness of the main operations was verified using GoogleTest and CTest. AddressSanitizer was used to detect errors related to dynamic memory management, and `clang-format` was used to maintain a consistent code style.