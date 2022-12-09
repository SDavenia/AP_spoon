/*
Write a function that can sum an arbitrary number of arguments using variadic templates.
*/
#include <iostream>
template <typename T>
T sumall(T sum){
  std::cout<<"Calling the standard one"<<std::endl;
  return sum;
}

template <typename T, typename... Types>
T sumall(T sum, const Types&... summands){
  std::cout<<"Calling the ... one"<<std::endl;
  return sum + sumall(summands...);
}


int main (int argc, char **argv){
  double result = sumall(6.18,1,4,6);
  std::cout<<result<<std::endl;
  return 0;
}


