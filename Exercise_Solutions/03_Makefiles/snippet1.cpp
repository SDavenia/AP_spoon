#include <iostream>
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


// The error here is that class is not defined