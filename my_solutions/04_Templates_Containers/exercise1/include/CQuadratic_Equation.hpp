#pragma once
#include "CComplex.hpp" // You need these two here cause otherwise the CQuadratic equation has no access to the object CComplex and CCoeffs
#include "CCoeffs.hpp"
#include <iostream>
#include <cmath>
template <typename T>
class CQuadratic_Equation{
    // In main we do not have to call any function from CComplex, so we can leave them private
    CComplex<T> solution1;
    CComplex<T> solution2;
public:
    // We have to make coefficients public though if we want to use them in the main.
    CCoeffs<T> coefficients;
    void solve(){
        std::cout << "Calling solve" <<std::endl;
        coefficients.print_coeffs();
        double D, im, div;
        D = coefficients.b*coefficients.b - 4 * coefficients.a * coefficients.c;
        div = 1/(2*coefficients.a);
        //std::cout<<div<<std::endl;
        //std::cout<<D<<std::endl;
        if (D > 0){
            solution1.re = (-coefficients.b + std::sqrt(D))*div;
            solution2.re = (-coefficients.b - std::sqrt(D))*div;
        }else if(D == 0){
            solution1.re = (-coefficients.b)*div;
            solution2.re = (-coefficients.b)*div;
        }else{
            /*
            std::cout<<"Negative denominator"<<std::endl;
            std::cout<<coefficients.a<<std::endl;
            std::cout<<coefficients.b<<std::endl;
            std::cout<<coefficients.c<<std::endl;
            */
            solution1.re = (-coefficients.b)*div;
            solution2.re = (-coefficients.b)*div;
            std::cout<<"solution 1:"<<solution1.re<<solution1.im<<std::endl;
            im = std::sqrt(-D)*div;
            solution1.im = im;
            solution2.im = -im;
        }
    }
    void print_solution(){
        solution1.print();
        solution2.print();
    }

};



