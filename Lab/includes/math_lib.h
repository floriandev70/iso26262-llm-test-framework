//
// Created by Florian Carstens on 12.04.24.
//

#ifndef MATH_LIB_H
#define MATH_LIB_H
#include <cstdint>

//add
int add(int,int);
int add_ref(int,int);
//subtract
int subtract(int,int);
int subtract_ref(int,int);
//multiply
int multiply(int,int);
int multiply_ref(int,int);
//divide
int divide(int,int);
int divide_ref(int,int);
//fac
int factorial(int);
//fib
int fibonacci(int);
int fibonacci_ref(int);
//prim
int prime_number(int);
int prime_number_ref(int);
//myFunc
float myFunc(void);
//dimi
#define SP_Get_I_Kl30() 5000
#define SP_Get_U_Kl30() 480000
#define UTIL_ABS(X)(((X) >= (0)) ? (X) : (-X))
#define MILLI 1000.0f

struct dcdc_ntc_temp_def {
    float temp_ntc1 = 10.0;
    float temp_ntc2 = 20.0;
    float temp_ntc3 = 30.0;
    float temp_ntc4 = 40.0;
    float temp_ntc5 = 50.0;
    float temp_ntc6 = 60.0;
};
int16_t Temp_Calc_Pres_Wacol_Temp_48V (struct dcdc_ntc_temp_def const *);
#endif //MATH_LIB_H
