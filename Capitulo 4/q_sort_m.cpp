#include <iostream>
#include <iomanip>
#include <cstdlib>

const int DIM=120;

inline void swapI(int &a, int &b){
        int aux = a;
        a = b;
        b = aux;
}

void show(int v[], int n){
    for(int i=0; i < n; i++){
        std::cout << std::setw(6) << v[i];
        if((i+1)%12==0){
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

void qSort(int v[], int b, int e){
    if (b >= e){
        return;
    }

    int i = b, j = e;

    int pivot = v[(e-b)/2];
    std::cout << "i: " << i << " j: " << j << " b: " << b << " e: " << e << " Pivot: " << pivot << std::endl;
    do{
        while(v[i]<pivot)++i;
        while(v[j]>pivot)--j;
        if (i<=j){
            if(v[i]!=v[j])
                swapI(v[i], v[j]);
            ++i;--j;
            show(v, DIM);
        }
    }while(i<=j);
    std::cout << "i: " << i << " j: " << j << " b: " << b << " e: " << e << std::endl;
    std::cin.get();
    qSort(v, b, j);
    qSort(v, i, e);
}



int main(){
    int v[DIM];
    for (int i=0; i < DIM ; i++)v[i]=rand();
    show (v, DIM);
    qSort(v, 0, DIM-1);
    show(v, DIM);
}
