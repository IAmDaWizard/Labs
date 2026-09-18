# C++ Laboratory Works

A collection of C++ laboratory works completed as part of my university studies.

This repository contains practical assignments focused on learning modern C++, manual memory management, algorithms, data structures, testing, build systems, and software development practices.

## Repository Structure

Each laboratory work is located in a separate directory and contains its own source code, headers, tests, build configuration, and documentation.

```text
Labs/
├── lab_01/
│   ├── include/
│   ├── src/
│   ├── test/
│   ├── CMakeLists.txt
│   └── README.md
│
├── lab_02/
├── lab_03/
├── ...
│
├── .gitignore
├── CMakeLists.txt
└── README.md
```

Detailed information about each assignment, its implementation, and conclusions can be found in the corresponding laboratory directory.

## Laboratory Works

| Lab | Topic | Status |
|:---:|---|:---:|
| [Lab 01](lab_01/) | Dynamic Matrices | ✅ Completed |
| Lab 02 | Coming soon | ⏳ Planned |
| Lab 03 | Coming soon | ⏳ Planned |

The table will be updated as new laboratory works are completed.

## Technologies

The repository currently uses:

- C++20
- CMake
- GoogleTest
- CTest
- AddressSanitizer
- clang-format

Additional tools and technologies may be introduced in future laboratory works.

## Build

The repository is organized as a single CMake project.

From the repository root, configure the project:

```bash
cmake -S . -B build
```

Build all available targets:

```bash
cmake --build build
```

Individual laboratory works are connected to the root CMake project through their own `CMakeLists.txt` files.

## Testing

Automated tests are implemented using **GoogleTest** and integrated with **CTest**.

To run all registered tests:

```bash
ctest --test-dir build --output-on-failure
```

AddressSanitizer is used to help detect memory-related errors during development and testing.

## Code Style

The source code is formatted using `clang-format` to maintain a consistent style across the repository.

Laboratory works follow a common project structure with separate directories for:

- header files;
- source files;
- tests.

## Goals

The main goal of this repository is to document my progress in learning C++ through practical university assignments.

The laboratory works are intended to develop experience with:

- C++ syntax and language features;
- pointers and manual memory management;
- dynamic data structures;
- algorithms and data processing;
- modular program organization;
- unit testing;
- CMake-based project configuration;
- debugging and memory error detection;
- consistent code style and project structure.

As the course progresses, this repository will be expanded with new laboratory works and more advanced C++ concepts.