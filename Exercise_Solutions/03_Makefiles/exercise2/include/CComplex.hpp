#include <iostream>
struct CComplex
{
    double real;
    double im;

public:
    //Default constructor
    CComplex(){
        real = 0; im = 0;
    }
    //Coordinator with two inputs
    CComplex(double x, double y){
        real = x;
        im = y;
    }

    // Definition of a function to print the imaginary number
    void print();

    // Overloading arithmetic operators
    CComplex operator+(const CComplex& b){
        CComplex result;
        result.real = real + b.real;
        result.im = im + b.im; 
        return result;
    }
    CComplex operator-(const CComplex& b){
        CComplex result;
        result.real = real - b.real;
        result.im = im - b.im; 
        return result;
    }

    CComplex operator*(const CComplex& b){
        CComplex result;
        result.real = real * b.real - im * b.im;
        result.im = real * b.im + b.real * im;
        return result;
    }

    CComplex operator/(const CComplex& b){
        CComplex result;
        result.real = (b.real * real + b.im * im) / (b.real * b.real + b.im * b.im);
        result.im = (b.real * im - b.im * real) / (b.real * b.real + b.im * b.im);
        return result;
    }

    // Now we need to overload the operator <<
    friend std::ostream& operator<<(std::ostream&os, const CComplex& c);

};


