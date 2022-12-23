#include <iostream>
extern "C" {
    void hello(){
        std::cout<<"Hello, World!"<<std::endl;
    }
    
    int sum(int a, int b){
    return a+b;
    }
}

