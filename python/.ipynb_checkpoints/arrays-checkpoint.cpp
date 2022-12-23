
#include <iostream>

extern "C"{
    int* create_array(int N) {
        int* arr = new int[N];
        return arr;
    }

    void do_something_with_array(int* arr,int N){
        for(int i=0;i<N;i++){
            arr[i]=i;
            std::cout<<arr[i];
        }
        std::cout<<std::endl;
    }
    
    void delete_array(int* arr) {
        delete[] arr;
    }
}
