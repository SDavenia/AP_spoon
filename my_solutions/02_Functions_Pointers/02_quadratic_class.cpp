/*
Create a class called "CQuadratic_Equation". 
It should have a class member variable of a type CCoeffs and two member variables of the other class "complex" 
  (that you need to also create; if you already feel comfortable with c++, you can use the std::complex instead) to store solutions. 
Add a class member function that solves the equation. 
Add a separate member function that prints solutions. 
*/
#include <iostream>
#include <cmath>

class CCoeffs{
public:
    double a, b, c;
    CCoeffs():a(0), b(0), c(0){} // Default constructor
    void print_coeffs() const{ // This function can also be called on const objects (No sense to do here though)
        std::cout<<"The coefficients are: "<<a<<" "<<b<<" "<<c<<" "<<std::endl;
    }
    void input_coeffs(){
        std::cout << "Insert the coefficients of a quadratic equation ax^2 + bx + c = 0"<<std::endl;
        std::cin >> a >> b >> c;
    }
};

// Class to store complex numbers
class CComplex{
public:
    double re, im; // To store real and imaginary part
    CComplex():re(0), im(0){}
    void print() const{
        std::cout<<re<<" + "<<im<<"i "<<std::endl;
    }
};

// Class to store quadratic equations
class CQuadratic_Equation{
    // In main we do not have to call any function from CComplex, so we can leave them private
    CComplex solution1;
    CComplex solution2;
public:
    // We have to make coefficients public though if we want to use the main as below.
    CCoeffs coefficients;
    void solve();
    void print_solution();

};

void CQuadratic_Equation::solve(){
    double D, im, div;
    D = coefficients.b*coefficients.b - 4 * coefficients.a * coefficients.c;
    div = 1/(2*coefficients.a);
    if (D > 0){
        solution1.re = (-coefficients.b + std::sqrt(D))*div;
        solution2.re = (-coefficients.b - std::sqrt(D))*div;
    }else if(D == 0){
        solution1.re = (-coefficients.b)*div;
        solution2.re = (-coefficients.b)*div;
    }else{
        solution1.re = (-coefficients.b)*div;
        solution2.re = (-coefficients.b)*div;
        im = std::sqrt(-D)*div;
        solution1.im = im;
        solution2.im = -im;
    }

}

void CQuadratic_Equation::print_solution(){
    solution1.print();
    solution2.print();
}
/*
Your main should be similar to

CQuadratic_Equation eq;
eq.coeffs.ask_for_input();
eq.coeffs.print();
eq.solve();
eq.print_solution();

*/

int main(){
    CQuadratic_Equation eq;
    eq.coefficients.input_coeffs();
    eq.coefficients.print_coeffs();
    eq.solve();
    eq.print_solution();
}