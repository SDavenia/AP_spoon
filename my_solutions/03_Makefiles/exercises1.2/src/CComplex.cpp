#include "CComplex.hpp"
#include <iostream>


CComplex::CComplex():re(0),im(0){}
void CComplex::print() const{
    std::cout<<re<<" + "<<im<<"i "<<std::endl;
}

