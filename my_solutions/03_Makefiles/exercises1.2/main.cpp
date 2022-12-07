#include "CComplex.hpp"
#include "CCoeffs.hpp"
#include "CQuadratic_Equation.hpp"
int main(){
    CQuadratic_Equation eq;
    eq.coefficients.input_coeffs();
    eq.coefficients.print_coeffs();
    eq.solve();
    eq.print_solution();
}