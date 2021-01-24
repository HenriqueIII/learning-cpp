#include "DateTime.h"
#include <iostream>
#include <iomanip>

int main(int argc, char ** argv){
    DateTime dt1("2001-03-03@00:00:00"), dt2("2001-04-03@00:00:00"), dt3("2001-04-03@00:00:00");
    DateTime dt4("2000-06-03@00:00:00"), dt5("2001-03-02@00:00:00"), dt6("2001-03-05@00:00:00");
    DateTime dt7("2000-01-01@00:00:00"), dt8("2000-01-01@00:00:00"), dt9("2000-01-01@00:00:00");
    DateTime * dtarr[] = {&dt1,&dt3,&dt4,&dt5,&dt6};

    for(int i=0;i<5;i++){
        dtarr[i]->theTimeBetween(dt2).printOn();
        std::cout << "\n";
    }
    return 0;
}