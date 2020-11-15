#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    unsigned int num;
    cout << "Insira um numero inteiro positivo: "<<endl;
    cin >> num;

    for (int i=3; i<=7; i+=2)
        if (num % i == 0)
            cout << num << " e divisivel por " << i << endl;
        else
            cout << num << " divido por " << i << " da resto " << (num % i) << "." << endl;
    return 0;
}
