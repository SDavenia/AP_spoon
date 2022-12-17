#include <iostream>

int main( int argc, char *argv[] ){
    //argc - number of command line input parameters
    //argv - contains the parameters
    
    //you can check if the user forgot to pass an expected parameter:
    if (argc<2){
        std::cout<<"USAGE: "<<argv[0]<<" SOME NUMBERS"<<std::endl;
    }
    
    // First prints the name of the program and then the arguments passed afterwords (since we start at 0)
    for (int i=0;i<argc;i++){
        std::cout<<"Printing: "<<argv[i]<<" "<<std::endl; 
    }
    std::cout<<std::endl;
    
    //note that the parameters passed like this are c-strings, so you might need to convert them to something else
    int a = atoi(argv[1]);
    double b = atof(argv[1]);
    
    std::cout<<a<< " "<<b<<std::endl;
    
    return 0;
} 
