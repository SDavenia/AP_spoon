#include <iostream>

/*
template <typename T>
void print(const T& var){
  std::cout<<var<<std::end;
}

struct MyClass{
  int a;
  int b;
}

int main(){
 MyClass var;
 print(var);
}
*/

/*
The type of the attributes of class object var need to be specified, otherwise it does not compile
Moreover print is not defined for this class of objects
 */

template <typename T>
void print(const T& var){
  std::cout<<var<<std::end;
}

struct MyClass{ //both are public
  int a;
  int b;
};

int main(){
 MyClass<int> var;
 print(var);
}