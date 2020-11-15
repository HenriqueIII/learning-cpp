#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include "Bubblesort.h"
#include <stdio.h>

const int DIM=24000;

inline void swap_i(int &a, int &b){
    int aux = a;
    a=b;
    b=aux;
}

void show(int v[], int n){
    for (int i=0; i < n; ++i){
        std::cout << std::setw(6) << v[i];
        if ((i+1)%12==0)
            std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

void quickSort(int v[], int b, int e){
    int j=b;

    if (b>=e) //condiçao terminante
        return;
    //show(v, 11);
    //std::cout << std::endl;
    for (int i = b; i < e; i++){
        //std::cout << "i: "<< i << " j: "<< j << " Valor: " << v[i] << " Pivot: " <<v[e]<< std::endl;

        if (v[i]<=v[e]){
            swap_i(v[i], v[j]);
            j++;
        }
    }
    swap_i(v[j], v[e]);
    quickSort(v, b, j-1);
    quickSort(v, j+1, e);
}

int main(){
    //srand (time(NULL));
    int v[DIM];
    int c[DIM];
    time_t now, s1, s2, s3;
    double dif;
    for(int i=0;i<DIM; v[i++]=rand());
    for(int i=0;i<DIM; c[i]=v[i], i++);
    //show(v, DIM);
    time(&now);
    quickSort(v, 0, DIM-1);
    time(&s1);
    dif=difftime(s1, now);
    //show(v, DIM);
    printf("QuickSort em: %.f\n", dif);
   // show(c, DIM);
    time(&s2);
    bubble_r(c, DIM-1);
    time(&s3);
    //show(v, DIM);
}
