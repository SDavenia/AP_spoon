#include <iostream>
void add_two(int* a){
    *a=*a+2;
}
int main(){
    int var = 0;
    add_two(&var);
    std::cout<<var<<std::endl;
    return 0;
}
/* This is wrong cause we pass a pointer to a in the function
   but inside the function we use a itself while we should dereference it
   this leads to var not being changed*/ 
