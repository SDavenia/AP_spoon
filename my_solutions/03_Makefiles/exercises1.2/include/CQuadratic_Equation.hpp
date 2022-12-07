#pragma once
#include "CComplex.hpp" // You need these two here cause otherwise the CQuadratic equation has no access to the object CComplex and CCoeffs
#include "CCoeffs.hpp"
class CQuadratic_Equation{
    // In main we do not have to call any function from CComplex, so we can leave them private
    CComplex solution1;
    CComplex solution2;
public:
    // We have to make coefficients public though if we want to use the main as below.
    CCoeffs coefficients;
    void solve();
    void print_solution();

};
