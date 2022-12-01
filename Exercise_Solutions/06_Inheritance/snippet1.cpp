#include <iostream>
class Shape{
public:
  virtual void print()=0;
  virtual ~Shape(){};
};

class Circle: public Shape{
  double r;
public:
  void print() override {std::cout<<r<<std::endl;}
};

int main(){
  //Shape s;
  Circle c; 
  c.print();
}
/*
The  error is that Shape is an abstract class since it has a virtual function
set to 0. Hence we are not able to define an object of class Shape.
*/