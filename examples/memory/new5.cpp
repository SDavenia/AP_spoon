#include <iostream>


template <typename T>
class CMyClass{
public:
    T* data;
    size_t size;
    CMyClass(const int& N);
    ~CMyClass();
    void print();
    // Copy assignment operator
    CMyClass& operator=(const CMyClass& p);

    // Move assignment opereator
    CMyClass& operator=(CMyClass&& p);

    // Plus operator
    CMyClass operator+(const CMyClass& p);

    // Copy constructor
    CMyClass(const CMyClass& p);

    // Move assingment operator
    CMyClass(CMyClass&& p);
    
};

template<typename T> 
    CMyClass<T>::CMyClass(const int& N) {
    data=new T[N];
    size=N;
    for(int i=0;i<N;i++){
        data[i]=i;
    }
    std::cout<<"constructor called"<<std::endl;
}


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


template <typename T>
CMyClass<T>& CMyClass<T>::operator=(CMyClass<T>&& p){
    std::cout<<"move assignment operator called"<<std::endl;
//first check for self-assignment
if (this != &p) { 
//copy non-dynamic variables
	size=p.size;
    p.size=0;
//free memory of existing dynamic variables
	if (data != nullptr){
		delete[] data;
    }	
    data=p.data;
    p.data=nullptr;

	
}//of checking for self-assignment
return *this;
};


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

template<typename T> 
CMyClass<T>::CMyClass ( CMyClass<T> && p ) {
     std::cout<<"move constructor called"<<std::endl;
//first check for self-assignment
if (this != &p) { 
//copy non-dynamic variables
	size=p.size;
    p.size=0;
//create and copy dynamic variables
    data=p.data;
    p.data=nullptr;
}//of checking for self-assignment
    
}



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
   
    CMyClass<int> obj(10);
    CMyClass<int> obj2(10);
   //THIS ACTUALLY NEVER CALLS ASSIGNMENT OPERATOR! 
    auto obj3=obj2+obj;
    obj3.print();
    //will crash without a copy constructor
 //   a_function(obj);
    //another use of copy constructor
  //  CMyClass<int> obj4(obj3);
    
    //obj3 still exists, but assume it can't be used anymore 
    auto obj5=std::move(obj3); 
    std::cout << "This moves" <<std::endl;
    obj5=std::move(obj2);
    
    return 0;
}
 
 
