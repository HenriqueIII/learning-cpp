#include <iostream>
#include "date.h"
//dado o ano, mostrar os meses em que ocorre dia 13 à sexta feira

int main(){
    int year;
    std::cout << "Qual o ano em que esta interessado? ";
    std::cin >> year;
    Date d(year, 1, 13);
    Date d2("1/1/2001");
    std::cout << "No ano de " << year << " ocorre sexta feira 13 no(s) mes(es) de: " << std::endl;
    for (int month = 1; month <= 12 ; ++ month){
        d.setMonth(month);
        if (d.getWeekDay() == FRIDAY)
            std::cout << d.getMonthName()<<' ';
    }
    d.setMonth(1);
    d.setDay(1);
    std::cout << "data: " << d2.getNormDate();
}
