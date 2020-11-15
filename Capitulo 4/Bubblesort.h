#ifndef BUBBLESORT_H_INCLUDED
#define BUBBLESORT_H_INCLUDED



#endif // BUBBLESORT_H_INCLUDED
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
