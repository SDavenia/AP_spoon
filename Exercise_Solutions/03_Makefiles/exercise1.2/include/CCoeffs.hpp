#pragma once
class CCoeffs{
public:
    double a;
    double b;
    double c;
    // Constructor: By default all coefficients are set to 0.
    CCoeffs(){
        a = 0;
        b = 0;
        c = 0;
    }

    void print();

    void ask_for_input();
};
