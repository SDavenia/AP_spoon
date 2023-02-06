#include <iostream>

void add_two(int& a){
    //std::cout<<a<<std::endl;
    std::cout<<&a<<std::endl;
    a = a + 2;
    int& b{a};
    std::cout<<b<<std::endl;
}

int main()
{
    int a{2};
    std::cout<<&a<<std::endl;
    add_two(a);


}