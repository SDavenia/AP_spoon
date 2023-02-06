#include <array>
#include <iostream>

template <int N>
void change_arr_element(std::array<int, N>& arr, const int& i){
    arr[i] = 3;
}

int main()
{
    std::array<int, 5> arr;
    for (int i = 0; i < arr.size(); i++){
        arr[i] = i;
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
    change_arr_element<arr.size()>(arr, 2);
    for(int i = 0; i < arr.size(); i++)
        std::cout<<arr[i]<<" ";

}