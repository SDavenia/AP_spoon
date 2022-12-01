#pragma once
#include "CComplex.hpp"
#include "CCoeffs.hpp"

class CQuadratic_Equation{
public:
    // It contains the coefficients of the equation of class CCoeffs and
    // the solutions of class CComplex
    CCoeffs coeffs;
    CComplex sol1;
    CComplex sol2;


    // By default the constructor asks the user for the coefficients.
    CQuadratic_Equation(){
        coeffs.ask_for_input();
    }
    void solve();
    void print_solution();
};
