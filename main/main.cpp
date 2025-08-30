#include <gtest/gtest.h>

#include "../Lab/includes/math_lib.h"

int main(int argc, char **argv) {
    std::cout << "Tests start now..." << std::endl;
    // prints
    //::testing::InitGoogleTest(&argc, argv);
    ::testing::GTEST_FLAG(filter) = "ASIL_A.*";
    return RUN_ALL_TESTS();
}
