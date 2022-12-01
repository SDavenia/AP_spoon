#include <iostream>

class Shape{
public:
  virtual void print(){};
  ~Shape(){
    std::cout<<"Shape destructor"<<std::endl;
  };

};

class Polygon: public Shape{
    double* v;
    void print() override {std::cout<<"hi"<<std::endl;}
    Polygon(const int& N){v = new double[N];};
    ~Polygon(){
        std::cout<<"Polygon destructor"<<std::endl;
        delete[] v;}
};

class Circle: public Shape{
  double r;
public:
  void print() override {std::cout<<r<<std::endl;}
};

int main(){
    Shape* s= new Polygon; // Creates a pointer to shape.
    s -> print();
}

/*
RICONTROLLA E SEMMAI CHIEDI CHE QUESTO PROPRIO NON TORNA.

The error was that shape is a pointer not an object, so I need to use ->
 and not . to call the function print


If the class was meant to define a polygon the problem was that we were not using
a virtual destructor, so the standard one would've been called without emptying the memory.
*/