#include <iostream>
#include <conio.h>

using namespace std;

int main(){
    char keyPress;

    cout << "Pressione uma tecla para checar o ascii. ESC para terminar." << endl;

    while(1){
        keyPress=getch();
        if ((int)keyPress==27)
            break;

        switch((int)keyPress){
            case 72: cout << "Cima" << endl; break;
            case 75: cout << "Esquerda" << endl; break;
            case 77: cout << "Direita" << endl; break;
            case 80: cout << "Baixo" << endl; break;
        }
    }
    return 0;
}
