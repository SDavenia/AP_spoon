#pragma once
#include <iostream>
class CComplex{
    double re, im;
public:
    CComplex(); // default constructor
    CComplex(double real, double imag); //constructor
    CComplex operator+(const CComplex& c) const;
    CComplex operator-(const CComplex& c) const;
    CComplex operator*(const CComplex& c) const;
    CComplex operator/(const CComplex& c) const;

    friend std::ostream& operator<<(std::ostream& os, const CComplex& c);
};
