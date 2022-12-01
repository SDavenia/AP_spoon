#include <iostream>

/* Write a program that asks the user to fill in a small array, then sort it by
    whatever way you can think of and print the result on the screen*/

int main(){
  int n;
  int tmp;
  int moves = 1;

  // Read number of entries in array from user and create empty array
  std::cout<<"Insert the length of your desired array"<<std::endl;
  std::cin>>n;
  int arr[n];

  // Read the entries for the array from user
  std::cout<<"Enter each element of the array one by one:"<<std::endl;
  for (int i = 0; i<n; i++){
    std::cin>>arr[i];
  }

  // Repeat until there is no movement in the array
  while (moves != 0){
    moves = 0;
    for (int i = 0; i < (n-1); i++){
      if (arr[i] > arr[i + 1]){
        tmp = arr[i];
        arr[i] = arr[i+1];
        arr[i + 1] = tmp;
        moves = 1;
      }
    }

  }

  // Print out the sorted array
  std::cout<<"The sorted array is as follows:"<<std::endl;
  for (int i = 0; i < n; i++)
    std::cout << arr[i] << " ";

  std::cout << std::endl;





}
