/*
Create an abstract base class "shape" and inherit 
        classes triangle (should have 3 vectices member variables) 
        and polygon from it (should have a raw pointer to vertices coordinates within to make life harder). 
The classes should have functions to calulate perimeter and to print vertice coordinates that work with runtime polymorhism
*/
#include <iostream>
#include <cmath>
#include <vector>

// I define a class Vertices which stores an x and y coordinate
class CVertex{
    double x, y;
public:
    // Constructors
    CVertex():x(0), y(0){}
    CVertex(double xcord, double ycord): x(xcord), y(ycord){}

    // print vertex function
    void print() const{
        std::cout<<"("<<x<<", "<<y<<")"<<std::endl;
    }

    // Set coordinates
    void set_coords(const double& x0, const double& y0){
      x=x0;
      y=y0;
    }

    // Function to compute euclidean distance between two vertices
    double distance(const CVertex& a) const;

};


// Shape is an abstract class
class Shape{
public:
    virtual void print() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape(){};
};

// Triangle
class Triangle : public Shape{
    CVertex v1, v2, v3;
public:
    // Constructors
    Triangle(): v1(), v2(), v3(){}
    Triangle(CVertex a1, CVertex a2, CVertex a3);
    Triangle(const std::vector<double>& myvertices);
    ~Triangle() override{};
    void print() const override{
        v1.print();
        v2.print();
        v3.print();
    }
    double perimeter() const override{
        double perimeter;
        perimeter = v1.distance(v2) + v1.distance(v3) + v3.distance(v2);
        return perimeter;
    }
};

// Polygon
// number of vertices
class Polygon : public Shape{
    int nV;
    CVertex* vertices;
public:
    // constructors
    Polygon(const std::vector<double>& myvertices);
    // destructor, override the base class one
    ~Polygon(){
      std::cout <<"Polygon destructor called."<<std::endl;
      delete[] vertices;
    }

    void print() const override{
        if(nV < 3){
            std::cout<<"This is not a polygon, you need at least three points"<<std::endl;
        }else{
            for(int i = 0; i < nV; i++){
                vertices[i].print();
            }
        }
    }

    double perimeter() const override;
};

int main()
{
    // Create three vertices
    CVertex a(1, 2);
    CVertex b(2, 3);
    CVertex c(1, 4);
    // Create an object of class triangle using these vertices
    Triangle tr(a, b, c);
    // Print the triangle
    tr.print();
    std::cout<<"The perimeter of the triangle is "<<tr.perimeter()<<std::endl;

    // Now working with the polygon
    std::vector<double> myvertices = {1, 2, 1, 3, 2, 3, 2, 1};
    Polygon poly(myvertices);
    std::cout<<poly.perimeter()<<std::endl;
}


double CVertex::distance(const CVertex& a) const {
    double result;
    result = std::sqrt((a.x - x)*(a.x - x) + (a.y - y)*(a.y - y));
    return result;
}

Triangle::Triangle(CVertex a1, CVertex a2, CVertex a3){
    v1 = a1;
    v2 = a2;
    v3 = a3;
}

Triangle::Triangle(const std::vector<double>& myvertices){
    if (myvertices.size() != 6){
        std::cout<<"This is not a triangle"<<std::endl;
    }else{
        v1.set_coords(myvertices[0],myvertices[1]);
        v2.set_coords(myvertices[2],myvertices[3]);
        v3.set_coords(myvertices[4],myvertices[5]);
    }
}

Polygon::Polygon(const std::vector<double>& myvertices){
    nV = myvertices.size()/2; //since in the vector we store x and y coordinates
    vertices = new CVertex[nV];
    for(int i = 0; i < nV; i++){
        vertices[i].set_coords(myvertices[2*i], myvertices[2*i+1]);
    }
}

double Polygon::perimeter() const{
    double perimeter;
    // Distance between first and last point
    perimeter += vertices[0].distance(vertices[nV-1]);

    // Distance among all other consecutive points
    for(int i = 0; i < (nV-1); i++){
        perimeter += vertices[i].distance(vertices[i + 1]);
    }
    return perimeter;
}

