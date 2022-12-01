#include <iostream>
/* Write a recursive function to print an array */

// Print a function which takes an array (or a pointer we can also write int* arr)
void print_array_recursive(int arr[], int size){
    if (size == 0)
        return;
    std::cout<<*arr;
    print_array_recursive(arr+1, --size);
}


int main(){
    int a[5] = {1, 2, 3, 4, 5};
    int* point = a;
    // Equivalent if we use point (pointer) or array.
    print_array_recursive(point, 5);
}
