#include <iostream>
class CMyClass{
    int a;
public:
    CMyClass(int x):a(x){};
};

int main(){
   CMyClass c(7);
   std::cout<<"this now works"<<std::endl;
   return 0;
}

// This won't work cause we have not set the constructor function to public
// Hence we are unable to call it.