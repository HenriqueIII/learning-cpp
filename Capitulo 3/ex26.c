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

    ofstream birthdays("birthdays.dat", ios::binary);

    if (!birthdays){
        cout << "Error opening birthdays" <<  endl; return;
    }

    do{
        PersonBirthday b;
        cout << "Nome - "; cin.getline(b.name, MAX_NAME);
        cout << "Data de Nascimento(dia mes ano) - ";
        cin >> b.day >> b.month >> b.year;

        if (b.month > 0 && b.month <= 12 && b.day > 0 && b.day <= (daysOfMonth[b.month - 1] + (b.month == 2 && (!(b.year%400) || !(b.year%4) && b.year%100)))){
            birthdays.write((unsigned char *) & b, sizeof b);
        }else{
            cout << "Data Invalida" << endl;
        }
        cout << "Quer introduzir mais aniversarios (S/N)? ";
        cin >> ch;
        cin.ignore(MAX_IGNORE, '\n');
    }while(toupper(ch) == 'S');

    return 0;
}
