#include <iostream>
#include "String.h"

int main(int argc, char** argv){
    //Testar os construtores
    String s1, s2("abcdef"), s3("abcdefgh", 4);
    std::cout << "String 1 - ";
    s1.display();
    std::cout << "String 2 - ";
    s2.display();
    std::cout << "String 3 - ";
    s3.display();
    //Testar a diferen�a entre lenght e capacity
    std::cout << " comprimento - " << s3.lenght() << std::endl << " capacidade - " << s3.capacity() << std::endl;
    s3.assignStr(s1);   //Teste � afecta��o (string menor).
    std::cout << "String 3 - ";
    s3.display();
    std::cout << " comprimento - " << s3.lenght() << std::endl << " capacidade - " << s3.capacity() << std::endl;
    s1.assignStr(s2); //Teste � afecta��o (string Maior).
    std::cout << "String 1 - ";
    s1.display();
    s2.assignStr("Nova Cadeia de Caracteres",15);
    std::cout << "String 2 - ";
    s2.display();
    s1.removeChar(0);   //Teste � remo��o
    std::cout << "String 1 - ";
    s1.display();
    s1.insertChar(5,'z');//Teste � Inser��o
    std::cout << "String 1 - ";
    s1.display();
    return 0;
}
