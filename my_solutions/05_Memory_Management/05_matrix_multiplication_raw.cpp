/*
Rewrite your matrix multiplication exercise using raw pointers to store the data instead of vectors.
*/
#include <iostream>
#include <fstream>
#include <cstring>

template <typename T>
class CMatrix{
    int size; // To store the dimension of the square matrix
    T* data;  // Pointer to T where data is stored
public:
    // Constructors
    CMatrix(){
        std::cout<<"Default constructor"<<std::endl;
        size = 0;
        data = nullptr;
    }
    // Constructor when number of elements is specified
    CMatrix(int N);

    // Destructor: need to specify it as we are using raw pointers
    ~CMatrix(){
        if (data != nullptr){
            std::cout<<"Destructor called"<<std::endl;
            delete[] data;
            data = nullptr;
        }
    }

    // Function to read data from a file
    void read_from_file(std::string filename);

    // Function to write data to a file
    void write_to_file(std::string filename) const;

    // Function to perform matrix multiplication
    CMatrix operator*(const CMatrix& A) const;
    

    // Operator overloading to print matrix
    template <typename O>
    friend std::ostream& operator<<(std::ostream& os, const CMatrix<O>& C);

    // Copy constructor CMatrix B(A);
    CMatrix(const CMatrix& A);

    // Copy assingment operator
    CMatrix& operator=(const CMatrix& A);
    
    // Move constructor
    CMatrix(CMatrix&& A);

    // Move assignment operator
    CMatrix& operator=(CMatrix&& A);
};


int main()
{
    CMatrix<double> A;// B;
    A.read_from_file("A.txt");
    //B.read_from_file("B.txt");
    //std::cout<<A<<std::endl;
    //std::cout<<B<<std::endl;
    //auto C = A*B;
    //std::cout<<C<<std::endl;
    //C.write_to_file("C.txt");

    // COPY CONSTRUCTOR
    // D(A); ERROR ALL THE FOLLOWING WORK
    // CMatrix<int> D(A); Error as we have a double
    //auto D(A);
    //CMatrix D{A};
    //CMatrix D(A);
    //CMatrix<double> D(A);
    // CMatrix<double> D = A;
    //std::cout<<D<<std::endl;

    // COPY ASSINGMENT OPERATOR
    CMatrix<double> E;
    E = A;

    // MOVE CONSTRUCTOR
    CMatrix F{std::move(E)};
    // CMatrix<double> G = std::move(F)

    // Move assignment operator
    /*
    WRONG
    CMatrix G;
    G = std::move(F);

    Calss 
    */
    CMatrix<double> G;
    G = std::move(F);

    
}

// Constructor
template <typename T>
CMatrix<T>::CMatrix(int N){
    data = nullptr; // for safety
    std::cout<<"Calling costructor with N"<<std::endl;
    size = N;
    if(N>0){
        data = new T[N*N];
    }
}

// Read-Write from file
template <typename T>
void CMatrix<T>::read_from_file(const std::string filename){
  std::ifstream filevar(filename);
  if(filevar){
      filevar>>size;
      data=new T[size*size];
  for (int i=0;i<size;++i) {
    for (int j=0;j<size;++j) {
      filevar>>data[i*size+j];
    }
  }
  filevar.close();}
    else{
    std::cout<<"couldn't open the file "<<filename<<std::endl;    
  }
}

template <typename T>
void CMatrix<T>::write_to_file(std::string filename) const{
    std::ofstream filevar(filename);
    if(filevar){
        filevar << size <<std::endl;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                filevar << data[j + i*size] << " ";
            }
            filevar<<""<<std::endl; //using if conditions to check whether to go next line is slower I think
        }
    }else{
        std::cout<<"failed to open file"<<std::endl;
    }
    filevar.close();
}

// Perform matrix multiplication
template <typename T>
CMatrix<T> CMatrix<T>::operator*(const CMatrix<T>& A) const{
    CMatrix<T> C(size);
    for (int i=0;i<size;i++){
		for (int j=0;j<size;j++){
			for (int k=0;k<size;k++){
				C.data[i*size + j]+=data[i*size + k]*A.data[k*size + j];
			}
		}
	}
    return C;
}

// print output operator overloaded
template <typename T>
std::ostream& operator<<(std::ostream& os, const CMatrix<T>& C){
    os<<"Square matrix of dimension "<<C.size<<std::endl;
    for (int i = 0; i < C.size; i++){
        for(int j = 0; j < C.size; j++){
            os<<C.data[j + i*C.size]<<" ";
        }
        os<<""<<std::endl;
    }
    return os;
}


// Copy constructor
template <typename T>
CMatrix<T>::CMatrix(const CMatrix<T>& A){
    if(this != &A){
        std::cout<<"copy constructor being called"<<std::endl;
        size = A.size;
        if(data != nullptr){
            delete[] data;
            data = nullptr;
        }
        if(A.data == nullptr){data = nullptr;}
        else{
            data = new T[size*size];
            for(int i = 0; i < size*size; i++){
                data[i] = A.data[i];
            }
        }

    }
}

// Copy assignment operator
template <typename T>
CMatrix<T>& CMatrix<T>::operator=(const CMatrix<T>& A){
    if(this != &A){
        std::cout<<"copy assignment operator being called"<<std::endl;
        size = A.size;
        if(data != nullptr){
            delete[] data;
            data = nullptr;
        }
        if(A.data == nullptr){data = nullptr;}
        else{
            data = new T[size*size];
            for(int i = 0; i < size*size; i++){
                data[i] = A.data[i];
            }
        }

    }
    return *this;

}

// Move costructor operator
template <typename T>
CMatrix<T>::CMatrix(CMatrix<T>&& A){
    if (this != &A){
        std::cout<<"Move constructor being called"<<std::endl;
        size = A.size;
        A.size = 0;
        data = A.data;
        A.data = nullptr; //since destructor on A is called automatically
    }
}

// Move assignment operator
template <typename T>
CMatrix<T>& CMatrix<T>::operator=(CMatrix<T>&& A){
    if (this != &A){
        std::cout<<"Move assignment operator being called"<<std::endl;
        size = A.size;
        A.size = 0;
        data = A.data;
        A.data = nullptr; //since destructor on A is called automatically
    }
    return *this;
}