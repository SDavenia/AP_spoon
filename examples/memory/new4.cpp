#include <iostream>
/*
In this example we define the copy assingment operator as well as the copy constructor.
It is needed for passing objects of our class to functions by value, otherwise we would not be able to,
 as when an object is passed to a function a copy of that object is constructed.
*/

template <typename T>
class CMyClass{
public:
    T* data;
    size_t size;

    // Constructor, destructor and print.
    CMyClass(const int& N);
    ~CMyClass();
    void print();

    // Copy assingment operator
    CMyClass& operator=(const CMyClass& p);
    CMyClass operator+(const CMyClass& p);

    // Copy constructor
    CMyClass(const CMyClass& p);
};

// Constructor when an integer N is passed.
template<typename T> 
    CMyClass<T>::CMyClass(const int& N) {
    data=new T[N];
    size=N;
    for(int i=0;i<N;i++){
        data[i]=i;
    }
    std::cout<<"constructor called"<<std::endl;
}

// Destructor defined
template<typename T> 
    CMyClass<T>::~CMyClass() {
    delete[] data;
    data=nullptr;
    std::cout<<"destructor called"<<std::endl;
}

template<typename T> 
void CMyClass<T>::print() {
     for(int i=0;i<size;i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;   
}

// Here we define the copy assignment operator
template <typename T>
CMyClass<T>& CMyClass<T>::operator=(const CMyClass<T>& p){
    std::cout<<"assignment operator called"<<std::endl;
//first check for self-assignment
if (this != &p) { 
    //copy non-dynamic variables
	size=p.size;
    //free memory of existing dynamic variables
	if (data != nullptr){
		delete[] data;
		data=nullptr;
    }	
    //create and copy dynamic variables
	if(p.data==nullptr){data=nullptr;}
	else{
		data = new T[size];
		for(int i=0;i<size;i++){
			data[i]=p.data[i];
        };
	}//else
	
}//of cheking for self-assignement
return *this;
};


// Here we define the copy constructor
template<typename T> 
CMyClass<T>::CMyClass ( const CMyClass<T>& p ) {
    std::cout<<"copy constructor called"<<std::endl;
//first check for self-assignment
if (this != &p) { 
//copy non-dynamic variables
	size=p.size;
//create and copy dynamic variables
	if(p.data==nullptr){data=nullptr;}
	else{
		data = new T[size];
		for(int i=0;i<size;i++){
			data[i]=p.data[i];
        };
	}//else
	
}//of cheking for self-assignement
    
}//copy constructor



//nonsense function to see what happens 
template <typename T>
void a_function(CMyClass<T> obj){
    std::cout<<obj.size<<std::endl;
}

template<typename T> 
CMyClass<T> CMyClass<T>::operator+ ( const CMyClass<T>& p ) {
    std::cout<<"plus operator called"<<std::endl;
    if (size!=p.size){std::cerr<<"not working with different sizes"<<std::endl;
        exit(1);
    }
    CMyClass<T> result(size);
    for(int i=0;i<size;i++){
        result.data[i]=data[i]+p.data[i];
    }    
    return result;
}


int main(){

    // CMyClass<int> obj0; This would result in an error as we have not defined a constructor with ().
    std::cout<<"These two should call constructor"<<std::endl;
    CMyClass<int> obj(10);
    CMyClass<int> obj2(10);
    //THIS ACTUALLY NEVER CALLS ASSIGNMENT OPERATOR! 
    std::cout<<"Copy elision: no assignment operator but default constructor instead"<<std::endl;
    auto obj3=obj2+obj;
    obj3.print();

    //This will crash without a copy constructor, as we are passing by value.
    a_function(obj);
    // Moreover, the object will be destroyed when function is done, so destructor is called as well.

    //another use of copy constructor
    std::cout<<"Here we will call the copy constructor as well"<<std::endl;
    CMyClass<int> obj4(obj3);
    
    std::cout<<"Here we have copy elision again, as instead of call"<<std::endl;
    CMyClass<int> obj5(obj3+obj2);
    return 0;
}
 
