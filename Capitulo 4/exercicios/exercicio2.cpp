#include <iostream>

const int DIM=30;

int strLen(char * str){
    char *q = str;
    while(*q++);
    return (q-str)-1;
}

inline void swapI(char &a, char &b){
    char aux=a;
    a=b;
    b=aux;
}

void invert(char v[]){
    int j = strLen(v);
    for (int i=0; i<j; ++i, --j)
        swapI(v[i],v[j-1]);
    v[strLen(v)]=0;
}


int main(){
    char nome[DIM];
    std::cout << "Por favor escreva o seu nome: ";
    std::cin >> nome;
    std::cout << nome <<" invertido e' ";
    invert(nome);
    std::cout << nome << std::endl;
}
