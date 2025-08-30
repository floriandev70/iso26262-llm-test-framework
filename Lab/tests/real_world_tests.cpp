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
#include "../includes/real_world.h"

/*ALL TESTS GENERATED in the PhD Research LAB by the ISO 26262 ASIL D Test Assistant (GPT4 Turbo) on 16.04.2024.*/

TEST(ASIL_D, check_abort) {
 EXPECT_EQ(check_abort(false, false, false), false);
 EXPECT_EQ(check_abort(true, false, false), true);
 EXPECT_EQ(check_abort(false, true, false), false);
 EXPECT_EQ(check_abort(false, false, true), false);
 EXPECT_EQ(check_abort(true, true, false), true);
 EXPECT_EQ(check_abort(true, false, true), true);
 EXPECT_EQ(check_abort(false, true, true), true);
 EXPECT_EQ(check_abort(true, true, true), true);
}

TEST(ASIL_A_2, autom_MCU_state_machine_OFF) {
 g_current_state = OFF;
 EXPECT_EQ(autom_MCU_state_machine(CURRENT_STATE), OFF);
 EXPECT_EQ(autom_MCU_state_machine(RUN), RUN);
 EXPECT_EQ(autom_MCU_state_machine(SLEEP), SLEEP);
}
TEST(ASIL_A_2, autom_MCU_state_machine_RUN) {
 g_current_state = RUN;
 EXPECT_EQ(autom_MCU_state_machine(SLEEP), SLEEP);
 EXPECT_EQ(autom_MCU_state_machine(OFF), OFF);
}
TEST(ASIL_A_2, autom_MCU_state_machine_SLEEP) {
 g_current_state = SLEEP;
 EXPECT_EQ(autom_MCU_state_machine(RUN), RUN);
 EXPECT_EQ(autom_MCU_state_machine(OFF), -1); // Invalid direct transition from SLEEP to OFF
}
TEST(ASIL_A_2, autom_MCU_state_machine_RUN2) {
 g_current_state = RUN;
 EXPECT_EQ(autom_MCU_state_machine(RUN), -1); // No effect when requesting same state as current
}
