#include "Time.h"
#include <iostream>

int main(int argc, char ** argv){
    Time t1(long(21863)), t2(2, 67, 78), t3, t4("00:00:00");
    std::cout << "t1(long(21863)): ";
    t1.printOn();
    std::cout << "t2(2, 67, 78): ";
    t2.printOn();
    std::cout << "t3: ";
    t3.printOn();
    std::cout << "t4(\"00:00:00\"): ";
    t4.printOn();
    std::cout << "t4.setSecond(65): ";
    t4.setSecond(65);
    t4.printOn();
    std::cout << "t4.setMinute(60): ";
    t4.setMinute(60);
    t4.printOn();
    std::cout << "t4.setHour(25): ";
    t4.setHour(25);
    t4.printOn();
    std::cout << "t4.isEqual(t1): ";
    std::cout << (t4.isEqual(t1)?"True":"False") << std::endl;
    std::cout << "t4.setTime(\"0:0:0\"): ";
    t4.setTime("0:0:0");
    t4.printOn();
    std::cout << "t4.isEqual(t1): ";
    std::cout << (t4.isEqual(t1)?"True":"False") << std::endl;
    std::cout << "t4.setSecond(21863): ";
    t4.setSecond(21863);
    t4.printOn();
    std::cout << "t4.isLessThan(t3): ";
    std::cout << (t4.isLessThan(t3)?"True":"False") << std::endl;
    std::cout << "t4.isLessThan(t2): ";
    std::cout << (t4.isLessThan(t2)?"True":"False") << std::endl;
    std::cout << "t4.isLessThan(t1): ";
    std::cout << (t4.isLessThan(t1)?"True":"False") << std::endl;
    std::cout << "t4.theTimeBetween(t1): ";
    std::cout << t4.theTimeBetween(t1) << std::endl;
    std::cout << "t4.theTimeBetween(t2): ";
    std::cout << t4.theTimeBetween(t2) << std::endl;
    std::cout << "t4.theTimeBetween(t3): ";
    std::cout << t4.theTimeBetween(t3) << std::endl;
    return 0;
}