/*
Rewrite your "solve quadratic equation" exercise templating everything on the type of the coefficients. 
Your templated class should live in .hpp file.

This exercise does not make much sense as even with integer coefficients the equation can have non-integer solutions
*/

#include "CComplex.hpp"
#include "CCoeffs.hpp"
#include "CQuadratic_Equation.hpp"
int main(){
    CQuadratic_Equation<int> eq;
    eq.coefficients.input_coeffs();
    eq.coefficients.print_coeffs();
    eq.solve();
    eq.print_solution();
}