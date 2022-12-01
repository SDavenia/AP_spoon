#pragma once
class CComplex{
public:
    // Each solution contains a real an an imaginary part
    double real;
    double im;
    // By default both are initialized to 0 when the constructor is used
    CComplex(){
        real = 0;
        im = 0;
    }
};

// main.o CQuadratic_Equation_functions.o CCoeffs_functions.o