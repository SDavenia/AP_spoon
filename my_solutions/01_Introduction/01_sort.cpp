/*
Write a program that asks the user to fill in a small array, then sort it by whatever way you can think of and print the result on the screen.
*/
#include <iostream>
#include <utility>
int main()
{
    const int n{10};
    int arr[n];
    int change{1}; // To indicate whether we moved items in the array
    std::cout << "insert 10 elements in this array" << std::endl;
    for(int i = 0; i < n; i++)
        std::cin>>arr[i];
    std::cout << "Your array contains" << std::endl;
    for(int i = 0; i < n; i++)
        std::cout<<arr[i]<<" ";
    std::cout<<""<<std::endl;
    std::cout << "Now I sort them in increasing order" << std::endl;
    while (change == 1){
        change = 0;
        for(int i = 0; i < n-1; i++){
            if(arr[i] > arr[i+1]){
                change = 1;
                std::swap(arr[i], arr[i+1]);
            }

        }
    }
    for(int i = 0; i < n; i++)
        std::cout<<arr[i]<<" ";
    std::cout<<""<<std::endl;

}