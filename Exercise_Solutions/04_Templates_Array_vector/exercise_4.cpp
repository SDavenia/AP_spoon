#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstring>
/*
Write a square matrix class that: 
 - uses std::vector to store the data
 - is templated on the type of the data
 - can read/write a matrix to/from file
 - has operator * overloaded
*/

template <typename T>
class CMatrix{
public:
    std::vector<T> data; 
    int size;
    // Constructors for the square matrix in case we specify or not a size.
    CMatrix(int N){
      size = N;
      data.resize(N*N);
    }
    CMatrix(){};
    // These two functions read and write a matrix from/to a file
    void read_from_file(std::string filename);
    void print_to_file(std::string filename);

    // Now I define a print function to print the matrix
    void print();

    CMatrix<T> operator*(const CMatrix<T>& B);
};

int main(){
  CMatrix<int> A,B;
  A.read_from_file("A.txt");
  B.read_from_file("B.txt");
  A.print();
  std::cout<<""<<std::endl;
  B.print();
  auto C = A*B;
  C.print_to_file("C.txt");
  C.print();
  
}

/*
Here is the function to read from a txt file.
The first argument should be the size of the matrix, followed by the elements in rowise order.
We open the file filename and read the size
We read all the elements and place them contingously in the matrix
*/
template <typename T>
void CMatrix<T>::read_from_file(std::string filename){
  std::ifstream filevar(filename);
  if(filevar){
    filevar>>size;
    data.resize(size*size);
    // We are filling the matrix by row
    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        filevar>>data[i*size+j];
      }
    }
  }
  filevar.close();
}

/*
Here is a function to write the matrix to a txt file.
We open a file filevar.
First of all I write in the size and then I go to next row
Then I keep writing all the data
*/

template <typename T>
void CMatrix<T>::print_to_file(std::string filename){
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

/* 
Here is a function that tries to print a matrix row by row in a matrix like structure
*/
template <typename T>
void CMatrix<T>::print(){
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      std::cout<<data[size * i + j]<<" ";
    }
    std::cout<<"\n";
  }
}

/*
Now we overload the * operator to perform matrix multplication
*/
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