#include <iostream>
/*
template <typename... Types>
void myPrint(const Types&... args){
    std::cout<<arg<<" ";
    myPrint(args...);
}
*/

/*
arg is not defined, but it needs to be defined otherwise we obtain a segmentation
We also need to include const.
*/

template <typename T>
void myPrint(const T& arg){
    std::cout<<arg<<" ";
}


template <typename T, typename... Types>
void myPrint(const T &arg, const Types&... args){
    std::cout<<arg<<" ";
    myPrint(args...);
}


int main()
{
    myPrint(1, 2, 3.0, "meow");
    return 0;
}