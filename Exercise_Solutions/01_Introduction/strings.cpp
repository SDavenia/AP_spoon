#include <iostream>

int main(){
  int x, y;
  std::string s;
  x = 3;
  y = 4;
  s = std::to_string(x) + " + " + std::to_string(y) + "i";
  std::cout<<"We print this string "<<s<<std::endl;
}
