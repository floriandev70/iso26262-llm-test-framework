#include <gtest/gtest.h>

#include "../Lab/includes/math_lib.h"

int main(int argc, char **argv) {
    std::cout << "Tests start now..." << std::endl;
    // prints
    dcdc_ntc_temp_def my_ntc_temp;
    //std::cout << Temp_Calc_Pres_Wacol_Temp_48V(&my_ntc_temp) << std::endl;
    //::testing::InitGoogleTest(&argc, argv);
    //::testing::GTEST_FLAG(filter) = "NOT_THERE.*";
    return RUN_ALL_TESTS();
}
