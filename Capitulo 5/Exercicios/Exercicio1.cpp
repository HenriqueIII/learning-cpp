#include "date.h"
#include <iostream>
#include <cstring>

int main(int argc, char ** argv){
    Date d1("1999-01-01"), d2("1999/01/01"), d3("2000.01.01"), d4("2000-02-01"), d5("2020-12-31");
    Date d6=d5.tomorrow();
    Date d7=d6.yesterday();
    
    d1.displayDate();
    std::cout << " e' " << (d1.isEqual(d2)?"igual a ":"diferente de ");
    d2.displayDate();
    std::cout << std::endl;
    d1.displayDate();
    std::cout << " e' " << (d1.isEqual(d3)?"igual a ":"diferente de ");
    d3.displayDate();
    std::cout << std::endl;
    d1.displayDate();
    std::cout << (d1.isLess(d2)?" e' ":" nao e' ") << "menor que ";
    d2.displayDate();
    std::cout << std::endl;
    d1.displayDate();
    std::cout << (d1.isLess(d3)?" e' ":" nao e' ") << "menor que ";
    d3.displayDate();
    std::cout << std::endl;
    d3.displayDate();
    std::cout << (d3.isLess(d2)?" e' ":" nao e' ") << "menor que ";
    d2.displayDate();
    std::cout << std::endl;
    
    d3.displayDate();
    std::cout << (d3.isLess(d4)?" e' ":" nao e' ") << "menor que ";
    d4.displayDate();
    std::cout << std::endl;

    d4.displayDate();
    std::cout << (d4.isLess(d5)?" e' ":" nao e' ") << "menor que ";
    d5.displayDate();
    std::cout << std::endl;

    d6.displayDate();
    std::cout << std::endl;
    d7.displayDate();
    std::cout << std::endl;
    d2.displayDate();
    std::cout << " - ";
    d3.displayDate();
    std::cout << " =" << d2.subNorm(d3)  << " dias." << std::endl;
    return 0;
}