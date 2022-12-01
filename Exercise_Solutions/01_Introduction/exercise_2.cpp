#include <iostream>
#include <cmath>
#include <string>

/* Write a program that converts integers to string */
int main(){
  // Ask the user for the number to convert to binary.
  int n;
  std::string s, rem;
  s = "";
  std::cout<<"Insert the integer to convert to binary"<<std::endl;
  std::cin>>n;

  while (n != 0){
    rem = std::to_string(n%2);
    n = n / 2;
    s = rem + s;
  }

  std::cout<<"The binary equivalent is: "<<s<<std::endl;
}
