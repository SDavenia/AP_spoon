// Create a class for complex numbers and make sure that all arithmetic operators are defined in it
#include <iostream>
#include "CComplex.hpp"


int main(){
    CComplex a(2, 3);
    CComplex b(1, 2);
    CComplex c;
    c = a + b;
    c.print();

    CComplex d;
    d = a / b;
    d.print();

    std::cout<<d<<std::endl;

}