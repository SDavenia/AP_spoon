#include <iostream>
#include <cmath>
#include <vector>
/*
Create an abstract base class "shape" and inherit classes 
    - triangle (should have 3 vectices member variables) 
    - polygon from it(should have a raw pointer to vertices coordinates within to make life harder). 
The classes should have functions to calulate perimeter and to print vertice coordinates that work with runtime polymorhism.
*/

/*
I will define a class template coordinates to store coordinates in R2
*/
template <typename T>
class CCoordinates{
    T x;
    T y;
public:
    CCoordinates(){
        std::cout<<"default constructor"<<std::endl;
        x = 0;
        y = 0;
    };
    CCoordinates(T n1, T n2): x(n1), y(n2){}
    void set_coords(T n1, T n2){
        x = n1;
        y = n2;
    }
    void print_coords(){
        std::cout<<"("<<x<<", "<<y<<")"<<std::endl;
    }

    double distance(const CCoordinates& a) const;
};

/*
Now I define an abstract class Shape and its inherited classess triangle and polygon
*/
template <typename T>
class CShape{
public:
    virtual void print_vertices() = 0;
    virtual T perimeter() = 0;
    // Need virtual destructor cause polygon has dynamically allocated memory, so need to define a manual destructor
    //  since it is inherited I need the base destructor to be virtual otherwise issues when working with pointers to base class.
    virtual ~CShape(){
        std::cout<<"Shape destructor"<<std::endl;
    }; 
};

template <typename T>
class CTriangle: public CShape<T>{
public:
    ~CTriangle() override{
        std::cout<<"Triangle destructor"<<std::endl;
    }
    CCoordinates<T> p1,p2,p3;
    CTriangle(const std::vector<double>& myvertices);
    void print_vertices() override;
    T perimeter() override;
};


template <typename T>
class CPolygon: public CShape<T>{
    int nV; // Number of vertices
    CCoordinates<T>* myvertices;
public:
    // Constructors
    CPolygon(){
        std::cout<<"Default constructor"<<std::endl;
        nV = 0;
        myvertices = nullptr;
    }
    CPolygon(const std::vector<double>& a);
    void print_vertices() override;
    T perimeter() override;
    // Destructor
    ~CPolygon(){
        std::cout<<"Polygon destructor"<<std::endl;
        delete[] myvertices;
        myvertices = nullptr;
    }
    
};


int main(){
    /*
    CCoordinates<double> a(3, 2);
    a.print_coords();

    CCoordinates<double> b;
    b.print_coords();

    std::cout<<a.distance(b)<<std::endl;

    std::vector<double> vec={1, 2, 3, 4, 5, 6};
    CTriangle<double> c(vec);
    c.print_vertices();
    std::cout<<c.perimeter()<<std::endl;
    */

    std::vector<double> vec2 = {1, 2, 3, 4, 5, 6, 7, 8};
    CPolygon<double> d(vec2);

    CPolygon<double> e;
    //d.print_vertices();
}


template <typename T>
double CCoordinates<T>::distance(const CCoordinates& a) const {
    double result;
    result = std::sqrt((a.x - x)*(a.x - x) + (a.y - y)*(a.y - y));
    return result;
}


template <typename T>
CTriangle<T>::CTriangle(const std::vector<double>& myvertices){
    if (myvertices.size() == 6) {
        p1.set_coords(myvertices[0],myvertices[1]);
        p2.set_coords(myvertices[2],myvertices[3]);
        p3.set_coords(myvertices[4],myvertices[5]);
    } else{
        std::cout << "This is not a triangle! Use polygon instead." << std::endl; exit(1);
    }
}

template <typename T>
void CTriangle<T>::print_vertices(){
    p1.print_coords(); // We only need this to access members, not their functions (??)
    p2.print_coords();
    p3.print_coords();
}


template <typename T>
T CTriangle<T>::perimeter(){
    T perimeter;
    perimeter = p1.distance(p2) + p1.distance(p3) + p2.distance(p3);
    return perimeter;
}

template <typename T>
CPolygon<T>::CPolygon(const std::vector<double>& a){
    nV = a.size()/2;
    std::cout<<"Allocating memory"<<std::endl;
    myvertices = new CCoordinates<T>[nV]; // array of polygons
    for(int i = 0; i < nV; i++){
        myvertices[i].set_coords(a[2*i], a[2*(i+1)]);
    }
}

template <typename T>
void CPolygon<T>::print_vertices(){
    for(int i = 0; i < nV; i++){
        myvertices[i].print_coords();
    }
}

template <typename T>
T CPolygon<T>::perimeter(){
    T perimeter;
    for (int i = 0; i < (nV -1); i++){
        for (int j = i+1; j < nV; j++){
            perimeter += myvertices[i].distance(myvertices[j]);
        }
    }
    return perimeter;
}