#include <iostream>

class Circle{
    const double x, y;
    double radius;
public:
    Circle( double xC, double yC, double r)
    :x(xC), y(yC){
        radius = r;
    }
    double getArea() const{
        return 3.14159 * radius * radius;
    }
    double getRadius() const{
        return radius;
    }
    void setRadius(double r){
        radius = r;
    }
};

int main(){
    Circle c1(0,0,1);
    std::cout << "O circulo de raio \"" << c1.getRadius() << "\" tem uma area de " << c1.getArea() << " cm2." << std::endl;
    c1.setRadius(3.14159);
    std::cout << "O circulo de raio \"" << c1.getRadius() << "\" tem uma area de " << c1.getArea() << " cm2." << std::endl;
    return 0;
}
