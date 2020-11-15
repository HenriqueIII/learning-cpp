#include <iostream>
void quad(int n){
    std::cout << (n*n) << ' ';
}
void forEach(int a[], int dim, void (*process)(int)){
    for (int i=0; i < dim; ++i)
        process(*a+i);
}

int main(){
    int num[10]={0,1,2,3,4,5,6,7,8,9};
    forEach(num, 10, quad);
    return 0;
}
