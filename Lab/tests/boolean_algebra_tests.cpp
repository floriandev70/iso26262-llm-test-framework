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
#include "../includes/boolean_algebra.h"

/*ALL TESTS GENERATED in the PhD Research LAB by the ISO 26262 ASIL A Test Assistant (GPT4 Turbo) on 11.04.2024.*/

TEST(ASIL_A, return_0){
 EXPECT_EQ(return_0(), 0);
}

TEST(ASIL_A, return_1){
 EXPECT_EQ(return_1(), 1);
}

TEST(ASIL_A, return_a){
 EXPECT_EQ(return_a(true), true);
 EXPECT_EQ(return_a(false), false);
}

TEST(ASIL_A, return_NOT_a){
 EXPECT_EQ(return_NOT_a(true), false);
 EXPECT_EQ(return_NOT_a(false), true);
}

TEST(ASIL_A, check_a_OR_b){
 EXPECT_TRUE(check_a_OR_b(true, false));
 EXPECT_TRUE(check_a_OR_b(false, true));
 EXPECT_TRUE(check_a_OR_b(true, true));
 EXPECT_FALSE(check_a_OR_b(false, false));
}

TEST(ASIL_A, check_a_XOR_b){
 EXPECT_TRUE(check_a_XOR_b(true, false));
 EXPECT_TRUE(check_a_XOR_b(false, true));
 EXPECT_FALSE(check_a_XOR_b(true, true));
 EXPECT_FALSE(check_a_XOR_b(false, false));
}

TEST(ASIL_A, check_a_NOR_b){
 EXPECT_FALSE(check_a_NOR_b(true, false));
 EXPECT_FALSE(check_a_NOR_b(false, true));
 EXPECT_FALSE(check_a_NOR_b(true, true));
 EXPECT_TRUE(check_a_NOR_b(false, false));
}

TEST(ASIL_A, check_a_AND_b){
 EXPECT_TRUE(check_a_AND_b(true, true));
 EXPECT_FALSE(check_a_AND_b(true, false));
 EXPECT_FALSE(check_a_AND_b(false, true));
 EXPECT_FALSE(check_a_AND_b(false, false));
}

TEST(ASIL_A, check_a_NAND_b){
 EXPECT_FALSE(check_a_NAND_b(true, true));
 EXPECT_TRUE(check_a_NAND_b(true, false));
 EXPECT_TRUE(check_a_NAND_b(false, true));
 EXPECT_TRUE(check_a_NAND_b(false, false));
}

TEST(ASIL_A, check_a_OR_b_OR_c){
 EXPECT_FALSE(check_a_OR_b_OR_c(false, false, false));
 EXPECT_TRUE(check_a_OR_b_OR_c(true, false, false));
 EXPECT_TRUE(check_a_OR_b_OR_c(false, true, false));
 EXPECT_TRUE(check_a_OR_b_OR_c(false, false, true));
 EXPECT_TRUE(check_a_OR_b_OR_c(true, true, false));
 EXPECT_TRUE(check_a_OR_b_OR_c(true, true, true));
}

TEST(ASIL_A, check_a_OR_b_AND_c){
 EXPECT_FALSE(check_a_OR_b_AND_c(false, false, true));
 EXPECT_TRUE(check_a_OR_b_AND_c(true, false, true));
 EXPECT_TRUE(check_a_OR_b_AND_c(false, true, true));
 EXPECT_FALSE(check_a_OR_b_AND_c(true, true, false));
 EXPECT_TRUE(check_a_OR_b_AND_c(true, true, true));
}

TEST(ASIL_A, check_a_OR__b_AND_c){
 EXPECT_TRUE(check_a_OR__b_AND_c(true, false, false));
 EXPECT_TRUE(check_a_OR__b_AND_c(false, true, true));
 EXPECT_FALSE(check_a_OR__b_AND_c(false, true, false));
 EXPECT_FALSE(check_a_OR__b_AND_c(false, false, false));
 EXPECT_TRUE(check_a_OR__b_AND_c(true, true, true));
}

TEST(ASIL_A, check_a_AND_b_AND_c){
 EXPECT_TRUE(check_a_AND_b_AND_c(true, true, true));
 EXPECT_FALSE(check_a_AND_b_AND_c(false, true, true));
 EXPECT_FALSE(check_a_AND_b_AND_c(true, false, true));
 EXPECT_FALSE(check_a_AND_b_AND_c(true, true, false));
 EXPECT_FALSE(check_a_AND_b_AND_c(false, false, false));
}

TEST(ASIL_A, check_a_AND_b_OR_a_AND_c) {
 EXPECT_EQ(check_a_AND_b_OR_a_AND_c(true, true, false), true);
 EXPECT_EQ(check_a_AND_b_OR_a_AND_c(true, false, true), true);
 EXPECT_EQ(check_a_AND_b_OR_a_AND_c(true, false, false), false);
 EXPECT_EQ(check_a_AND_b_OR_a_AND_c(false, true, true), false);
 EXPECT_EQ(check_a_AND_b_OR_a_AND_c(false, false, false), false);
}

TEST(ASIL_A, check_a_AND_b_XOR_a_AND_c) {
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_c(true, true, false), true);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_c(true, false, true), true);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_c(true, true, true), false);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_c(false, false, false), false);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_c(false, true, true), false);
}

TEST(ASIL_A, check_a_AND_b_XOR_a_AND_NOT_c) {
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c(true, true, false), false);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c(true, false, false), true);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c(true, true, true), true);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c(false, true, true), false);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c(false, false, false), false);
}

TEST(ASIL_A, check_a_AND_b_XOR_a_AND_NOT_c_OR_d) {
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c_OR_d(true, true, false, true), false);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c_OR_d(true, false, false, true), true);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c_OR_d(false, false, true, false), false);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c_OR_d(true, true, true, false), true);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c_OR_d(true, false, true, true), true);
}

/* Above tests re-used for ASIL B coverage due to bool values */

TEST(ASIL_B, return_0){
 EXPECT_EQ(return_0(), 0);
}

TEST(ASIL_B, return_1){
 EXPECT_EQ(return_1(), 1);
}

TEST(ASIL_B, return_a){
 EXPECT_EQ(return_a(true), true);
 EXPECT_EQ(return_a(false), false);
}

TEST(ASIL_B, return_NOT_a){
 EXPECT_EQ(return_NOT_a(true), false);
 EXPECT_EQ(return_NOT_a(false), true);
}

TEST(ASIL_B, check_a_OR_b){
 EXPECT_TRUE(check_a_OR_b(true, false));
 EXPECT_TRUE(check_a_OR_b(false, true));
 EXPECT_TRUE(check_a_OR_b(true, true));
 EXPECT_FALSE(check_a_OR_b(false, false));
}

TEST(ASIL_B, check_a_XOR_b){
 EXPECT_TRUE(check_a_XOR_b(true, false));
 EXPECT_TRUE(check_a_XOR_b(false, true));
 EXPECT_FALSE(check_a_XOR_b(true, true));
 EXPECT_FALSE(check_a_XOR_b(false, false));
}

TEST(ASIL_B, check_a_NOR_b){
 EXPECT_FALSE(check_a_NOR_b(true, false));
 EXPECT_FALSE(check_a_NOR_b(false, true));
 EXPECT_FALSE(check_a_NOR_b(true, true));
 EXPECT_TRUE(check_a_NOR_b(false, false));
}

TEST(ASIL_B, check_a_AND_b){
 EXPECT_TRUE(check_a_AND_b(true, true));
 EXPECT_FALSE(check_a_AND_b(true, false));
 EXPECT_FALSE(check_a_AND_b(false, true));
 EXPECT_FALSE(check_a_AND_b(false, false));
}

TEST(ASIL_B, check_a_NAND_b){
 EXPECT_FALSE(check_a_NAND_b(true, true));
 EXPECT_TRUE(check_a_NAND_b(true, false));
 EXPECT_TRUE(check_a_NAND_b(false, true));
 EXPECT_TRUE(check_a_NAND_b(false, false));
}

TEST(ASIL_B, check_a_OR_b_OR_c){
 EXPECT_FALSE(check_a_OR_b_OR_c(false, false, false));
 EXPECT_TRUE(check_a_OR_b_OR_c(true, false, false));
 EXPECT_TRUE(check_a_OR_b_OR_c(false, true, false));
 EXPECT_TRUE(check_a_OR_b_OR_c(false, false, true));
 EXPECT_TRUE(check_a_OR_b_OR_c(true, true, false));
 EXPECT_TRUE(check_a_OR_b_OR_c(true, true, true));
}

TEST(ASIL_B, check_a_OR_b_AND_c){
 EXPECT_FALSE(check_a_OR_b_AND_c(false, false, true));
 EXPECT_TRUE(check_a_OR_b_AND_c(true, false, true));
 EXPECT_TRUE(check_a_OR_b_AND_c(false, true, true));
 EXPECT_FALSE(check_a_OR_b_AND_c(true, true, false));
 EXPECT_TRUE(check_a_OR_b_AND_c(true, true, true));
}

TEST(ASIL_B, check_a_OR__b_AND_c){
 EXPECT_TRUE(check_a_OR__b_AND_c(true, false, false));
 EXPECT_TRUE(check_a_OR__b_AND_c(false, true, true));
 EXPECT_FALSE(check_a_OR__b_AND_c(false, true, false));
 EXPECT_FALSE(check_a_OR__b_AND_c(false, false, false));
 EXPECT_TRUE(check_a_OR__b_AND_c(true, true, true));
}

TEST(ASIL_B, check_a_AND_b_AND_c){
 EXPECT_TRUE(check_a_AND_b_AND_c(true, true, true));
 EXPECT_FALSE(check_a_AND_b_AND_c(false, true, true));
 EXPECT_FALSE(check_a_AND_b_AND_c(true, false, true));
 EXPECT_FALSE(check_a_AND_b_AND_c(true, true, false));
 EXPECT_FALSE(check_a_AND_b_AND_c(false, false, false));
}

TEST(ASIL_B, check_a_AND_b_OR_a_AND_c) {
 EXPECT_EQ(check_a_AND_b_OR_a_AND_c(true, true, false), true);
 EXPECT_EQ(check_a_AND_b_OR_a_AND_c(true, false, true), true);
 EXPECT_EQ(check_a_AND_b_OR_a_AND_c(true, false, false), false);
 EXPECT_EQ(check_a_AND_b_OR_a_AND_c(false, true, true), false);
 EXPECT_EQ(check_a_AND_b_OR_a_AND_c(false, false, false), false);
}

TEST(ASIL_B, check_a_AND_b_XOR_a_AND_c) {
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_c(true, true, false), true);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_c(true, false, true), true);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_c(true, true, true), false);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_c(false, false, false), false);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_c(false, true, true), false);
}

TEST(ASIL_B, check_a_AND_b_XOR_a_AND_NOT_c) {
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c(true, true, false), false);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c(true, false, false), true);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c(true, true, true), true);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c(false, true, true), false);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c(false, false, false), false);
}

TEST(ASIL_B, check_a_AND_b_XOR_a_AND_NOT_c_OR_d) {
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c_OR_d(true, true, false, true), false);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c_OR_d(true, false, false, true), true);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c_OR_d(false, false, true, false), false);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c_OR_d(true, true, true, false), true);
 EXPECT_EQ(check_a_AND_b_XOR_a_AND_NOT_c_OR_d(true, false, true, true), true);
}