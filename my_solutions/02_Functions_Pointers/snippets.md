### snippet 1
void add_two(int* a){
    a=a+2;
}
int main(){
    int var{0};
    add_two(&var);
    std::cout<<var<<std::endl;
    return 0;
}
We pass the argument a to function add_two as a pointer. This means that in order to access its value we need to dereference a inside the function, which is not done here.
A possible fix is to add the dereferencing operator or alternatively to pass a by reference to the function (if we do this there is no need to call the function using & in the main).
Here are these two possible fixes:

void add_two(int* a){
    *a=*a+2;
}
int main(){
    int var{0};
    add_two(&var);
    std::cout<<var<<std::endl;
    return 0;
}
void add_two(int& a){
    a=a+2;
}
int main(){
    int var{0};
    add_two(var);
    std::cout<<var<<std::endl;
    return 0;
}

### snippet 2
void swap(int a, int b){
   int temp{a};
   a=b;
   b=a; 
}
int main(){
   int var1{8}, var2{9};
   swap(var1,var2);
   std::cout<<var1<<" "<<var2<<std::endl;
   return 0;
}
There are two main mistakes in this code.
The first one is that we need to assign b to temp and not to a otherwise we end up with the same value twice.
The other is that this function does not actually swap the values of a and b, as they are passed by value to the function. 
In order to let the function alter them they need to be passed by pointer or by reference. The latter is preferrable in c++.
A possible solution using passing by reference is as follows:

void swap(int& a, int& b){
   int temp{a};
   a=b;
   b=temp; 
}
int main(){
   int var1{8}, var2{9};
   swap(var1,var2);
   std::cout<<var1<<" "<<var2<<std::endl;
   return 0;
}

### snippet 3
class CMyClass{
    int a;
    CMyClass(int x):a(x){};
}

int main(){
   CMyClass c(7);
   std::cout<<"this won't work"<<std::endl;
   return 0;
}
The first mistake is that there is a semicolon missing after the class definition.
The other problem is that we have defined the constructor CMyCass(int x) as a private member function (by default all members inside class are private in c++).
A possible solution retaining a as a private member of the class is as follows:

class CMyClass{
    int a;
public:
    CMyClass(int x):a(x){};
}

int main(){
   CMyClass c(7);
   std::cout<<"this will work"<<std::endl;
   return 0;
}

### snippet 4
int main(){
    int x = 4;
    int& y;
}
This code is wrong because references have to be initialized when they are created, and this is not done with y.
We can alter this code to make it work as follows:
int main(){
    int x = 4;
    int& y{x};
}