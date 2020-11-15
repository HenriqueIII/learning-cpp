#include <iostream>

unsigned strLen(const char* s){
    const char* q = s;
    while (*q++);
    return (q-s-1);
}

void uitoa(unsigned n, char * &s){
    if (n==0) return;
    uitoa(n /10, s);
    *s++= n%10+'0';
}

void itoa(int n, char * s){
    if (n < 0){
        *s++='-';
        n=-n;
    }
    uitoa(n, s);
    *s = 0;
}

void strinv(char* s, int, int j){
    int i = 0;
    if ( j-i > 2)
        strinv(s, i+1, j-1);
    char aux = s[j]; s[j] = s[i]; s[i] = aux;
}

int main(){
    //char str[]= "ohnitrec";
    std::cout << "Insira um numero:";
    char str[31];
    int n;
    std::cin >> n;
    itoa(n, str);
    std::cout << str << std::endl;
    return 0;
}

