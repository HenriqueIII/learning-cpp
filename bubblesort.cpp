#include <iostream>

const int DIM=10;

int v[]={9,8,7,6,5,4,3,2,1,0};

void show(int v[], int);

void switchPairs(int v[], int n){
    if (v[n] > v[n+1]){
        int aux=v[n];
        v[n]=v[n+1];
        v[n+1]=aux;
    }
}

void bubbleSort_r(int v[], int n){
        if (n==0){
            return;
        }
        for (int i=0;i<n-1;i++){
            switchPairs(v, i);
        }
        bubbleSort_r(v, n-1);
}

void show(int v[], int n){
    for (int i=0;i<n;std::cout << v[i++] << " ");
    std::cout << std::endl;
}

int main(){
    show(v,DIM);
    bubbleSort_r(v, DIM);
    show(v, DIM);
}
