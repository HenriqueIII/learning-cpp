#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctype.h>
using namespace std;

int main(){
    cout << "Pense um numero de 0 a 7 e prima uma tecla.";
    cin.get();

    int number = 0;

    for (int i = 4; i > 0; i /= 2){
        char ch;
        cout << "\nE maior ou igual a " << i+number << " (S/N)?";
        cin >> ch;
        if (toupper(ch) == 'S')
                number += i;
    }
    cout << "\nO numero que pensou e " << number << "." << endl;
    return 0;
}
