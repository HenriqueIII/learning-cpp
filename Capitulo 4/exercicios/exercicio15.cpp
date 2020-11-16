#include <iostream>
#include <iomanip>
#include <stdlib.h>

const int DIM=10000;
const char * menu_str[]={" 1 - BubbleSort", " 2 - QuickSort", " 3 - qsort em stdlib.h", " 4 - Imprimir Lista Inicial" ," 0 - Sair"};
int contar;

int strLen(const char * v){
    char * q = (char*) v;
    while(*q++);
    return q-v-1;
}
void swapI(int &a, int &b){
    int aux=a;
    a=b;
    b=aux;
}
int menu(){
    std::cout << "+"<<std::setw(46)<< std::setfill('-') << "+"<<std::endl<<std::setfill(' ');
    std::cout << "|"<<menu_str[0]<<std::setw(46-strLen(menu_str[0]))<<"|"<<std::endl;
    std::cout << "|"<<menu_str[1]<<std::setw(46-strLen(menu_str[1]))<<"|"<<std::endl;
    std::cout << "|"<<menu_str[2]<<std::setw(46-strLen(menu_str[2]))<<"|"<<std::endl;
    std::cout << "|"<<menu_str[3]<<std::setw(46-strLen(menu_str[3]))<<"|"<<std::endl;
    std::cout << "|"<<menu_str[4]<<std::setw(46-strLen(menu_str[4]))<<"|"<<std::endl;
    std::cout << "+"<<std::setw(46)<< std::setfill('-') << "+"<<std::endl<<std::setfill(' ');
    int choose;
    std::cin >> choose;
    return choose;
}
void menu_error(){
    std::cout << "Numero Invalido" << std::endl;
}
int bubbleSort(int v[], int n){
    int cont=0;
    for (int i = n; i>0; --i){
        int troca=0;
        for (int j=0; j<i; ++j){
            cont++;
            if (v[j]>v[j+1]){
                troca = 1;
                swapI(v[j], v[j+1]);
            }
        }
        if(!troca){
            break;
        }
    }
    return cont;
}
int quickSort(int v[], int b, int e){
    int j = b;
    int cont = 0;
    if(b>=e){
        return 0;
    }
    for (int i=b; i<e; i++){
        cont++;
        if (v[i]<=v[e]){
            swapI(v[i], v[j]);
            j++;
        }
    }
    swapI(v[j], v[e]);
    cont += quickSort(v, b, j-1);
    cont += quickSort(v, j+1, e);
    return cont;
}
void show(int v[], int n){
    for (int i=0; i<n; i++){
        std::cout << std::setw(6)<<v[i];
        if((i+1)%12==0){
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}
int compar (const void * p1, const void * p2){
    contar++;
    return * (int*)p1-*(int *)p2;
}


int main(){
    int arr[DIM], escolha, desemp, c[DIM];
    for (int i = 0; i < DIM; arr[i++]=rand());
    //show(arr, DIM);
    do{
        escolha = menu();
        for (int i=0; i<DIM; i++)
            c[i]=arr[i];
        switch(escolha){
            case 1:
                desemp=bubbleSort(c, DIM-1);
                show(c, DIM);
                std::cout << "Algoritmo terminado em "<<desemp<<" vez"<<(desemp==1?".":"es.")<<std::endl;
                break;
            case 2:
                desemp=quickSort(c, 0, DIM);
                show (c, DIM);
                std::cout << "Algoritmo terminado em "<<desemp<<" vez"<<(desemp==1?".":"es.")<<std::endl;
                break;
            case 3:
                contar=0;
                qsort(c, DIM, sizeof(int), compar);
                show(c, DIM);
                std::cout << "Algoritmo terminado em "<<contar<<" vez"<<(contar==1?".":"es.")<<std::endl;
                break;
            case 4:
                show (arr, DIM);
                break;
            case 0:
                break;
            default:
                menu_error();
        }
    }while(escolha!=0);
}
