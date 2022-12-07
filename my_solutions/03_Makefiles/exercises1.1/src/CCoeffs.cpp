#include "CCoeffs.hpp"
#include <iostream>
#include <cmath>

void CCoeffs::print_coeffs() const{
    std::cout<<"The coefficients are: "<<a<<" "<<b<<" "<<c<<" "<<std::endl;
}

void CCoeffs::input_coeffs(){
     std::cout << "Insert the coefficients of a quadratic equation ax^2 + bx + c = 0"<<std::endl;
        std::cin >> a >> b >> c;
}

CCoeffs::CCoeffs(): a(0), b(0), c(0){};

void solve_quadratic_equation(const CCoeffs& coefficients){ 
    // coefficients.a = 2; this returns a compilation error since we specified const
    double D, x1, x2, im, div;
    D = coefficients.b*coefficients.b - 4 * coefficients.a * coefficients.c;
    // To make it faster we can compute this here
    div = 1/(2*coefficients.a);
    if (D > 0){
        x1 = (-coefficients.b + std::sqrt(D))*div;
        x2 = (-coefficients.b - std::sqrt(D))*div;
        std::cout << "The equation has two real distinct solutions " << x1 << " and " <<x2<<std::endl;
    }else if(D == 0){
        x1 = -coefficients.b*div;
        std::cout << "The equation has only one real solution" << x1 <<std::endl;
    }else{
        x1 = -coefficients.b*div;
        im = std::sqrt(-D)*div;
        std::cout << "The equation has two complex solutions " << x1 << "+" << im << "i and " << x1 << "-" << im << "i" <<std::endl;
    }


}