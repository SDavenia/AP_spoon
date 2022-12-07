#include <iostream>
#include "CCoeffs.hpp"

CCoeffs::CCoeffs():a(0), b(0), c(0){}
void CCoeffs::print_coeffs() const{
    std::cout<<"The coefficients are: "<<a<<" "<<b<<" "<<c<<" "<<std::endl;
}

void CCoeffs::input_coeffs(){
        std::cout << "Insert the coefficients of a quadratic equation ax^2 + bx + c = 0"<<std::endl;
        std::cin >> a >> b >> c;
}
