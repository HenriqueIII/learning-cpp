/* Exemplo 4.16 - Contar as ocorrencias de cada palavra lida*/

#include <iostream>
#include <cstring>

const int MAX=25; // comprimento maximo das palavras.

struct Pair{
    char name[MAX];
    int val; // val == 0 significa par livre
};

const int WORDS = 1024;
Pair vec[WORDS];

Pair &find(const char* p){
    int i=0;
    for(i = 0; vec[i].val && strcmp(p, vec[i].name); ++i);
    return vec[i];
}

void count(char* word){
    //procura no ARRAY VEC a palavra WORD.
    Pair &res = find(word);
    //palavra nova
    if (res.val==0) strcpy(res.name, word);
    ++res.val;
}

int main(){
    char buf[MAX]; //array para onde sao lidas as palavras.
    std::cout << "Escrever palavras, terminar com EOF (CTRL Z)"<< std::endl;
    while (std::cin >> buf)
        //Se a palavra BUF ainda nao existir inicia no array
        //VEC a estruta PAIR correspondente.
        count (buf);
    for (int i=0; vec[i].val; i++)
        std::cout << vec[i].name << ":" << vec[i].val << std::endl;
    return 0;
}
