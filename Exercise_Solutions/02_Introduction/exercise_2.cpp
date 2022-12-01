#include <iostream>
#include <cmath>
/* Create a class called "CQuadratic_Equation". 
It should have a class member variable of a type CCoeffs and two member variables of the other class "complex" 
  (that you need to also create; if you already feel comfortable with c++, you can use the std::complex instead) to store solutions. 

Add a class member function that solves the equation. 
Add a separate member function that prints solutions. 

*/

// Definition of the CCoeffs class which defines the coefficients of the quadratic equation ax^2 + bx + c = 0
class CCoeffs{
public:
    double a;
    double b;
    double c;
    // Constructor: By default all coefficients are set to 0.
    CCoeffs(){
        a = 0;
        b = 0;
        c = 0;
    }

    void print();

    void ask_for_input();
};
// Functions of the class CCoeffs.

// This function prints the coefficients a,b,c
void CCoeffs::print(){
    std::cout<<"The coefficients of the quadratic equation are a="<<a<<", b="<<b<< " and c="<<c<<::std::endl;
}

// This function reads the coefficients a,b,c from the user
void CCoeffs::ask_for_input(){
    std::cout<<"Insert the coefficients of the equation ax^2 + bx + c = 0"<<std::endl;
    std::cin>>CCoeffs::a >>CCoeffs::b>>CCoeffs::c;
}

// Definition of CComplex class to store solutions of the form a + bi
class CComplex{
public:
    // Each solution contains a real an an imaginary part
    double real;
    double im;
    // By default both are initialized to 0 when the constructor is used
    CComplex(){
        real = 0;
        im = 0;
    }
};


//Definition of the CQuadratic_Equation class
class CQuadratic_Equation{
public:
    // It contains the coefficients of the equation of class CCoeffs and
    // the solutions of class CComplex
    CCoeffs coeffs;
    CComplex sol1;
    CComplex sol2;


    // By default the constructor asks the user for the coefficients.
    CQuadratic_Equation(){
        coeffs.ask_for_input();
    }
    void solve();
    void print_solution();
};

// This function prints the solution of the equation once solved
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

/*Your main should be similar to:
  - CQuadratic_Equation eq;
  - eq.coeffs.ask_for_input();
  - eq.coeffs.print();
  - eq.solve();
  - eq.print_solution();*/


int main(){
    std::cout<<"This program solves a quadratic equation of the form ax^2 + bx + c = 0"<<std::endl;
    CQuadratic_Equation eq;
    eq.coeffs.print();
    eq.solve();
    eq.print_solution();
    return 0;
} 