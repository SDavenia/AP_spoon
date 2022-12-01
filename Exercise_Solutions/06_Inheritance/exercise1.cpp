#include <iostream>
/*
Create an abstract base class shape, inherit classes 
 - triangle (3 vertices member variables)
 - polygon: should have a raw pointer to vertices coordinates

The classes should have functions to calculate perimeter and to print
vertices coordinates that work with runtime polymorphism.
*/


/*
// Create a class vertices to store vertices
template <typename T>
class Vertices{
public:
    T x;
    T y;
    Vertices(const T&a, const T&b){
        x = a;
        y = b;
    }
    void print_coordinates(){
        std::cout<<"x is: "<<x<<", y is: "<<y<<std::endl;
    }
};
*/


class Shape{
public:
    virtual void print()=0;
    // We define a virtual perimeter function, which returns a 
    // depending on the type of the coordinates passed (int, double, ...)
    virtual double perimeter(){
        return 0;
    };
    virtual ~Shape(){};
};


class Triangle: public Shape{
public:
  double x1, x2, x3, y1, y2, y3;

  Triangle(const double &a, const double &b, 
           const double &c, const double &d,
           const double &e, const double &f){
    x1=a; y1=b; 
    x2=c; y2=d;
    x3=e; y3=f;

  }
  void print() override{
    std::cout<<x1<<" "<<y1<<std::endl;
  }
  double perimeter() override{
    return 6.2;
  }
   
};




int main()
{
    double  a{1},b{2},c{3},d{4},e{5},f{6};
    
    Triangle t(1,2,3,4,5,6);
    t.print();
    std::cout<<"  "<<t.perimeter()<<std::endl;

}