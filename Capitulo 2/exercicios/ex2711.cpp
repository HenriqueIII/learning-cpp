#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    unsigned long int num1, num2, maxdiv;
    cout << "Insira dois numeros inteiros positivo: "<<endl;
    cin >> num1 >> num2;

    if(num1 > num2){
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    do{
        maxdiv=num1%num2;
        num1=num2;
        num2=maxdiv;
    }while(maxdiv != 0);

    cout << num1 << " e o maior divisor comum" << endl ;
    return 0;
}
