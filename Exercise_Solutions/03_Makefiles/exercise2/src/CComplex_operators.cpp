#include <iostream>
#include <cmath>
#include "CComplex.hpp"

void CComplex::print(){
    std::cout<<real<<" + "<<im<<"i."<<std::endl;
}

std::ostream& operator<<(std::ostream&os, const CComplex& c){
    os<<"real part is "<<c.real<<", imaginary part is "<<c.im<<std::endl;
    return os;
}