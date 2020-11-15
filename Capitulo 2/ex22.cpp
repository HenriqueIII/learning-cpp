#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctype.h>
using namespace std;

int main(){
    char identifier[5] = {'A','E','I','O','U',};
    int counts[7], c;
    enum Vog{A,E,I,O,U,SPACE,OTHER} ch;

    do{
        for (ch = A; ch <= OTHER; ch =(Vog)(ch+1)){
            counts[ch]=0;
        }

        cout << "Digite uma linah de texto." << endl;

        while((c=toupper(cin.get())) != '\n'){
            switch (c){
                case 'A': ch = A; break;
                case 'E': ch = E; break;
                case 'I': ch = I; break;
                case 'O': ch = O; break;
                case 'U': ch = U; break;
                case '\t':
                case ' ': ch = SPACE; break;
                default: ch = OTHER; break;
            }
            counts[ch]++;
        }
        cout << endl;

        for (ch = A; ch <= U; ch =(Vog)(ch+1)){
            cout << setw(9) << identifier[ch] << " - " << counts[ch] << endl;
        }
        cout << "Separador" << (counts[SPACE]==1 ? " - " : "es - ") << counts[SPACE] << endl;
        cout << "Outro" << (counts[OTHER]==1?" - ":"s - ") << counts[OTHER] << endl;

        cout << "Quer repetir? (S/N): ";
        if ((c = tolower(cin.get()))!='\n')
            while(cin.get() != '\n');
    }while (c == 's');
    return 0;
}
