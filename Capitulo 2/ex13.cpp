#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    unsigned numberOfChars = 0;
    char ch;
    cout << "Insira uma linha de texto: " << endl;
    while ((ch = cin.get()) != '\n')
        if (ch != ' ')
            ++numberOfChars;
    cout << "\nDigitou " << numberOfChars << " caracter" << (numberOfChars !=1 ? "es." : ".") << endl;
    return 0;
}
