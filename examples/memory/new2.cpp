#include <iostream>
/*
If we do not define the copy constructor, we incur in an error, since the destructor tries to free twice the same memory, 
as only a shallow copy was created.
*/
template <typename T>
class CMyClass{
public:

    // Allocate memory on the heap for data.
    T* data;
    size_t size;

    // Constructor
    CMyClass(const int& N);

    // Destructor (need to define it as we have to allocate memory on the heap).
    ~CMyClass();
    void print();
    CMyClass& operator=(const CMyClass& p);
}; 

// Define the constructor, we can't use the default one as we want to have memory allocated on the heap.
template<typename T> 
CMyClass<T>::CMyClass(const int& N) {
    data=new T[N];
    size=N;
    for(int i=0;i<N;i++){
        data[i]=i;
    }
    std::cout<<"constructor called"<<std::endl;
}

// 
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


int main(){
   
    CMyClass<int> obj(10);
    CMyClass<int> obj2(10);
    
    obj2=obj;   
    obj2.print();
    
    return 0;
}
 
