/*
Create a class for complex numbers and make sure that all the arithmetic operations are defined for it. 
  Also, overload the << operator for it.
*/

#include "CComplex.hpp"
int main()
{
    CComplex<int> a;
    CComplex<int> b(3, 2);
    std::cout<<b;
    CComplex<int> c = a + b;
    std::cout<<c;

}