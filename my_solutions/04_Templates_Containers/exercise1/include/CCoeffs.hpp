#pragma once
#include <iostream>

template <typename T>
class CCoeffs{
public:
    T a, b, c;
    CCoeffs():a(0), b(0), c(0){}
    void print_coeffs() const{
        std::cout<<"The coefficients are: "<<a<<" "<<b<<" "<<c<<" "<<std::endl;
    }
    void input_coeffs(){
        std::cout << "Insert the coefficients of a quadratic equation ax^2 + bx + c = 0"<<std::endl;
        std::cin >> a >> b >> c;
    }
};

