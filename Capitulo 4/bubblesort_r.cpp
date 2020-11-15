#include <iostream>

const int DIM=120;

void show(int v[], int);


void swapN(int v[], int k){
    if (v[k]>v[k+1]){
        int aux = v[k];
        v[k] = v[k+1];
        v[k+1] = aux;
    }
}

void bigIn(int v[], int k){
    if (k>=2){
        bigIn(v, k-1);

    }
    swapN(v, k-1);
    //show(v, k);
    //std::cout << std::endl;
}

void bubble_r(int v[],int n){
    if (n>=1){
        bigIn(v, n);
        bubble_r(v, n-1);
    }
}

void show(int v[], int n){
    for (int i=0; i < n; std::cout << v[i++] << " ");
    std::cout << std::endl << std::endl;
}

int main(){
    int v[DIM];
    for(int i=0;i<DIM; v[i++]=rand());
    show(v, DIM);
    bubble_r(v, DIM);
    show(v, DIM);
}
