#include <fstream>
#include <iostream>
#include <ctype.h>

const int MAX_NAME = 20, MAX_IGNORE = 256;

struct PersonBirthday{
    char name[MAX_NAME];
    unsigned int day, month, year;
};

using namespace std;

int main(){
    unsigned daysOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char ch;

    ifstream birthdays("birthdays.dat", ios::binary);

    if (!birthdays){
        cout << "Error opening birthdays" <<  endl ;
        return 0;
    }
    PersonBirthday b;
    while(birthdays.read((char*) &b, sizeof b))
        cout << b.name << " " << b.day << "/" << b.month << "/" << b.year << endl;



    return 0;
}
