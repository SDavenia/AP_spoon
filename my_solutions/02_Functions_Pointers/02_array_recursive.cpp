/*
Write a recursive function to print an array.
*/
#include <iostream>
void print_recursive(int* arr, int N){
    if(N == 1)
        std::cout<<arr[0]<<std::endl;
    else{
        std::cout<<arr[0]<<" ";
        print_recursive(arr+1, N-1);
    }
    
}

int main(){
    const int n{5};
    int arr[n] = {1, 2, 3, 4, 5};
    print_recursive(arr, n);

}