#include "includes/math_lib.h"

#include <cstdint>

/***********************************************************************************************************************
 * Function: int add(int a, int b)
 * Requirements: This function returns the sum of two integers within the input range [0..1000].
 * Outputs within the range [-1(error), 0..1500]. Rejects computation and returns -1 if the
 * result would go out of bounds.
 **********************************************************************************************************************/
int add(int a, int b) {
    if (a < 0 || a > 1000 || b < 0 || b > 1000) {
        return -1;
    }
    if (a > 1500 - b) {
        return -1;
    }
    return a + b;
}
/***********************************************************************************************************************
 * Function: int subtract(int a, int b)
 * Requirements: This function returns the difference of two integers within the input range [0..1000].
 * Outputs within the range [-1(error), 0..1500]. Rejects computation and returns -1 if the
 * result would go out of bounds.
 **********************************************************************************************************************/
int subtract(int a, int b){
    if ((a < 0) || (b < 0) || (a > 1000) || (b > 1000)) {
        return -1;
    }
    if (a < b){
        return -1;
    }
    return a - b;
}
/***********************************************************************************************************************
 * Function: int multiply(int a, int b)
 * Requirements: This function returns the product of two integers within the input range [0..1000].
 * Outputs within the range [-1(error), 0..1500]. Rejects computation and returns -1 if the
 * result would go out of bounds.
 **********************************************************************************************************************/
int multiply(int a, int b) {
    if (a < 0 || a > 1000 || b < 0 || b > 1000) return -1;
    if (b > 0 && a > 1500 / b) return -1; // Prevent overflow
    return a * b;
}
/***********************************************************************************************************************
 * Function: int divide(int a, int b)
 * Requirements: This function returns the integer quotient of two integers within the input range [0..1000].
 * Outputs within the range [-1(error), 0..1500]. Rejects computation and returns -1 if the
 * result would go out of bounds or b is zero.
 **********************************************************************************************************************/
int divide(int a, int b) {
    if (a < 0 || a > 1000 || b <= 0 || b > 1000) return -1;
    return a / b;
}
/***********************************************************************************************************************
 * Function: int factorial(int n)
 * Requirements: This function returns the factorial of a non-negative integer within the input range [0..1000].
 * Outputs within the range [-1(error), 0..1500]. Rejects computation and returns -1 if the
 * result would go out of bounds.
 **********************************************************************************************************************/
int factorial(int n) {
    if (n < 0 || n > 1000) {
        return -1;
    }
    int fact = 1;
    for (int i = 2; i <= n; ++i) {
        if (fact > 1500 / i) {
            return -1;
        }
        fact *= i;
    }
    return fact;
}
/***********************************************************************************************************************
 * Function: int fibonacci(int n)
 * Requirements: This function returns the nth Fibonacci number within the input range [0..1000].
 * Outputs within the range [-1(error), 0..1500]. Rejects computation and returns -1 if the
 * result would go out of bounds.
 **********************************************************************************************************************/
int fibonacci(int n) {
    if (n < 0 || n > 1000) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int prev = 0, next = 1, result = 1;
    for (int i = 2; i <= n; ++i) {
        result = prev + next;
        if (result > 1500 || result < 0) {
            return -1;
        }
        prev = next;
        next = result;
    }
    return result;
}
/***********************************************************************************************************************
 * Function: int prime_number(int n)
 * Requirements: This function checks if n is a prime number within the input range [0..1000].
 * Outputs number 1 if prime, 0 if not prime, and -1 for error due to invalid input.
 **********************************************************************************************************************/
int prime_number(int n) {
    if ((n < 0) || (n > 1000)) {
        return -1;
    }
    if (n <= 1) {
        return 0;
    }
    if ((n != 2) && (n % 2 == 0)) {
        return 0;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}


/* Refactored versions for branch coverage and lazy check avoidance! */

/***********************************************************************************************************************
 * Function: int add_ref(int a, int b)
 * Note: Refactured version of function add().
 * Requirements: This function returns the sum of two integers within the input range [0..1000].
 * Outputs within the range [-1(error), 0..1500]. Rejects computation and returns -1 if the
 * result would go out of bounds.
 **********************************************************************************************************************/
int add_ref(int a, int b) {
    if (a < 0) {
        return -1;
    }
    if (b < 0){
        return -1;
    }
    if (a > 1000){
        return -1;
    }
    if (b > 1000){
        return -1;
    }
    if (a + b > 1500) {
        return -1;
    }
    return a + b;
}
/***********************************************************************************************************************
 * Function: int subtract_ref(int a, int b)
 * Note: Refactured version of function subtract().
 * Requirements: This function returns the difference of two integers within the input range [0..1000].
 * Outputs within the range [-1(error), 0..1500]. Rejects computation and returns -1 if the
 * result would go out of bounds.
 **********************************************************************************************************************/
int subtract_ref(int a, int b){
    if (a < 0) {
        return -1;
    }
    if (b < 0){
        return -1;
    }
    if (a > 1000){
        return -1;
    }
    if (b > 1000){
        return -1;
    }
    if (a < b){
        return -1;
    }
    return a - b;
}
/***********************************************************************************************************************
 * Function: int multiply_ref(int a, int b)
 * Note: Refactured version of function multiply().
 * Requirements: This function returns the product of two integers within the input range [0..1000].
 * Outputs within the range [-1(error), 0..1500]. Rejects computation and returns -1 if the
 * result would go out of bounds.
 **********************************************************************************************************************/
int multiply_ref(int a, int b) {
    if (a < 0) {
        return -1;
    }
    if (b < 0){
        return -1;
    }
    if (a > 1000){
        return -1;
    }
    if (b > 1000){
        return -1;
    }
    if (b > 0) {
        if (a > 1500 / b) {
            return -1;
        }
    }
    return a * b;
}
/***********************************************************************************************************************
 * Function: int divide_ref(int a, int b)
 * Note: Refactured version of function divide().
 * Requirements: This function returns the integer quotient of two integers within the input range [0..1000].
 * Outputs within the range [-1(error), 0..1500]. Rejects computation and returns -1 if the
 * result would go out of bounds or b is zero.
 **********************************************************************************************************************/
int divide_ref(int a, int b) {
    if (a < 0) {
        return -1;
    }
    if (b < 0){
        return -1;
    }
    if (a > 1000){
        return -1;
    }
    if (b > 1000){
        return -1;
    }
    if(b == 0){
        return -1;
    }
    return a / b;
}
/***********************************************************************************************************************
 * Function: int prime_number_ref(int n)
 * Note: Refactured version of function prime_number()
 * Requirements: This function checks if n is a prime number within the input range [0..1000].
 * Outputs number 1 if prime, 0 if not prime, and -1 for error due to invalid input.
 **********************************************************************************************************************/
int prime_number_ref(int n) {
    if (n < 0) {
        return -1;
    }
    if (n > 1000) {
        return -1;
    }
    if (n <= 1) {
        return 0;
    }
    if (n != 2) {
        if(n % 2 == 0) {
            return 0;
        }
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
/***********************************************************************************************************************
 * Function: int fibonacci_ref(int n)
 * Note: Refactured version of function fibonacci()
 * Requirements: This function returns the nth Fibonacci number within the input range [0..1000].
 * Outputs within the range [-1(error), 0..1500]. Rejects computation and returns -1 if the
 * result would go out of bounds.
 **********************************************************************************************************************/
int fibonacci_ref(int n) {
    if (n < 0 || n > 1000) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int prev = 0, next = 1, result = 1;
    for (int i = 2; i <= n; ++i) {
        result = prev + next;
        if (result > 1500) {
            return -1;
        }
        prev = next;
        next = result;
    }
    return result;
}
////
float myFunc(void) {
    int x; float f;
    x = 3;
    f = x;
    return f;
}
/****************************************************************************/
//! Berechnung des Signals PRES_WACOL_TEMP_48V abhänging von den NTCs Flowrate I and U of KL30
//Tinlet = Flow[L/min]* 0.2671
//+ I_KL30[A]* 0.0037
//+ I_KL30[A]* -0,0031*V_KL30[V]*0,05
//+ NTC1_CAN[degC]* 1.053
//+ NTC2_CAN[degC]* -0.4578
//+NTC3_CAN[degC]* -0.6286
//+ NTC4_CAN[degC]* 0.2951
//+ NTC5_CAN[degC]* 1.8444
//+NTC6_CAN[degC]* -2.0185
//+ NTC7_CAN[degC]* 0.9187
//+ (-2.573)
/*!
*   \param ntc_temp      Pointer auf Struktur mit allen NTC-, Min- und Max-Temperaturen
*/
/****************************************************************************/

int16_t Temp_Calc_Pres_Wacol_Temp_48V(struct dcdc_ntc_temp_def const *ntc_temp)
{
    float tmp_result = 0.0;
    float I_KL30_10mA = (float)SP_Get_I_Kl30();
    float U_KL30_1mV = (float)SP_Get_U_Kl30();
    float abs_I_KL30_10mA = (float)UTIL_ABS(I_KL30_10mA);
    float abs_U_KL30 = (float)UTIL_ABS(U_KL30_1mV);
    // here comes the magic
    //+ I_KL30[A] * 0.0037
    tmp_result = I_KL30_10mA / MILLI*10.0f * 0.0037f
    //+ ABS(I_KL30[A]) * -0,0031 * ABS(V_KL30[V]) * 0,05
    + abs_I_KL30_10mA / MILLI*10.0f * -0.0031f * abs_U_KL30 / MILLI * 0.05f;
    //and now we add the temps!
    //+ NTC1_CAN[degC] * 1.053
    tmp_result += ntc_temp->temp_ntc1 * 1.053f
    //+ NTC2_CAN[degC] * -0.4578
    + ntc_temp->temp_ntc2 * -0.4578f
    //+NTC3_CAN[degC] * -0.6286
    + ntc_temp->temp_ntc3 * -0.6286f
    //+ NTC4_CAN[degC] * 0.2951
    + ntc_temp->temp_ntc4 * 0.2951f
    //+ NTC5_CAN[degC] * 1.8444
    + ntc_temp->temp_ntc4 * 1.8444f
    //+NTC6_CAN[degC] * -2.0185
    + ntc_temp->temp_ntc4 * -2.0185f
    //+ NTC7_CAN[degC] * 0.9187
    + ntc_temp->temp_ntc4 * 0.9187f;
    //lastly the correction value
    //+ (-2.573)
    tmp_result += -2.573f;
    // and return to sender in 0,1C...
    return ((int16_t)(tmp_result*10.0f));
}
/****************************************************************************/