#include <iostream>
#include <cmath>
#include <string>
/* Write a program that asks the user to input 3 parameters for a quadratic equation
   ax^2+bx+c=0, then solve it (complex roots included).
   Store the coefficients in a class CCoeffs. */
struct CCoeffs{
    std::string x;
    std::string y;
};

int main(){
  CCoeffs solutions;
  double a, b, c, determinant, x1, x2, im;
  std::string s1, s2;

  // Read the three coefficients from the user.
  std::cout<<"Insert the coefficients a b c of a polynomial"<<std::endl;
  std::cin >> a >> b >> c;

  // Compute the determinant
  determinant = b*b - 4 * a * c;
  // Determinant = 0
  if (determinant == 0){
    x1 = (-b)/(2 * a);
    solutions.x = std::to_string(x1);
    solutions.y = std::to_string(x1);

  } else if (determinant < 0){
    determinant = - determinant;

    x1 = -b/(2*a);
    im = sqrt(determinant)/(2 * a);

    s1 = std::to_string(x1) + " + " + std::to_string(im) + "i";
    s2 = std::to_string(x1) + " - " + std::to_string(im) + "i";

    solutions.x = s1;
    solutions.y = s2;


  }
  else {
    x1 = (-b + sqrt(determinant))/(2 * a);
    x2 = (-b - sqrt(determinant))/(2 * a);
    solutions.x = std::to_string(x1);
    solutions.y = std::to_string(x2);
  }

  std::cout<<"The solutions of the equation are "<<solutions.x<<" and "<<solutions.y<<"."<<std::endl;
}
