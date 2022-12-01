#include <iostream>
#include <cmath>
class CCoeffs{
public:
    double a;
    double b;
    double c;
    CCoeffs(){
        a = 0;
        b = 0;
        c = 0;
    }

    void print();

    void ask_for_input();


};


void solve_quadratic_equation(CCoeffs coeffs);