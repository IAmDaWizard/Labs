#pragma once
#include <cstddef>
typedef struct Array_Of_Matrices {
    int len{100000};
    int n{};
    int*** array{nullptr};
    std::size_t* rows{nullptr};
    std::size_t* cols{nullptr};
} aom;
