#include <iostream>
#include <cstring>
#include <fstream>
#include <memory>
/*
Rewrite your matrix multiplication exercise using 
smart pointers to store the data instead of vectors.

Here we do not need the destructor as we are using smart pointers
We also need to change the definition of the data pointer
*/

template <typename T>
class CMatrix{
public:
    std::unique_ptr<T[]> data;
    int size;

    // Need to create a constructor 
    // If we specify size, this is needed cause in the overloading of * we use it.
    CMatrix(const int& N){
        data=std::make_unique<T[]>(N*N);
        size = N;
        std::cout<<"Constructor called"<<std::endl;
    }
    CMatrix(){
        std::cout<<"Empty constructor called"<<std::endl;
    };


    // Print in matrix format function
    void print_matrix();


    // These two functions read and write a matrix from/to a file
    void read_from_file(std::string filename);
    void print_to_file(std::string filename);


    CMatrix<T> operator*(const CMatrix<T>& B);
};


// Print in matrix format
template <typename T>
void CMatrix<T>::print_matrix(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j <size; j++){
            std::cout<<data[i*size + j]<<" ";
        }
        std::cout<<" "<<std::endl;
    }
}

// Read from txt file: first the size, then the elements
template <typename T>
void CMatrix<T>::read_from_file(std::string filename){
  std::cout<<"Reading matrix from file"<<std::endl;
  std::ifstream filevar(filename);
  if(filevar){
    filevar>>size;
    data=std::make_unique<int[]>(size*size);
    // We are filling the matrix by row
    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        filevar>>data[i*size+j];
      }
    }
  }
  filevar.close();
}

// Printing function to type
template <typename T>
void CMatrix<T>::print_to_file(std::string filename){
  std::cout<<"Printing matrix to file"<<std::endl;
  std::ofstream filevar;
  std::cout<<""<<std::endl;
  filevar.open(filename, std::ios_base::app);
  filevar<<size<<std::endl;
  for (int i = 0; i<size; i++){
    for (int j = 0; j<size; j++){
      filevar<<data[i*size + j]<<" ";
    }
  }
  filevar.close();
}

// Matrix multiplication
template <typename T>
CMatrix<T> CMatrix<T>::operator*(const CMatrix<T>& B){
  if (size != B.size)
    std::cout<<"The two matrices have different size, can't perform matrix multiplication"<<std::endl;
  // We initialize matrix result of size same as the other 2.
  CMatrix<T> result(size);
  // Now we loop over all entries of the result matrix.
  for(int i = 0; i<size; i++){
    for(int j = 0; j < size; j++){
      // Here we compute the entry result[i,j]
      T res = 0;
      // We loop over k and make sum_k=1^n A_ik B_kj
      for(int k = 0; k < size; k++){
        res = res + data[i*size + k] * B.data[k*size + j];
      }
      result.data[i*size + j] = res;
    }
  }
  return result;

}



int main(){
    CMatrix<int> A, B, C;
    A.read_from_file("A.txt");
    A.print_matrix();
    B.read_from_file("B.txt");
    B.print_matrix();
    C = A*B;
    C.print_matrix();
    C.print_to_file("C.txt");
}

