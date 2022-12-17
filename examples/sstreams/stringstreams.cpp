#include <string>
#include <sstream> //stingstreams
#include <iostream>

int main(){
    int a{90};
    // We initialize a ostringstream object ss
    std::ostringstream ss;
    // We add some objects to the stream
    ss<<a<<" + " <<a;


    //Here we extract the string from the stream!
    std::string s=ss.str();
    std::cout<<s<<std::endl;
    
    // Here we construct an istringstream object ss2 and we initialize it to the content of s
    // It is the corresponding of ostringstream
    std::istringstream ss2(s);
    int n;
 
    // Stream a number till white space is encountered
    ss2 >> n;
 
    // Print the number
    std::cout << n << std::endl;
}
