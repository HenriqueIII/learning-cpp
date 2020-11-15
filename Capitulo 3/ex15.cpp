#include <iostream>
#include <ctype.h>
#include <conio.h>

using namespace std;

int main(){
    char c;
    cout << "Escreva um caracter - "; c=getch();
    cout << endl;
    if (isalpha(c))
        cout << "Letra - " << c;
    else if (isdigit(c))
        cout << "Digito - " << c;
    else if (isspace(c))
        cout << "Espaço em Branco.";
    else if (isprint(c))
        cout << "Simbolo - " << c;
    else
        cout << "Simbolo nao visualizavel, codigo - " << (int)c;
    cout << endl;
    return 0;
}
