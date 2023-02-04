### snippet 1
```
class Shape{
 public:
  virtual void print()=0;
  virtual ~Shape(){};
}

class Circle: public Shape{
  double r;
  void print() override {std::cout<<r<<std::endl};
}

int main(){
  Shape s;
  Circle c; 
}
```
The error here is that Shape is an abstract class, since it has a virtual function set to 0.
This means that we can't define an object of class Shape.
Moreover, there are semicolon missing at the end of class definitions.

```
class Shape{
 public:
  virtual void print()=0;
  virtual ~Shape(){};
};

class Circle: public Shape{
  double r;
  void print() override {std::cout<<r<<std::endl};
};

int main(){
  Circle c; 
}
```

### snippet 2
```
class Shape{
 public:
  virtual void print(){};
  ~Shape(){};
}

class Polygon: public Shape{
  double* v;
  void print() override {std::cout<<"hi"<<std::endl};
  Polygon(const int&N){v=new double[N];};
  ~Polygon(){delete[] v;};
}

int main(){
  Shape* s = new Circle(7);
  s.print();
}
```

The problem here is that when pointer s goes out of scope only the destructor of the base class Shape is called, meaning
 that the memory is not actually freed. This occurs because we use a pointer to the base class Shape for a new object of class Polygon (I suppose there is a typo here).
To fix this we need to make the destructor virtual, which ensures that the destructors of the derived class is called as well.

```
class Shape{
 public:
  virtual void print(){};
  virtual ~Shape(){};
}

class Polygon: public Shape{
  double* v;
  void print() override {std::cout<<"hi"<<std::endl};
  Polygon(const int&N){v=new double[N];};
  ~Polygon() override {delete[] v;};
}

int main(){
  Shape* s = new Circle(7);
  s.print();
}
```
