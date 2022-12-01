#include <iostream>
/*
class MyClass{
  int x;
  MyClass():x(0){};
}

std::ostream& operator<<(std::ostream& os, const MyClass& m){
    os<<m.x<<std::endl;
    return os;
};

int main(){
    MyClass m;
    std::cout<<m<<std::endl;
}
*/
// The error is that the class has by default its access set to private.
// Hence since the operator is not defined as a friend of that class it can't access
// Its private variable x and work correctly
// Moreover constructors need to be public

class MyClass{
  int x;
public:
  MyClass():x(0){};
  friend std::ostream& operator<<(std::ostream& os, const MyClass& m);
  
};

std::ostream& operator<<(std::ostream& os, const MyClass& m){
    os<<m.x<<std::endl;
    return os;
};

int main(){
    MyClass m;
    std::cout<<m<<std::endl;
}