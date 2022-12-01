#include <iostream>
#include <cmath>
#include "CCoeffs.hpp"


void CCoeffs::print(){
    std::cout<<"The coefficients of the quadratic equation are a="<<a<<", b="<<b<< " and c="<<c<<::std::endl;
}

// This function reads the coefficients a,b,c from the user
void CCoeffs::ask_for_input(){
    std::cout<<"Insert the coefficients of the equation ax^2 + bx + c = 0"<<std::endl;
    std::cin>>CCoeffs::a >>CCoeffs::b>>CCoeffs::c;
}