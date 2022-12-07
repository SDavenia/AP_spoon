#include "CComplex.hpp"
#include <iostream>

CComplex::CComplex():re(0),im(0){}; //Default CCtor initializes them both to 0

CComplex::CComplex(double real, double imag):re(real),im(imag){};

CComplex CComplex::operator+(const CComplex& c) const{
    CComplex result;
    result.re = re + c.re;
    result.im = re + c.im;
    return result;
}

CComplex CComplex::operator-(const CComplex& c) const{
    CComplex result;
    result.re = re - c.re;
    result.im = re - c.im;
    return result;
}

CComplex CComplex::operator*(const CComplex& c) const{
    CComplex result;
    result.re = re*c.re - im*c.im;
    result.im = re*c.im + im*c.re;
    return result;
}

CComplex CComplex::operator/(const CComplex& c) const{
    CComplex result;
    double denominator;
    denominator = 1/(c.re*c.re + c.im*c.im);
    result.re = (re * c.re + im * c.im)*denominator;
    result.im = (im * c.re - re * c.im)*denominator;
    return result;
}

std::ostream& operator<<(std::ostream& os, const CComplex& c){
    os<<c.re<<" + "<<c.im<<"i"<<std::endl;
    return os;
}