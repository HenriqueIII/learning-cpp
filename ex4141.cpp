//Exercicio 1 do cap 4
#include <iostream>

typedef char (*PChar); //apontador p caracter.
typedef char (*PAPChar)[10]; //Apontador para array de caracteres.
typedef void (*PFuncInt)(int); // apontador para função que nao retorna nada e recebe 1 int
typedef int VectInt[20]; //array para 20 int

*PFuncInt(a){
    std::cout << a << std::endl;
    std::cout << a << std::endl;
}

int main(){
    PFuncInt(3);
}


