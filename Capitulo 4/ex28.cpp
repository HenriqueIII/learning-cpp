#include <iostream>

unsigned strLen(const char* s){
    const char* q = s;
    while (*q++);
    return (q-s-1);
}

void strinv(char* s, int, int j){
    if ( j-i > 2)
        strinv(s, i+1, j-1);
    char aux = s[j]; s[j] = s[i]; s[i] = aux;
}

int main(){
    //char str[]= "ohnitrec";
    std::cout << "Insira uma string:";
    char str[31];
    std::cin >> str;
    strinv(str, 0, strLen(str)-1);
    std::cout << str << std::endl;
    return 0;
}

