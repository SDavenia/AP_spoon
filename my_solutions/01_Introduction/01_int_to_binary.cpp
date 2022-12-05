/*
This program converts integers to binary: I only consider positive integers 
    cause negative ones have a different representation
*/
#include <iostream>
#include <string>
int main()
{
    unsigned int a;
    std::string binary{""};
    // Ask the user for input
    std::cout << "What number do you want to convert to binary"<<std::endl;
    std::cin>>a;
    while(a != 0){
        if (a % 2 == 1)
           binary = "1" + binary;
        else
           binary = "0" + binary;
        a = a/2;
    }
    std::cout << binary <<std::endl;
}