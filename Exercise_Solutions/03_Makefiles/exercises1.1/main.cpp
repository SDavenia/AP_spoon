// We redefine the previous exercise_1 using classes and functions in different separate files
#include "class.hpp"

int main(){
    CCoeffs coeffs;
    coeffs.ask_for_input();
    coeffs.print();
    solve_quadratic_equation(coeffs);
    return 0;
}