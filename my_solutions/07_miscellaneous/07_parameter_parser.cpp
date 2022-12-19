/*
Write your own "parameter parser" similar to getops(). Your code should accept parameters like.
*/
#include <iostream>
#include <string>
#include <sstream>

// I need to be able to compile as ./a.out -n1 1 -n2 2 -n3 3

template <typename T>
T my_getopt(int argc, char* argv[], std::string s);

int main(int argc, char* argv[]){

}

/*
I take as input the number of arguments in the command line, their names and a string s of plausible parameters
*/

// We read two at a time command line arguments -n1 and 2
template <typename T>
T my_getopt(int argc, char* argv[], std::string s){
    std::string flag;
    int number;
    if (argc > 0){
        argc = argc - 2; // Since we remove the two strings
        flag = argv[0];
        number = argv[1];

    }


}