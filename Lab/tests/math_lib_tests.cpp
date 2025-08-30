/*
* ISO 26262 SW test subset:
 *
 * Structural coverage metrics at the software unit level
 * -Statement Coverage
 * -Branch Coverage
 * -MC/DC Coverage
 *
 * Methods for software unit verification
 * -Requirement-based test
 *
 * Methods for deriving test cases
 * -Analysis of requirements
 * -Generation and analysis of equivalence classes
 * -Analysis of boundary values
 * -Error guessing
 */

#include <iostream>
#include "gtest/gtest.h"
#include "../includes/math_lib.h"

/*ALL TESTS GENERATED in the PhD Research LAB by the ISO 26262 ASIL B Test Assistant (GPT4 Turbo) on 11.04.2024.*/

TEST(ASIL_B, add) {
    EXPECT_EQ(add(0, 500), 500);
    EXPECT_EQ(add(1000, 500), 1500);
    EXPECT_EQ(add(-1, 500), -1);
    EXPECT_EQ(add(500, -1), -1);
    EXPECT_EQ(add(1001, 500), -1);
    EXPECT_EQ(add(500, 1001), -1);
    EXPECT_EQ(add(750, 751), -1);
}

TEST(ASIL_B, subtract) {
    EXPECT_EQ(subtract(-1, 0), -1);
    EXPECT_EQ(subtract(0, -1), -1);
    EXPECT_EQ(subtract(0, 1), -1);
    EXPECT_EQ(subtract(1001, 0), -1);
    EXPECT_EQ(subtract(0, 1001), -1);
    EXPECT_EQ(subtract(0, 0), 0);
    EXPECT_EQ(subtract(1, 2), -1);
    EXPECT_EQ(subtract(1, 1), 0);
}

TEST(ASIL_B, add_ref) {
    EXPECT_EQ(add_ref(0, 0), 0);
    EXPECT_EQ(add_ref(750, 750), 1500);
    EXPECT_EQ(add_ref(1001, 500), -1);
    EXPECT_EQ(add_ref(500, 1001), -1);
    EXPECT_EQ(add_ref(-1, 500), -1);
    EXPECT_EQ(add_ref(500, -1), -1);
    EXPECT_EQ(add_ref(1000, 501), -1);
}

TEST(ASIL_B, subtract_ref) {
    EXPECT_EQ(subtract_ref(0, 0), 0);
    EXPECT_EQ(subtract_ref(1000, 500), 500);
    EXPECT_EQ(subtract_ref(1, 2), -1);
    EXPECT_EQ(subtract_ref(-1, 500), -1);
    EXPECT_EQ(subtract_ref(500, -1), -1);
    EXPECT_EQ(subtract_ref(1000, 999), 1);
    EXPECT_EQ(subtract_ref(1000, 1000), 0);
    EXPECT_EQ(subtract_ref(1001, 10), -1);
    EXPECT_EQ(subtract_ref(500, 1001), -1);
}

TEST(ASIL_B, multiply_ref) {
    EXPECT_EQ(multiply_ref(0, 0), 0);
    EXPECT_EQ(multiply_ref(10, 10), 100);
    EXPECT_EQ(multiply_ref(1001, 10), -1);
    EXPECT_EQ(multiply_ref(10, 1001), -1);
    EXPECT_EQ(multiply_ref(-1, 10), -1);
    EXPECT_EQ(multiply_ref(10, -1), -1);
    EXPECT_EQ(multiply_ref(501, 3), -1);
}

TEST(ASIL_B, divide_ref) {
    EXPECT_EQ(divide_ref(0, 1), 0);
    EXPECT_EQ(divide_ref(10, 0), -1);
    EXPECT_EQ(divide_ref(1001, 10), -1);
    EXPECT_EQ(divide_ref(10, 1001), -1);
    EXPECT_EQ(divide_ref(-1, 10), -1);
    EXPECT_EQ(divide_ref(10, -1), -1);
    EXPECT_EQ(divide_ref(1000, 10), 100);
}

TEST(ASIL_B, factorial) {
    EXPECT_EQ(factorial(0), 1);
    EXPECT_EQ(factorial(1), 1);
    EXPECT_EQ(factorial(3), 6);
    EXPECT_EQ(factorial(1001), -1);
    EXPECT_EQ(factorial(-1), -1);
    EXPECT_EQ(factorial(6), 720);  // Corrected maximum without exceeding the range
    EXPECT_EQ(factorial(7), -1);
}

TEST(ASIL_B, prime_number_ref) {
    EXPECT_EQ(prime_number_ref(-1), -1);
    EXPECT_EQ(prime_number_ref(1001), -1);
    EXPECT_EQ(prime_number_ref(0), 0);
    EXPECT_EQ(prime_number_ref(1), 0);
    EXPECT_EQ(prime_number_ref(2), 1);
    EXPECT_EQ(prime_number_ref(4), 0);
    EXPECT_EQ(prime_number_ref(29), 1);
    EXPECT_EQ(prime_number_ref(35), 0);
}

TEST(ASIL_B, fibonacci_ref) {
    EXPECT_EQ(fibonacci_ref(-1), -1);
    EXPECT_EQ(fibonacci_ref(1001), -1);
    EXPECT_EQ(fibonacci_ref(0), 0);
    EXPECT_EQ(fibonacci_ref(1), 1);
    EXPECT_EQ(fibonacci_ref(7), 13);
    EXPECT_EQ(fibonacci_ref(16), 987);
    EXPECT_EQ(fibonacci_ref(17), -1);
}

TEST(ASIL_A_2, fibonacci) {
        EXPECT_EQ(fibonacci(0), 0);
        EXPECT_EQ(fibonacci(1), 1);
        EXPECT_EQ(fibonacci(1501), -1);
        EXPECT_EQ(fibonacci(12), 144);
        EXPECT_EQ(fibonacci(17), 987);
}