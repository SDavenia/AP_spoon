/*
 1) Create a mesh to store an evenly spaced 2-dimensional grid (in an std::vector). Leave space for the boundaries as they do not belong
 2) Setup the initial constant boundary condition: the lower left hand corner is fixed at 100 and see gradient up to 0
 3) Setup the initial condition of the inner grid elements to 0.5
 4) Write a solver class that will have the jacobi method. At each iteration you need to recomputed from the elements of the current iteration
*/

#include <iostream>
#include <vector>

template <typename T>
class CMesh{
    int N; // to store the size of the mesh
    std::vector<T> data;
public:
    CMesh(const int size){
        N = size;
        data.resize((N+2)*(N+2)); // since we need to include the boundary
        initialize();
    }

    void initialize();

    void print_all(); // prints the whole mesh including the boundary.
    void print();     // prints the mesh internal bit only.

    void step(const int& niter);
};

template <typename T>
class CSolver{
public:
    void jacobi(CMesh<T>& mesh, const int& steps){
        mesh.step(steps);
    }
};



int main(){
    CMesh<double> mesh1(9);
    //mesh1.print_all();
    CSolver<double> solve;
    solve.jacobi(mesh1, 1000);
    mesh1.print_all();

}


template <typename T>
void CMesh<T>::print_all(){
    for(int i = 0; i < (N+2); i++){
        for(int j = 0; j < (N+2); j++){
            std::cout<<data[j + i * (N+2)]<<" ";
        }
        std::cout<<"\n";
    }
}

template <typename T>
void CMesh<T>::print(){
    for(int i = 1; i < (N+1); i++){
        for(int j = 1; j < (N+1); j++){
            std::cout<<data[j + i * (N+2)]<<" ";
        }
        std::cout<<"\n";
    }
}

// Initialize the boundary condition and the matrix of interest.
template <typename T>
void CMesh<T>::initialize(){
    data[(N+2)*(N+2) - (N+2)] = 100;
    for(int i = 1; i < (N+1); i++){
        data[i*(N+2)] = i* ((T)100 / (T)(N+1));
        data[(N+2)*(N+2) - (i+1)] = i* ((T)100 / (T)(N+1));
        for(int j = 1; j < (N+1); j++){
            data[j + i * (N+2)] = 0.5;
        }
    }
}


/*
First of all we need to count the number of neighbours for each cell and store them in another vector
then we can update the matrix.
*/
template <typename T>
void CMesh<T>::step(const int& niter){
    int k = 0;
    std::vector<T> new_mesh;
    new_mesh.resize((N+2)*(N+2));
    while(k < niter){
        for(int i = 1; i < (N+1); i++){
            for(int j = 1; j < (N+1); j++){
                new_mesh[j + i*(N+2)] = (data[j + (i+1)*(N+2)] + data[j + (i-1)*(N+2)] + data[j+1 + i*(N+2)] + data[j-1 + i*(N+2)])*0.25;
            }
        }
    // Now we move them in a new matrix.
    for(int i = 1; i < (N+1); i++){
        for(int j = 1; j <(N+1); j++){
            data[j + i*(N+2)] = new_mesh[j + i*(N+2)];
        }
    }
    k++;
    }

}