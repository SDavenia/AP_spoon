/*
Write a square matrix class that:

    uses std::vector to store the data
    is templated on the type of the data
    can read/write a matrix to/from file
    has operator * overloaded
    You main function should look similar to
*/
#include <vector>
#include <iostream>
#include <cstring>

template <typename T>
class CMatrix{
    int size;
public:
    std::vector<T> data;
    // Constructor specified with N elements, allocates a sufficient amount of memory.
    CMatrix(int N){
        size = N;
        data.resize(N*N);
    }
    //template <typename O>
    // friend std::ostream& operator<<(std::ostream os, const CMatrix<O>& c);
    void print_matrix() const;
    void read_from_file(std::string);
    void print_to_file(std::string) const;
};

int main(){
    CMatrix<double> A(3);
    A.print_matrix();
  //CMatrix<double> A,B;
  //A.read_from_file("A.txt");
  //B.read_from_file("B.txt");
  //auto C=A*B;
  //C.print_to_file("C.txt");
}

template <typename T>
void CMatrix<T>::print_matrix() const{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout<<data[j + i*size]<<" ";
        }
        std::cout<<""<<std::endl;
    }
}


/*
template <typename O>
std::ostream& operator<<(std::ostream os, const CMatrix<O>& c){
    for(int i = 0; i < c.size; i++){
        for(int j = 0; j < c.size; j++){
            os<<c.data[j+i*c.size()];
        }
        os<<std::endl;
    }
    return os;
}
*/