#include <sstream>
#include <iostream>

int main( int argc, char *argv[] ){
  // Initialize an istringstream object to the first passed argument
  std::istringstream ss(argv[1]);
  int x{0};
  //we try to read a number from the first passed argument
  if (!(ss >> x)) {
    std::cerr << "Invalid number: " << argv[1] << std::endl;
  } else if (!ss.eof()) {
    std::cerr << "There are trailing characters after the number: " << argv[1] << std::endl;
    std::cout<<"number was "<<x<<std::endl;
  }
  std::cout<<x<<std::endl;
  return 0;
}
