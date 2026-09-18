add_library(lab01_lib
        src/matrix_operations.cpp
        src/algorithm.cpp
)

target_include_directories(lab01_lib PUBLIC include)

add_executable(lab01 src/main.cpp)

target_link_libraries(lab01 PRIVATE lab01_lib)

add_executable(lab01_tests
        test/matrix_operations_test.cpp
        test/algorithm_test.cpp
)

target_link_libraries(lab01_tests PRIVATE
        lab01_lib
        GTest::gtest_main
)

add_test(NAME Lab01Tests COMMAND lab01_tests)
