#include <iostream>
class CComplex{
public:
    double re, im; // To store real and imaginary part
    CComplex():re(0), im(0){}
    CComplex(int real, int imaginary): re(real), im(imaginary){}

    void assign(int real, int imaginary){ //const here would not compiler
        re = real;
        im = imaginary;
    }
    void print() const{
        std::cout<<re<<" + "<<im<<"i "<<std::endl;
    }
};

int main(){
    CComplex a{2, 3};
    a.print();
    a.assign(1, 2);
    a.print();
    const CComplex b{2, 3};
    b.print();
    //b.assign(2, 3); does not compile, error
    
}