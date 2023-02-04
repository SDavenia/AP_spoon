#include <iostream>

template <typename T>
class CBase1{
public:    
    T field1; 
    CBase1(const T& f0):field1(f0),field2{f0},field3(f0){};
    ~CBase1(){std::cout<<"base1 dctor called"<<std::endl;};
    void say_hi(){std::cout<<"hi"<<std::endl;};
protected:
    T field2;
private: 
    T field3;    
};

class CBase2{
public:    
    int field0; 
    CBase2(const int& f0):field0(f0){};
    ~CBase2(){std::cout<<"base2 dctor called"<<std::endl;};
protected:
    int field01;
private: 
    int field02;    
};


 
template <typename T>
class CDerived1:public CBase1<T>, public CBase2{
public:
    T field4; 
    // When we call the constructor of the derived class first we need to call the constructor of the base classes
    CDerived1(const T& f0):CBase1<T>(f0),CBase2(f0){
        field4=f0;
    };
   ~CDerived1(){std::cout<<"derived dctor called"<<std::endl;}
   void test_function(){
       // Here we access the members of the non templated base 
       std::cout<<"non templated members"<<std::endl;
       std::cout<<field0<<" "<<field01<<std::endl;
       // Here we want to access the members of the templated base
       //using "this" is one of the ways to get around templates 
       std::cout<<"templated members"<<std::endl;
       std::cout<<this->field1<<" "<<this->field2<<" "<<std::endl; 
       std::cout<<field1<<std::endl;  
    };
};


int main(){
    
 CDerived1<int> c(11);
 std::cout<<c.field0<<" "<<c.field4<<std::endl;
 std::cout<<c.field1<<std::endl;
 c.test_function();
 //c.say_hi();
    
}
// Notice how the derived destructor is NOT called, see virtual_dctor.cpp