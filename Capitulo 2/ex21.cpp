#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctype.h>
using namespace std;

int main(){
    unsigned long n, max = 1, number =0;
    char ch;
    cout << "Quer que eu adivinhe numeros desde 0 ate quanto?";
    cin >> n;

    do{
        max*=2;
    }while(max < n);

    for (unsigned long i = max/2; i > 0; i /= 2){
        char ch;
        cout << "\nE maior ou igual a " << i+number << " (S/N)?";
        cin >> ch;
        if (toupper(ch) == 'S')
                number += i;
    }
    cout << "\nO numero que pensou e " << number << "." << endl;
    return 0;
}
