/*
Instead of reading the matrix from a file, get the matrix size from the command line parameters and use the random_fill function 
  provided in the lecture to fill in a large matrix (around a 1000). 
Add the timing to the matrix multiplication program (you can use the easier version of it, the one with std::vector). 

Extra exercsise for those who managed to either install openblas or can find that module on some cluster: 
   add the call to the cblas_dgemm function like in the matrix_cblas.cpp example and compare the timings.
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <chrono>
#include <algorithm>
#include <type_traits>
#include <cstdlib>
#include </Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks/Accelerate.framework/Versions/Current/Frameworks/vecLib.framework/Headers/cblas.h>//to call cblas_dgemm to compare results
// Remember to compile with flag -framework Accelerate


template <typename T>
class CMatrix{
    int size; // should not be modifiable
public:
    // Default constructor initializes a 2x2 matrix
    CMatrix(){
        size = 2;
        data.resize(4);
    }
    std::vector<T> data;
    // Constructor specified with N elements, allocates a sufficient amount of memory.
    CMatrix(const int N){
        size = N;
        data.resize(N*N);
    }
    void print_matrix() const;

    void random_fill();


    //void read_from_file(std::string filename);
    void print_to_file(std::string filename) const;

    // Need to overload the multiplication operator, can make it const
    CMatrix operator*(const CMatrix& B) const;

    template <typename O>
    friend std::ostream& operator<<(std::ostream& os, const CMatrix<O>& A);
};

int main(int argc, char* argv[]){
    if(argc < 2){
        std::cout<<"USAGE: "<<argv[0]<<"number"<<std::endl;
        return 0;
    }
    int N = atoi(argv[1]);

    CMatrix<double> A(atoi(argv[1]));
    CMatrix<double> B(atoi(argv[1]));
    A.random_fill();
    B.random_fill();
    auto t_start = std::chrono::steady_clock::now();
    auto C=A*B;
    auto t_end = std::chrono::steady_clock::now();
    auto total = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
    std::cout<<"It took "<<total<<" milliseconds."<<std::endl;

    auto t_start1 = std::chrono::steady_clock::now();
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N,N,N,1,&A.data[0],N,&B.data[0],N,0,&C.data[0],N);
    auto t_end1 = std::chrono::steady_clock::now();
    auto total1 = std::chrono::duration_cast<std::chrono::milliseconds>(t_end1 - t_start1).count();
    std::cout<<"It took "<<total1<<" milliseconds with cblas."<<std::endl;
    //std::cout<<C;
    //C.print_to_file("C.txt");
    return 0;
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
template <typename T>
void CMatrix<T>::read_from_file(std::string filename){
    std::ifstream filevar(filename);
    filevar >> size;
    int n_elements = size * size;
    data.resize(n_elements);
    for (int i = 0; i < n_elements; i++){
        filevar>>data[i];
    }
    filevar.close();
}
*/
template <typename T>
void CMatrix<T>::random_fill(){
	constexpr auto low_bound = 0;
	constexpr auto up_bound = 100;
    //take the seed from current time 
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine dre(seed);//engine
    std::uniform_int_distribution<int> di(low_bound,up_bound);//distribution
    std::generate(data.begin(), data.end(), [&](){ return di(dre);});//fill
};


template <typename T>
void CMatrix<T>::print_to_file(std::string filename) const{
    std::ofstream filevar(filename);
    filevar << size << std::endl;
    int n_elements = size*size;
    for (int i = 0; i < n_elements; i++){
        filevar << data[i] << " ";
        if ((i+1)%3 == 0)
            filevar << std::endl;
    }
    filevar.close();
}

template <typename T>
CMatrix<T> CMatrix<T>::operator*(const CMatrix<T>& B) const{
    if(size != B.size){
        std::cout<<"Can't perform matrix multiplication on square matrices of different sizes"<<std::endl;
        return 0;
    }
    CMatrix<T> C(size);
    T sum;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            sum = 0;
            for(int k = 0; k < size; k++){
                sum += data[k + i*size] * B.data[j + k*size];
            }
            C.data[j + i*size] = sum;
        }

    }
    return C;
}


template <typename O>
std::ostream& operator<<(std::ostream& os, const CMatrix<O>& A){
    for(int i = 0; i < A.size; i++){
        for(int j = 0; j < A.size; j++){
            os<<A.data[j+i*A.size]<<" ";
        }
        os<<std::endl;
    }
    return os;
}