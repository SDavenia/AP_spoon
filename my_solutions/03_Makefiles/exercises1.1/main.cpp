/*
The aim is to re-write the code from exercise 1 lecture 2 using makefiles
*/

#include "CCoeffs.hpp"

int main(){
    CCoeffs coefficients;
    coefficients.input_coeffs();
    coefficients.print_coeffs();
    solve_quadratic_equation(coefficients);
}
