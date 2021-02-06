/** 12. Usando obectos da classe String e WordArray esceva um programa
 *      que mostre sem repetições, ordenadas em 4 colunas, as palavras de um
 *      ficheiro de texto.                                                  */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "WordArray.h"

std::ifstream openFile(String & fileName){
    std::ifstream f(fileName.getStr());
    if (!f){
        std::cout << "Error opening " << fileName.getStr() << '\n';
        exit (1);
    }
    return f;
}

WordArray getData(std::ifstream & f){
    WordArray arr;
    point=false;
    int i=0;
    while(!f.eof()){
        String word;
        f >> word;
        if(word.lenght())
            arr.setValueAt(word,i++);
    }
    return arr;
}

void print(WordArray & texto){
    texto.removeEqual();
    texto.ordArray();
    for (int i=0;i<texto.getSize();i++){
        std::cout << std::setw(20) << texto.getValueAt(i).getStr();
        if ((i+1)%4==0)
            std::cout << '\n';
    }
    std::cout << '\n';    
}

int main(int argc, char ** argv){
    std::cout << "Qual o ficheiro que pretende abrir? ";
    String filename;
    std::cin >> filename;
    std::ifstream f = openFile(filename);
    WordArray texto=getData(f);
    f.close();
    print(texto);
    return 0;
}