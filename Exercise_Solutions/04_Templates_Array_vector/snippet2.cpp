#include <iostream>
/*
template <typename T, double S>
void add_number(T& var){
    T=T+S;
}
*/

/*
The problem here is that double can't be templated, only int and bool can.
Moreover, T is used instead of the variable of type T var
*/

// Define a function
template <typename T, int S>
void add_number(T& var){
    var=var+S;
}

int main()
{
    int a{5};
    add_number<int, 20>(a);
    std::cout<<a<<std::endl;
}