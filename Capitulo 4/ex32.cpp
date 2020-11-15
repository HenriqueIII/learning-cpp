//bubblesort recursivo e iterativo
#include <iostream>
#include <stdlib.h>
#include <iomanip>

const int DIM=20;
int v[DIM];
void show(int lista[], int);


//versao iterativa
inline void sortPair(int w[], int i){
    if (w[i]<=w[i+1])
        return;
    int aux = w[i+1];
    w[i+1]=w[i];
    w[i]=aux;
}

void bubblesort(int lista[], int n){
        for (int i = n; i > 0; i--)
            for (int j = 0; j < i; j++)
                sortPair(lista, j);
}
//Fim versao interativa


//funcao recursiva

void dragBig(int v[], int k){
    int i = 0;
    if (k>=2) dragBig(v, k-1);
    show(v, k);
    std::cout << "k: " << k << std::endl;
    if ((i++ % 20) == 0)
        std::cin.get();
    sortPair(v, k-1);
}

void bubble_r(int lista[], int n){
    if (n >= 1)
    {
        dragBig(v,n);
        bubble_r(v, n-1);
    }
}

//fim funcao recursiva


int main(){
    for (int i=0; i <DIM; v[i++]=rand());
    show(&v[0], 1);
    show (v, DIM);
    bubble_r(v, DIM-1);
    show(v, DIM);
    return 0;
}

void show(int lista[], int n){
    for (int i=0; i<n; std::cout << lista[i++] << " ");

    std::cout << std::endl;
}
