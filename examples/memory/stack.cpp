#include <iostream>
/*
Here we have a class with a pointer to int.
In this case c++ still makes a shallow copy, so we have two pointers
 pointing to the same memory location.
*/

class MyClass{
public:
    int* data;
    MyClass(){};
    MyClass(int& N);
    //~MyClass();
};

MyClass::MyClass(int& N){
    data = &N;
}


int main(){
    int N{5};
    MyClass obj1(N);

    MyClass obj2;
    // Here the compiler makes a shallow copy, so the address is the same as above
    obj2 = obj1;
    std::cout<<obj1.data<<std::endl;
    std::cout<<obj2.data<<std::endl;

    // We can see that now by changing obj2 we have another pointer to the same value.
    *obj2.data = 3;
    std::cout<<*obj1.data<<std::endl;
}