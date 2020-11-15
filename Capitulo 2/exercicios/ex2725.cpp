#include <iostream>
#include <conio.h>
#define LINES 11
#define ROWS 79

using namespace std;

int main(){
    char keyPress;
    char a[LINES+1][ROWS+1];
    int posX = 0, posY = 0, i, j;

    for(i = 0; i<=LINES; i++)
        for (j = 0; j<=ROWS; j++)
            a[i][j]=' ';

    while(1){
        keyPress=getch();
        system("cls");
        if ((int)keyPress==27)
            break;

        switch((int)keyPress){
            case 72: //Cima
                if (posY){
                    posY --;
                }
                break;
            case 75: //Esquerda
                if (posX){
                    posX--;
                }else{
                    if(posY){
                        posY--;
                        posX=ROWS;
                    }
                }
                break;
            case 77: //Direita
                if(posX<ROWS){
                    posX++;
                }else{
                    if (posY<LINES){
                        posX=0;
                        posY++;
                    }
                }
                break;
            case 80: //baixo
                if (posY<LINES)
                    posY++;
                break;
        }

        for(i = 0; i<=LINES; i++){
            for (j = 0; j<=ROWS; j++)
                if (i == posY && j == posX)
                    a[i][j]='*';
                else
                    a[i][j]=' ';
        }

        //cout << "("<<posX<<","<<posY<<")"<<"\t"<<a[posY][posX]<<endl;

        for(i = 0; i<=LINES; i++){
            for (j = 0; j<=ROWS; j++)
                cout << a[i][j];
        cout << endl;
        }
    }
    return 0;
}
