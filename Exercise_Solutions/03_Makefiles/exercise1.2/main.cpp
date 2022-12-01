#include <iostream>
#include "CQuadratic_Equation.hpp"
#include "CCoeffs.hpp"
#include "CComplex.hpp"
int main(){
    std::cout<<"This program solves a quadratic equation of the form ax^2 + bx + c = 0"<<std::endl;
    CQuadratic_Equation eq;
    eq.coeffs.print();
    eq.solve();
    eq.print_solution();
    return 0;
} 