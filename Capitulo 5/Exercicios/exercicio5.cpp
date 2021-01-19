#include "DateTime.h"
#include <iostream>

int main(int argc, char ** argv){
    DateTime dt1, dt2(1999,2,3,1,2,3), dt3("2000-02-29@10:30:00"), dt4("2001-08-31@12:45:00"), dt7(1999,2,3,1,2,3), dt8("0000-00-00@00:00:00");
    Date d1(long(1600));
    d1.displayDate();
    std::cout << std::endl;
    dt1.printOn();
    std::cout << std::endl;
    dt2.printOn();
    std::cout << std::endl;
    dt3.printOn();
    std::cout << std::endl;
    dt4.printOn();
    std::cout << std::endl;
    DateTime dt5(dt3.getData(),dt4.getTime());
    dt5.printOn();
    std::cout << std::endl;
    DateTime dt6(Date(0,0,0), Time());
    dt6.printOn();
    std::cout << std::endl;
    dt8.getData().setYear(0);
    dt8.getData().setMonth(0);
    dt8.getData().setDay(0);
    dt8.printOn();
    std::cout << std::endl << std::endl << "Comparações" << std::endl; 
    std::cout << "----------------------------" << std::endl;
    dt1.printOn();
    std::cout << (dt1.isEqual(dt2)?" e ": " nao e ") << "igual a ";
    dt2.printOn();
    std::cout << std::endl;
    dt2.printOn();
    std::cout << (dt2.isEqual(dt7)?" e ": " nao e ") << "igual a ";
    dt7.printOn();
    std::cout << std::endl;
    dt3.printOn();
    std::cout <<" e "<< (dt3.isLess(dt4)?" menor ": " maior ");
    dt4.printOn();
    std::cout << std::endl;
    dt3.printOn();
    std::cout <<" e "<< (dt3.isLess(dt5)?" menor ": " maior ");
    dt5.printOn();
    std::cout << std::endl;
    dt3.printOn();
    std::cout <<" e "<< (dt3.isLess(dt2)?" menor ": " maior ");
    dt2.printOn();
    std::cout << std::endl;
    dt3.printOn();
    std::cout << " - ";
    dt4.printOn();
    std::cout << " = ";
    dt3.theTimeBetween(dt4).printOn();
    std::cout << std::endl;
    dt1.printOn();
    std::cout << " - ";
    dt3.printOn();
    std::cout << " = ";
    dt1.theTimeBetween(dt3).printOn();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    //data igual, hora maior
    DateTime dt9("2000-01-01@00:00:00"), dt10("2000-01-01@01:00:00"); //bug, 31 dias quando devia ser 0
    dt10.printOn(); //Tambem deveria ter 1 hora de diferença mas tem 0
    std::cout << " - ";
    dt9.printOn();
    std::cout << " = ";
    dt10.theTimeBetween(dt9).printOn();
    std::cout << std::endl;
    //data igual, hora igual
    dt10.setTime(Time("00:00:00")); //bug, 31 dias, deveria ser 0 dias;
    dt10.printOn();
    std::cout << " - ";
    dt9.printOn();
    std::cout << " = ";
    dt10.theTimeBetween(dt9).printOn();
    std::cout << std::endl;
    //data maior, hora igual
    dt9.setData(Date("2000-02-01")); //bug, 0 dias, deveria ser 31    
    dt10.printOn();
    std::cout << " - ";
    dt9.printOn();
    std::cout << " = ";
    dt10.theTimeBetween(dt9).printOn();
    std::cout << std::endl;
    std::cout << std::endl;
    //trocar testes
    //data igual, hora maior
    DateTime dt11("2000-01-01@01:00:00"), dt12("2000-01-01@00:00:00"); // hora funciona 
    dt12.printOn(); // Retorna 31 dias devia ser 0
    std::cout << " - ";
    dt11.printOn();
    std::cout << " = ";
    dt12.theTimeBetween(dt11).printOn();
    std::cout << std::endl;
    //data igual, hora igual
    dt11.setTime(Time("00:00:00")); //retorna 31 dias, deveria ser 0
    dt12.printOn();
    std::cout << " - ";
    dt11.printOn();
    std::cout << " = ";
    dt12.theTimeBetween(dt11).printOn();
    std::cout << std::endl;
    //data maior, hora igual
    dt12.setData(Date("2000-02-01")); //retorna 0 dias, devia ser 31     
    dt12.printOn();
    std::cout << " - ";
    dt11.printOn();
    std::cout << " = ";
    dt12.theTimeBetween(dt11).printOn();
    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}