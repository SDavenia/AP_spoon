### Snippet 1
CCoords CCoords::operator+(const int& b) {
        CCoords result;
        result.x = x + b;
        result.y = y + b;
        return result;
    }
int main(){
    CCoords c;
    c.x=0;c.y=3;
    auto cc=2+c;
}

This is wrong as this function is not a member function of the class CCoords but it is a friend function. As such we need to pass an object of class CCoords as well.
We also need to ensure that the order is correct, so since in the main we are calling int + CCoords we can correct this as follows:

CCoords CCoords::operator+(const int& b, const CCoords& c) {
        CCoords result;
        result.x = c.x + b;
        result.y = c.y + b;
        return result;
    }
int main(){
    CCoords c;
    c.x=0;c.y=3;
    auto cc=2+c;
}

### Snippet 2
class MyClass{
  int x;
  MyClass():x(0){};
}
std::ostream& operator<<(std::ostream& os, const MyClass& m){
    os<<m.x<<std::endl;
    return os;
};
int main(){
    MyClass m;
    std::cout<<m<<std::endl;
}
First of all there is a semicolon missing after the class declaration.
We are unable to call the constructor as it has been made private, so we need to make it public.
The overloaded operator << has not been made friend of the class MyClass, meaning we would be unable to access the private member variables (such as x here) of the class.
class MyClass{
  int x;
  friend std::ostream& operator<<(std::ostream& os, const MyClass& m);
public:
  MyClass():x(0){};

};
std::ostream& operator<<(std::ostream& os, const MyClass& m){
    os<<m.x<<std::endl;
    return os;
};
int main(){
    MyClass m;
    std::cout<<m<<std::endl;
}

### Snippet 3
int result;
for(int i=0;i<N;i++){
   result=calculate_result();  //valid function defined somewhere else
   std::ofstream filevar("results.txt");
   filevar<<result<<std::endl;
   filvar.close();
}
First of all we should always check if the file that we are opening does exist.
Moreover, we are overwriting the same file at every iteration of the loop, this makes no sense as it would just be sufficient to call it once on the last iteration.
Assuming that we want to append the results in the same file we can re-write this code as follows (assuming the file test.txt already exists):

int result;
filevar.open("test.txt", std::ios_base::app);
for(int i=0;i<N;i++){
   result=calculate_result();  //valid function defined somewhere else
   filevar<<result<<std::endl;
}
filevar.close();

