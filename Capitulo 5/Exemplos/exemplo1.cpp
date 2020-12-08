#include <iostream>
#include "date.h"
#include <ctime>
//dado o ano, mostrar os meses em que ocorre dia 13 à sexta feira

time_t t = time(0);
struct tm * now = localtime(&t);

Date::getYearToday(){
    return (now->tm_year+1900);
}

Date::getMonthToday(){
    return (now->tm_mon+1);
}

Date::getDayToday(){
    return now->tm_mday;
}

int main(){
    Date dateVect[10];
    int year;
    std::cout << "Qual o ano em que esta interessado? ";
    std::cin >> year;
    Date d(year, 1, 13);
    Date d2("1/1/2001");
    Date d3;
    std::cout << "No ano de " << year << " ocorre sexta feira 13 no(s) mes(es) de: " << std::endl;
    for (int month = 1; month <= 12 ; ++ month){
        d.setMonth(month);
        if (d.getWeekDay() == FRIDAY)
            std::cout << d.getMonthName()<<' ';
    }
    d.setMonth(1);
    d.setDay(1);
    std::cout << "data: " << d2.getNormDate() << std::endl;
    std::cout << "data 3: " << d3.getNormDate() << std::endl;
    for (int i=0; i<10; std::cout << "Data " << i << " : " << dateVect[i++].getNormDate() << std::endl);
}
