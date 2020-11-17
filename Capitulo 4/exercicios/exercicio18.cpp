#include <iostream>

const int BITS_OF_CHAR = 8;

inline char getDigit (unsigned val){
    return val + (val<10?'0':'A'-10);
}

char * getStrBase(unsigned num, int base =16){
    const int MAX_BUFF = sizeof(int) * BITS_OF_CHAR + 1;
    static char str[MAX_BUFF];
    char * res = str + MAX_BUFF;
    *--res=0;
    if (num > 0)
        for (; num >0; num /= base)
            *--res = getDigit(num%base);
    else
        *--res = '0';
    return res;
}

int main(){
    int num;
    std::cout << "Insira um numero inteiro > 0: ";
    std::cin >> num;
    for (int i = 2; i <= 32; i *= 2)
        std::cout << "Numero: " << num << " Base " << i << " = " << getStrBase(num, i)<< std::endl;
    return 0;
}
