#include <iostream>
#include <cmath>
/* Write a program that asks the user to input 3 parameters for a quadratic equation
   ax^2+bx+c=0, then solve it (complex roots included). */

int main(){
  double a, b, c, determinant, x1, x2, im;

  // Read the three coefficients from the user.
  std::cout<<"Insert the coefficients a b c of a polynomial"<<std::endl;
  std::cin >> a >> b >> c;

  // Compute the determinant
  determinant = b*b - 4 * a * c;
  // Determinant = 0
  if (determinant == 0){
    x1 = (-b)/(2 * a);
    std::cout<<"The equation has a unique real solution "<<x1<<std::endl;
  } else if (determinant < 0){
    determinant = - determinant;

    x1 = -b/(2*a);
    im = sqrt(determinant)/(2 * a);

    std::cout<<"The equation has two complex solutions: "<<x1<<" + "<<im<<"i and "<<x1<<" - "
    <<im<<"i.\n"<<std::endl;

  }
  else {
    x1 = (-b + sqrt(determinant))/(2 * a);
    x2 = (-b - sqrt(determinant))/(2 * a);
    std::cout<<"The equation has solutions "<<x1<<"and"<<x2<<"."<<std::endl;
  }

}
