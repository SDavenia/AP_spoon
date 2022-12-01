#include <iostream>
/*
Write a function that can sum an arbitrary number of arguments using variadic templates.
*/

// First of all let us write a function that sums two elements
template <typename T>
T sumall(T sum){
  std::cout<< __PRETTY_FUNCTION__<<std::endl;
  return sum;
}

// Now we write a function with variadic argument
template <typename T, typename... Args>
T sumall(T sum, const Args&... summands){
  std::cout<< __PRETTY_FUNCTION__<<std::endl;
  return sum + sumall(summands...);
}


int main (int argc, char **argv){
  double result = sumall(6.18,1,4,6);
  std::cout<<result<<std::endl;
  return 0;
}

// By running it using pretty_function we can see that the variadic one is called for the first three times
// and then we call the limit case which also stops it.