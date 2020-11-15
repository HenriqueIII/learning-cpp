#include <iostream>
using namespace std;

int main(){
    int day, month, year, numOfDays;
    cout << "Dia: "; cin >> day;
    cout << "Mês: "; cin >> month;
    cout << "Ano: "; cin >> year;

    if (month >= 1 && month <= 12){
        switch (month){
            case 2: numOfDays = 28 + (!(year%400) || !(year%4) && (year%100));break;
            case 4:
            case 6:
            case 9:
            case 11: numOfDays = 30;break;
            default: numOfDays=31;
        }
    }else{
        numOfDays = 0;
    }

    if (day > 0 && day <= numOfDays){
        cout << "Faltam " << (numOfDays - day) << " dias para o final do mes." << endl;
    }else{
        cout << "Nao e uma data valida" << endl;
    }
}

