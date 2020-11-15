#include <iostream>

typedef char PChar;//PChar é um apontador para caracter.

typedef PChar PAPChar[];

typedef int VectInt[20];

//typedef ;

typedef void (*PFuncInt)(int);  //PFuncInt é um apontador para uma funçao que nao retorna
                                //nada e recebe um inteiro.

enum Classification{BAD=0,SUFFICIENT=3, GOOD=5};    //Classification é uma enumeraçao de GOOD, SUFFICIENT,
                                                    // e BAD em que BAD tem o valor 0, SUFFICIENT tem o valor 3
                                                    // e GOOD tem o valor 5.


int main(){
    VectInt v[20]={1,2,3,4,5,6,7,8,9,0};
    for (int i=0;i<1;++i)
        for (int j=0;j<20;++j)
            std::cout << v[i][j] << std::endl;
}
