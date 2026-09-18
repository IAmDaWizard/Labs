cmake_minimum_required(VERSION 4.1)
project(Labs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        -g
        -fsanitize=address
        -fno-omit-frame-pointer
)

add_link_options(-fsanitize=address)
find_package(GTest QUIET)
if (NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG v1.15.2
    )
    FetchContent_MakeAvailable(googletest)
endif ()

enable_testing()
add_subdirectory(lab_01)
