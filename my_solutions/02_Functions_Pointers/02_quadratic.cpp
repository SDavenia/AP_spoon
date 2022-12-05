/*
Add a contructor to your class of coefficients to initialize them all to zero. 
Add a class member function that prints the coefficients. 
Add a class member function that asks the user to input the coefficients. 
Write a function that takes a variable of your coefficient class as input and solves the equation (this function should also print solutions). 
*/
#include <iostream>
#include <cmath>

class CCoeffs{
public:
    double a, b, c;
    CCoeffs():a(0), b(0), c(0){} // Default constructor
    void print_coeffs(){
        std::cout<<"The coefficients are: "<<a<<" "<<b<<" "<<c<<" "<<std::endl;
    }
    void input_coeffs(){
        std::cout << "Insert the coefficients of a quadratic equation ax^2 + bx + c = 0"<<std::endl;
        std::cin >> a >> b >> c;
    }
};

// This function takes as input an object of class coefficients and prints out the solution
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

int main(){
    CCoeffs coefficients;
    coefficients.input_coeffs();
    coefficients.print_coeffs();
    solve_quadratic_equation(coefficients);
    


}