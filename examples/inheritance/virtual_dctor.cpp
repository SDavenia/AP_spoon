#include <iostream>
//TL;DR: if destructor is not virtual, you risk leaking memory

template <typename T>
class CBase1{
public:    
    T field1; 
    CBase1(const T& f0):field1(f0){std::cout<<"Constructing base"<<std::endl;};
   // virtual 
   // virtual ~CBase1(){std::cout<<"base dctor called"<<std::endl;};
   ~CBase1(){std::cout<<"Base dctor called"<<std::endl;}
};

template <typename T>
class CDerived1:public CBase1<T>{
public:
    T field2; 
    T* arr;
    CDerived1(const T& f0):CBase1<T>(f0){
        std::cout<<"Constructing derived"<<std::endl;
        field2=f0;
        arr=new int[10];
    };
   // ~CDerived1() override {free(arr); std::cout<<"derived dctor called"<<std::endl;}
   ~CDerived1() {free(arr); std::cout<<"derived dctor called"<<std::endl;}
};


int main(){
    
// CDerived1<int> c(11);
// std::cout<<c.field1<<" "<<c.field2<<std::endl;
 
 //this is how it's written in most examples/tutorials, but it hardly makes sense like that:
 //CBase1<int>* ptr=new CDerived1<int>(7);
 //instead: 


//CDerived1<int> obj2(9);
//std::cout<<obj2.field1<<std::endl;
//std::cout<<obj2.field2<<std::endl;

CDerived1<int>* c1 = new CDerived1<int>(12);
CBase1<int>* ptr=c1;

std::cout<<ptr<<"   "<<c1<<std::endl;
delete ptr; 


 return 0;   
} 


/*
CDerived1<int>* c1 = new CDerived1<int>(12);
CBase1<int>* ptr=c1;

std::cout<<ptr<<"   "<<c1<<std::endl;
delete ptr; 
*/