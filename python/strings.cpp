#magic command file which creates a file for you with the code below

#include <iostream>
extern "C" {
    void print(char* str) {
       std::cout<<str<<std::endl;
    }
}
