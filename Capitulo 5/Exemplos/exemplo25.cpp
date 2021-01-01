#include <iostream>
#include "IntArray.h"

const int INITIAL_SIZE = 5, NUM_INT = 10;

int main(int argc, char ** argv){
    IntArray v1(INITIAL_SIZE); // v1 toma a dimensão 5
    //Escrever no objecto v1 10 inteiros lidos de cin
    std::cout << "Insira " << NUM_INT << " inteiros -> ";
    int value, i;
    for (i=0; i < NUM_INT; i++){
        std::cin >> value;
        v1.setValueAt(value,i); // se i > 4 amplia espaço
    }
    std::cout << "\nNo IntArray v1 foram inseridos " << v1.size() << " inteiros." << std::endl;
    //escrever no console output o valor inteiro lido
    //do objecto v1 que se encontra no indice indicado.

    std::cout << "\nQual o indice que pretende ler? ";
    std::cin >> i;
    value = v1.getValueAt(i); // caso i > 9 o programa aborta.
    std::cout << "O inteiro situado no indice " << i << " e' " << value << std::endl;
    return 0;
}
