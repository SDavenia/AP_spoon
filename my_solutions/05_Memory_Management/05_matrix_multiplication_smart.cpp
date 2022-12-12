#include <memory>
#include <iostream>
#include <cstring>
#include <fstream>
/*
Redefine the matrix class overloading matrix multiplication but this time use unique pointers
*/

template <typename T>
class CMatrix{
    int size;
public:
    std::unique_ptr<T[]> data;

    // Constructors
    CMatrix(){
        std::cout<<"Default constructor"<<std::endl;
        size = 0;
        data = nullptr;
    };
    CMatrix(const int N); // Constructor with size N specified 
    // We do not need a default destructor as smart pointers call it automatically, you can check with leaks

    // copy constructor CMyClass A{B}
    CMatrix(const CMatrix& p);

    // copy assingment operator
    CMatrix& operator=(const CMatrix& p);

    // move constructor
    CMatrix(CMatrix&& p);

    // move assingment operator
    CMatrix& operator=(CMatrix&& p);
 
    void read_from_file(std::string filename);
    void print_to_file(std::string filename) const;

    // Overloaded operators
    CMatrix operator*(const CMatrix& B) const;

    // Friend functions
    template <typename O>
    friend std::ostream& operator<<(std::ostream& os, const CMatrix<O>& A);
};


int main()
{
    CMatrix<int> A, B;
    A.read_from_file("A.txt");
    B.read_from_file("B.txt");
    //std::cout<<A;
    //std::cout<<B;

    auto C = A*B;
    //std::cout<<C;
    C.print_to_file("C.txt");
    CMatrix D{C};                    // Here we call the copy constructor
    C = A;                           // Here we call the assignment operator
    CMatrix<int> E{std::move(A)};    // Here we call the move constructor
    E = std::move(A);                // Here we call the move assignment operator

}

// Constructor
template <typename T>
CMatrix<T>::CMatrix(const int N){
    std::cout<<"Constructor"<<std::endl;
    size = N;
    data=std::make_unique<int[]>(N*N);
}

// Copy constructor
template <typename T>
CMatrix<T>::CMatrix(const CMatrix<T>& p){
    std::cout<<"Copy constructor"<<std::endl;
    // Check for self assignment
    if (this != &p){
        size = p.size;
        int n_elements = size * size;
        // if (data != nullptr){data.reset();} No need as we reassign it and the smart pointer automatically removes memory
        if (p.data == nullptr){
            data.reset();
        }else{
            data = std::make_unique<T[]>(n_elements);
            for(int i = 0; i < n_elements; i++)
                data[i] = p.data[i];
        }
    }
}

// Copy assignment
template <typename T>
CMatrix<T>& CMatrix<T>::operator=(const CMatrix<T>& p){
    std::cout<<"Assignment operator"<<std::endl;
    if (this != &p){
        size = p.size;
        int n_elements = size * size;
        // if (data != nullptr){data.reset();}
        if (p.data == nullptr){
            data = nullptr;
        }else{
            data = std::make_unique<T[]>(n_elements);
            for(int i = 0; i < n_elements; i++){
                data[i] = p.data[i];
            }
        }
    }
    return *this;
}


// Move constructor
template <typename T>
CMatrix<T>::CMatrix(CMatrix<T>&& p){
    std::cout<<"Move constructor"<<std::endl;
    if (this != &p){
        size = p.size;
        p.size = 0;
        // if (data != nullptr){data.reset();}
        data = std::move(p.data);
        // p.data.reset(); No need since it goes out of scope automatically
    }
}

// Move assignment operator
template <typename T>
CMatrix<T>& CMatrix<T>::operator=(CMatrix<T>&& p){
    std::cout<<"Move assignment operator"<<std::endl;
    if (this != &p){
        size = p.size;
        p.size = 0;
        if (data != nullptr){data.reset();}
        data = std::move(p.data);
        //p.data.reset();
    }
    return *this;
}




template <typename T>
void CMatrix<T>::read_from_file(std::string filename){
    std::ifstream filevar(filename);
    if(filevar){
        filevar >> size;
        int n_elements = size*size;
        data=std::make_unique<T[]>(size * size);
        for (int i = 0; i < n_elements; i++){
            filevar>>data[i];
        }
    }else{
        std::cout<<"Unable to open file"<<std::endl;
    }
}

template <typename T>
void CMatrix<T>::print_to_file(std::string filename) const{
    std::ofstream filevar(filename);
    int n_elements = size*size;
    if(filevar){
        filevar << size <<std::endl;
        for(int i = 0; i < n_elements; i++){
            filevar << data[i] << " ";
            if((i+1)%size == 0)
                filevar <<std::endl;
        }
    }
}


// Overloaded operators
template <typename T>
CMatrix<T> CMatrix<T>::operator*(const CMatrix<T>& B) const{
    int n_elements = size * size;
    T sum;
    CMatrix<T> C(size);
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            sum = 0;
            for(int k = 0; k < size; k++){
                sum = sum + data[k + i*size] * B.data[j + k*size];
            }
            C.data[j + i * size] = sum;
        }
    }
    return C;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const CMatrix<T>& A){
    int element_size = A.size * A.size;
    for(int i = 0; i < element_size; i++){
        os<<A.data[i]<<" ";
        if((i+1)%A.size == 0)
            os<<""<<std::endl;
    }
    return os;
}



