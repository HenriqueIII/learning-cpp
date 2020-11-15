//calculadora usando argumentos cmd com ptr.
#include <iostream>

int addOP(int a, int b){return a+b;}
int subOP(int a, int b){return a-b;}
int divOP(int a, int b){return a/b;}
int mulOP(int a, int b){return a*b;}

typedef int (*OPfunc) (int, int);

OPfunc funcTab[]={addOP,subOP,divOP,mulOP};

char charTab[]={'+','-','/','*'};

enum OP{ADD, SUB, DIV, MUL, LAST};

int strLen(const char* str){
    const char * q = str;
    while(*q++);
    return int (q-str-1);
}

int atoi(const char* str){
    int n=0;
    for (int i=(str[0]=='-'?1:0); i < strLen(str); n=(n*10)+(str[i]-'0'), i++);
    if (str[0]=='-')
        n=-n;
    return n;
}

void error(){
    std::cout << "Usage: calc.exe int [+|-|*|/] int" << std::endl;
    exit(1);
}

int main(int argc, char * argv[]){
    if(argc!=4)
        error();
    int op=ADD;
    while(charTab[op]!=argv[2][0])
        if (++op==LAST)
            error();
    std::cout << funcTab[op](atoi(argv[1]),atoi(argv[3])) << std::endl;
    return 0;
}
