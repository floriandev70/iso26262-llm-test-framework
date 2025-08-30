//
// Created by Florian Carstens on 10.04.24.
//
#include "includes/boolean_algebra.h"
/******************************************************************************
 * Function: int return_0(void)
 * Requirements: This function returns always the value 0.
 ******************************************************************************/
int return_0(void) {
    return 0;
}
/******************************************************************************
 * Function: int return_1(void)
 * Requirements: This function returns always the value 1.
 ******************************************************************************/
int return_1(void) {
    return 1;
}
/******************************************************************************
 * Function: bool return_a(bool a)
 * Requirements: This function returns the value of parameter a.
 ******************************************************************************/
bool return_a(bool a) {
    return a;
}
/******************************************************************************
 * Function: bool return_NOT_a(bool a)
 * Requirements: This function negates the parameter a, it returns NOT(a)
 ******************************************************************************/
bool return_NOT_a(bool a) {
    return !a;
}
/******************************************************************************
 * Function: bool check_a_OR_b(bool,bool)
 * Requirements: This function checks whether a or b is true.
 ******************************************************************************/
bool check_a_OR_b(bool a,bool b) {
    bool check = false;
    if((a == true)||(b == true)) {
        check = true;
    }
    return check;
}
/******************************************************************************
 * Function: bool check_a_XOR_b(bool,bool)
 * Requirements: This functions returns true, if one of the parameters is true
 *               and one is false.
 ******************************************************************************/
bool check_a_XOR_b(bool a,bool b) {
    bool check = false;
    if(((a == true)&&(b == false))||((a == false)&&(b == true))) {
        check = true;
    }
    return check;
}
/******************************************************************************
 * Function: bool check_a_NOR_b(bool,bool)
 * Requirements: This functions checks whether a or b is true and then
 *               returns the negated result.
 ******************************************************************************/
bool check_a_NOR_b(bool a,bool b) {
    bool check = false;
    if((a == true)||(b == true)) {
        check = true;
    }
    return !check;
}
/******************************************************************************
 * Function: bool check_a_AND_b(bool,bool)
 * Requirements: This functions checks whether a and b are both true.
 ******************************************************************************/
bool check_a_AND_b(bool a,bool b) {
    bool check = false;
    if((a == true)&&(b == true)) {
        check = true;
    }
    return check;
}
/******************************************************************************
 * Function: bool check_a_NAND_b(bool,bool)
 * Requirements: This functions checks whether a and b are both true and then
 *               returns the negated result.
 ******************************************************************************/
bool check_a_NAND_b(bool a,bool b) {
    bool check = false;
    if((a == true)&&(b == true)) {
        check = true;
    }
    return !check;
}
/******************************************************************************
 * Function: bool check_a_OR_b_OR_c(bool a,bool b,bool c);
 * Requirements: This functions checks whether a or b or c is true.
 ******************************************************************************/
bool check_a_OR_b_OR_c(bool a,bool b,bool c) {
    bool check = false;
    if((a == true)||(b == true)||(c == true)) {
        check = true;
    }
    return check;
}
/******************************************************************************
 * Function: bool check_a_OR_b_AND_c(bool a,bool b,bool c)
 * Requirements: This functions checks whether a or b is true and c is true.
 ******************************************************************************/
bool check_a_OR_b_AND_c(bool a,bool b,bool c) {
    bool check = false;
    if(((a == true)||(b == true)) && (c == true)) {
        check = true;
    }
    return check;
}
/******************************************************************************
 * Function: bool check_a_OR__b_AND_c(bool a,bool b,bool c)
 * Requirements: This functions checks whether a is true or b and c is true.
 ******************************************************************************/
bool check_a_OR__b_AND_c(bool a,bool b,bool c) {
    bool check = false;
    if((a == true) || ((b == true)&&(c == true))) {
        check = true;
    }
    return check;
}
/******************************************************************************
 * Function: bool check_a_AND_b_AND_c(bool a,bool b,bool c)
 * Requirements: This functions checks whether all parameters are true.
 ******************************************************************************/
bool check_a_AND_b_AND_c(bool a,bool b,bool c) {
    bool check = false;
    if((a == true) && (b == true) && (c == true)) {
        check = true;
    }
    return check;
}
/******************************************************************************
 * Function: bool check_a_AND_b_OR_a_AND_c(bool a,bool b,bool c);
 * Requirements: This functions checks whether a and b are true or a and c are true.
 ******************************************************************************/
bool check_a_AND_b_OR_a_AND_c(bool a,bool b,bool c) {
    bool check = false;
    if(((a == true) && (b == true)) || ((a == true) && (c == true))) {
        check = true;
    }
    return check;
}
/******************************************************************************
 * Function: bool check_a_AND_b_XOR_a_AND_c(bool a,bool b,bool c)
 * Requirements: This function checks whether a and b or a and c are true,
 *               but not both.
 ******************************************************************************/
bool check_a_AND_b_XOR_a_AND_c(bool a,bool b,bool c) {
    bool check = false;
    bool a_AND_b = false;
    bool a_AND_c = false;
    if((a == true) && (b == true)) {
        a_AND_b = true;
    }
    if((a == true) && (c == true)) {
        a_AND_c = true;
    }
    if(((a_AND_b == true)&&(a_AND_c == false)) || ((a_AND_b == false)&&(a_AND_c == true)))
        check = true;
    return check;
}
/******************************************************************************
 * Function: bool check_a_AND_b_XOR_a_AND_NOT_c(bool a,bool b,bool c)
 * Requirements: This function checks three conditions:
 *              1. Condition: Are a and b both true?
 *              2. Condition: Is a true and b not true?
 *              3. Condition: Is either condition 1 or condition 2 true, but
 *              not both at the same time?
 *              This function returns the result of condition 3.
 ******************************************************************************/
bool check_a_AND_b_XOR_a_AND_NOT_c(bool a,bool b,bool c) {
    bool check = false;
    bool a_AND_b = false;
    bool a_AND_NOT_c = false;
    if((a == true) && (b == true)) {
        a_AND_b = true;
    }
    if((a == true) && (c == false)) {
        a_AND_NOT_c = true;
    }
    if(((a_AND_b == true)&&(a_AND_NOT_c == false)) || ((a_AND_b == false)&&(a_AND_NOT_c == true)))
        check = true;
    return check;
}
/******************************************************************************
 * Function: bool check_a_AND_b_XOR_a_AND_NOT_c_OR_d(bool a,bool b,bool c,bool d)
 * Requirements: This function checks these conditions:
 *              1. Condition: Are a and b both true?
 *              2. Condition: Is a true and c not true or d true?
 *              3. Condition: Is either condition 1 or condition 2 true, but
 *              not both at the same time?
 *              This function returns the result of condition 3.
 ******************************************************************************/
bool check_a_AND_b_XOR_a_AND_NOT_c_OR_d(bool a,bool b,bool c, bool d) {
    bool check = false;
    bool a_AND_b = false;
    bool a_AND_NOT_c_OR_d = false;
    if((a == true) && (b == true)) {
        a_AND_b = true;
    }
    if((a == true) && ((c == false) || (d == true))) {
        a_AND_NOT_c_OR_d = true;
    }
    if(((a_AND_b == true)&&(a_AND_NOT_c_OR_d == false)) ||
       ((a_AND_b == false)&&(a_AND_NOT_c_OR_d == true)))
        check = true;
    return check;
}