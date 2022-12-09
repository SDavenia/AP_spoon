#pragma once

#include <iostream>

template <typename T>
class CComplex{
public:
    T re, im; // To store real and imaginary part
    CComplex():re(0),im(0){}
    void print() const{
        std::cout<<re<<" + "<<im<<"i "<<std::endl;
    }
};




