/*
Time the std::sort with a lambda function and your own sort implementation (there was some in previous exercises)
 when sorting a large vector (large enough to take a few seconds).
*/
#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <algorithm>

void my_sort(std::vector<int> &vec);

int main(){

    const int n{10000};
    // Generate a random vector of size n
    std::vector<int> vec, vec1;
    vec.resize(n);

    constexpr auto low_bound = 0;
    constexpr auto up_bound = 100;
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine dre(seed);
    std::uniform_int_distribution<int> di(low_bound, up_bound);
    std::generate(vec.begin(), vec.end(), [&](){return di(dre);});
    vec1 = vec;

    // Sort using sort
    auto t_start = std::chrono::steady_clock::now();
    std::sort(vec.begin(), vec.end(), [](int x, int y){return x > y;});
    auto t_end = std::chrono::steady_clock::now();
    auto total = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
    std::cout << "It took: "<<total<<" milliseconds to sort using std sort algorithm"<<std::endl;

    // Sort using my implementation of sort
    auto t_start1 = std::chrono::steady_clock::now();
    my_sort(vec1);
    auto t_end1 = std::chrono::steady_clock::now();
    auto total1 = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();
    std::cout << "It took: "<<total1<<" milliseconds to sort using your implementation"<<std::endl;

    /*
    for (int x: vec){
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    for (int x: vec1){
        std::cout<<x<<" ";
    }
    */

}


void my_sort(std::vector<int> &vec){
    int changed = 1;
    while(changed != 0){
        changed = 0;
        for(int i = 0; i < (vec.size() - 1); i++){
            if(vec[i] < vec[i+1]){
                changed = 1;
                std::swap(vec[i], vec[i+1]);
            }
        }
    }
}