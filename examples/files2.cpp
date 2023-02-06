#include <iostream>
#include <fstream>

int main(){
    //you can do the same things as with std::cout and std::cin

    //this will create "test.txt" if it doesn't exist or overwrite if it does
    std::ofstream filevar;
    filevar.open("test2.txt", std::ios_base::app);

    filevar << "lala";

    filevar.close();
    
    return 0;
}