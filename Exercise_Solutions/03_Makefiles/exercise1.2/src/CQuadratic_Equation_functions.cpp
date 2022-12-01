#include <iostream>
#include <cmath>
#include "CQuadratic_Equation.hpp"

void CQuadratic_Equation::print_solution(){
    std::cout<<"The solutions of this equation are "<<std::endl;
    std::cout<<CQuadratic_Equation::sol1.real<<"+"<<CQuadratic_Equation::sol1.im<<"i"<<std::endl;
    std::cout<<CQuadratic_Equation::sol2.real<<CQuadratic_Equation::sol2.im<<"i"<<std::endl;

}

// This function solves the equation
void CQuadratic_Equation::solve(){
    if(CQuadratic_Equation::coeffs.a==0){
        std::cout<<"This is not a quadratic equation, a=0, I refuse to solve this. Try again.";
        exit(1);
    }
        
    double discr = CQuadratic_Equation::coeffs.b*CQuadratic_Equation::coeffs.b - 4*CQuadratic_Equation::coeffs.a*CQuadratic_Equation::coeffs.c;
	double root;
	if (discr >= 0){
        //for performance (which doesn't matter now, but can in general)
        //we calculate the complicated math only once
        double inv2a=1/(2*CQuadratic_Equation::coeffs.a);
        double root_of_discr = std::sqrt(discr);
        sol1.real = (-CQuadratic_Equation::coeffs.b + root_of_discr)*inv2a;
        sol2.real = (-CQuadratic_Equation::coeffs.b - root_of_discr)*inv2a;
	} else {
        double inv2a=1/(2*CQuadratic_Equation::coeffs.a);
        double root_of_discr = std::sqrt(-discr);
        sol1.real = -CQuadratic_Equation::coeffs.b*inv2a;
        sol2.real = -CQuadratic_Equation::coeffs.b*inv2a;
        sol1.im = root_of_discr*inv2a;
        sol2.im = -root_of_discr*inv2a;
    }    
}
