#include "Point.h"
#include "Random.h"
#include <iostream>
#include "Display.h"

int main(int argc, char ** argv){
    Point a(10,20), b;
    b = a.add(Point(15, 5));
    Random::init();
    std::cout << "b: (" << b.getX() << "," << b.getY() << ")\n";
    Point c = Random::get(Point(0,0),Point(79,49));
    std::cout << "c: (" << c.getX() << "," << c.getY() << ")\n";
    return 0;
}