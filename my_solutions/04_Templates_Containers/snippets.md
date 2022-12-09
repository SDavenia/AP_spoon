### Snippet 1
template <typename T>
class CMyClass{
  T a;
  T b;
}

int main(){
  CMyClass var;
 ...
}
The problem here is that when working with templated classes we need to specify the type we want the elements of the class to have. This is because it can't understand it explicitly as with templated functions.
template <typename T>
class CMyClass{
  T a;
  T b;
}

int main(){
  CMyClass<int> var;
 ...
}

### Snippet 2
template <typename T, double S>
void add_number(T& var){
    T=T+S;
}

The problem with this code is that we are using a template T (so a type), instead of the actual variable var to sum.
template <typename T, double S>
void add_number(T& var){
    var = var + S;
}

### Snippet 3
template <typename... Types>
void myPrint(const Types&... args){
    std::cout<<arg<<" ";
    myPrint(args...);
}
Variadic templates are written the same way you'd write a recursive function, so you need a base case and a recursion.
The problem here is that we have not defined the standard myPrint function, which is needed to exit the loop. We also need the variadic templated function to take a first element as argument, but that also needs to be templated.

template <typename T>
void myPrint(const T& arg){
    std::cout<<arg<<" ";
}

template <typename T, typename... Types>
void myPrint(const T& arg, const Types&... args){
    std::cout<<arg<<" ";
    myPrint(args...);
}


### Snippet 4
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

First of all there is a semicolon missing after the class definition.
This will not work because the << operator is not defined for objects of the class MyClass, so we have to overload it for objects of that class.
Moreover there is a typo where instead of endl end is spelt.

template <typename T>
void print(const T& var){
  std::cout<<var<<std::endl;
}

struct MyClass{
  int a;
  int b;
  friend std::ostream& operator<<(std::ostream& os, const MyClass& c);
};

int main(){
 MyClass var;
 print(var);
}

std::ostream& operator<<(std::ostream& os, const MyClass& c){
    os << "a is" << c.a << "and b is" << c.b << std::endl;
}