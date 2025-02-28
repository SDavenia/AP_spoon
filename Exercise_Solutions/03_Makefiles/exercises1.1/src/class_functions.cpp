#include <iostream>
#include <cmath>
#include "class.hpp"

void CCoeffs::print(){
    std::cout<<"The coefficients of the quadratic equation are a="<<a<<", b="<<b<< " and c="<<c<<::std::endl;
}

void CCoeffs::ask_for_input(){
    std::cout<<"Insert the coefficients of the equation ax^2 + bx + c = 0"<<std::endl;
    std::cin>>CCoeffs::a >>CCoeffs::b>>CCoeffs::c;
}

void solve_quadratic_equation(CCoeffs coeffs){
    if(coeffs.a==0){
        std::cout<<"This is not a quadratic equation, a=0, I refuse to solve this. Try again.";
        exit(1);
    }
        
    double discr = coeffs.b*coeffs.b - 4*coeffs.a*coeffs.c;
	double root;
	if (discr >= 0){
        //for performance (which doesn't matter now, but can in general)
        //we calculate the complicated math only once
        double inv2a=1/(2*coeffs.a);
        double root_of_discr = std::sqrt(discr);
        double root1 = (-coeffs.b + root_of_discr)*inv2a;
        double root2 = (-coeffs.b - root_of_discr)*inv2a;
        
        std::cout<< "The roots are: "<< root1 << " "<<root2<<std::endl;
	} else {
        double inv2a=1/(2*coeffs.a);
        double root_of_discr = std::sqrt(-discr);
        std::cout<< "The roots are: "<< -coeffs.b*inv2a << "+i "<<root_of_discr*inv2a<<" and ";
        std::cout<< -coeffs.b*inv2a << "-i "<<root_of_discr*inv2a<<std::endl;
    }    

}