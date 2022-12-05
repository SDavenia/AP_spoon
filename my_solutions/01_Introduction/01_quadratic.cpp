/*
Write a program that asks the user to input 3 parameters for a quadratic equation.
Then solve it and modify it to store the coefficients in a class CCoeffs
*/
#include <iostream>
#include <cmath>

class CCoeffs{
public:
    double a, b, c;
};

int main(){
    double D, x1, x2, im;
    CCoeffs coefficients;
    std::cout << "Insert the coefficients of a quadratic equation ax^2 + bx + c = 0"<<std::endl;
    std::cin >> coefficients.a >> coefficients.b >> coefficients.c;
    D = coefficients.b*coefficients.b - 4 * coefficients.a * coefficients.c;
    if (D > 0){
        x1 = (-coefficients.b + std::sqrt(D))/(2*coefficients.a);
        x2 = (-coefficients.b - std::sqrt(D))/(2*coefficients.a);
        std::cout << "The equation has two real distinct solutions " << x1 << " and " <<x2<<std::endl;
        return 0;
    }
    if (D == 0){
        x1 = -coefficients.b/(2*coefficients.a);
        std::cout << "The equation has only one real solution" << x1 <<std::endl;
        return 0;
    }else{
        x1 = -coefficients.b/(2*coefficients.a);
        im = std::sqrt(-D)/(2*coefficients.a);
        std::cout << "The equation has two complex solutions " << x1 << "+" << im << "i and " << x1 << "-" << im << "i" <<std::endl;
    }
    return 0;


}