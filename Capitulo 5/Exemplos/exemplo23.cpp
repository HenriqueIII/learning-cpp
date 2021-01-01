#include <iostream>
#include "CharStack.h"

void f(){
    CharStack s1(100), s2(200);
    char ch;
    while (! s1.isFull() && (ch = std::cin.get())!='\n')
        s1.push(ch);
    while (! s1.isEmpty())
        s2.push(ch = s1.pop());
    while (! s2.isEmpty())
        std::cout << s2.pop() << std::endl;
}

int main(int argc, char ** argv){
    f();
    return 0;
}
