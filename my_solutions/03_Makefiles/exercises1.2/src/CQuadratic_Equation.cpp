#include "CQuadratic_Equation.hpp"
#include "CComplex.hpp"
#include "CCoeffs.hpp"
#include <iostream>
#include <cmath>
void CQuadratic_Equation::solve(){
    double D, im, div;
    D = coefficients.b*coefficients.b - 4 * coefficients.a * coefficients.c;
    div = 1/(2*coefficients.a);
    if (D > 0){
        solution1.re = (-coefficients.b + std::sqrt(D))*div;
        solution2.re = (-coefficients.b - std::sqrt(D))*div;
    }else if(D == 0){
        solution1.re = (-coefficients.b)*div;
        solution2.re = (-coefficients.b)*div;
    }else{
        solution1.re = (-coefficients.b)*div;
        solution2.re = (-coefficients.b)*div;
        im = std::sqrt(-D)*div;
        solution1.im = im;
        solution2.im = -im;
    }

}

void CQuadratic_Equation::print_solution(){
    solution1.print();
    solution2.print();
}