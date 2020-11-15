#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    unsigned numberOfChars = 0;
    cout << "Insira uma linha de texto: " << endl;
    while (cin.get() != '\n')
        ++numberOfChars;
    cout << "\nDigitou " << numberOfChars << " caracter" << (numberOfChars !=1 ? "es." : ".") << endl;
    return 0;
}
