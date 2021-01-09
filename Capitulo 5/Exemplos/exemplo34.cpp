//Algoritmo de Eratosthenes
//Encontrar numeros primos até n
//1º Passo - Criar um conjunto de numeros de 2 até n
//2º Passo - Encontrar o numero maximo para testar, usando a raiz quadrada de n, arrendodada para baixo
//3º Passo - Para o primeiro numero do conjunto(2), eliminar todos os multiplos (2*i) até i=n/2
//4º Passo - Pegar no próximo numero(z) do conjunto e remover todos os multiplos (z*i) até i=n/2
//5º Passo - Repetir para todos os proximos numeros no conjunto até ao numero encontrado no passo 2
//6º Passo - Imprimir o conjunto no ecrã 

#include "IntSet.h"
#include <cmath>
#include <iostream>

int main(int argc, char ** argv){
    IntSet crivo;
    const int n = 5000;
    int maxcheck = roundf(sqrt(n));
    for (int i = 2; i <= n; i++)
        crivo.insertN(i);
    crivo.reset();
    for (int i = crivo.getCurr();i <= maxcheck; crivo.next(), i=crivo.getCurr())
        for (int j=2; j <= n/2; j++)
            crivo.removeN(i*j);
    crivo.display();
    return 0;
}