#include <iostream>
//examples of dynamic polymoprhism
 
class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
   virtual int area (){ return 0; }
  // virtual int area ()=0;//makes the class abstract, then you can't have an object of it
    //pure virtual functions must be overriden, otherwise the child class is also abstract
};

class Rectangle: public Polygon {
  public:
      //override helps compiler and makes sure you don't type anything wrong
    int area() override{ 
        return width * height;
    }
};

class Triangle: public Polygon {
  public:
    int area() override{ 
        return (width * height / 2); 
    }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon poly;
  /*
  Below you can notice how pointers to the derived class are compatible with pointers to the base class.
   However, to call their member functions from the pointer you need to use ->.
   Since we are overriding the functions, the derived one will be called, if we had not the base one would have been
    called since the pointer is a pointer to object of the base class. (As evalutation of the objects occurs at run time and not compile time)
  */
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  Polygon * ppoly3 = &poly;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  ppoly3->set_values (4,5);
  std::cout << rect.area() <<std::endl;      // call using the object can also do it with overload
  std::cout << ppoly1->area() << std::endl;  // call using pointer, can't be done with overload
  std::cout << ppoly2->area() << std::endl;
  std::cout << ppoly3->area() << std::endl;
  return 0;
}
