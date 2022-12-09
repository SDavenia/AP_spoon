#pragma once
#include <iostream>

template <typename T>
class CComplex{
    T re, im;
public:
    CComplex(); // default constructor
    CComplex(T real, T imag); //constructor
    CComplex operator+(const CComplex& c) const;
    CComplex operator-(const CComplex& c) const;
    CComplex operator*(const CComplex& c) const;
    CComplex operator/(const CComplex& c) const;
    // We need to define another template WHY??
    template <typename O>
    friend std::ostream& operator<<(std::ostream& os, const CComplex<O>& c);
};

template <typename T>
CComplex<T>::CComplex():re(0),im(0){}; //Default CCtor initializes them both to 0

template <typename T>
CComplex<T>::CComplex(T real, T imag):re(real),im(imag){};

template <typename T>
CComplex<T> CComplex<T>::operator+(const CComplex<T>& c) const{
    CComplex result;
    result.re = re + c.re;
    result.im = re + c.im;
    return result;
}

template <typename T>
CComplex<T> CComplex<T>::operator-(const CComplex<T>& c) const{
    CComplex result;
    result.re = re - c.re;
    result.im = re - c.im;
    return result;
}

template <typename T>
CComplex<T> CComplex<T>::operator*(const CComplex<T>& c) const{
    CComplex result;
    result.re = re*c.re - im*c.im;
    result.im = re*c.im + im*c.re;
    return result;
}

template <typename T>
CComplex<T> CComplex<T>::operator/(const CComplex<T>& c) const{
    CComplex result;
    double denominator;
    denominator = 1/(c.re*c.re + c.im*c.im);
    result.re = (re * c.re + im * c.im)*denominator;
    result.im = (im * c.re - re * c.im)*denominator;
    return result;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const CComplex<T>& c){
    os<<c.re<<" + "<<c.im<<"i"<<std::endl;
    return os;
}