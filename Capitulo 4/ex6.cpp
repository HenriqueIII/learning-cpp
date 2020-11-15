#include <iostream>

unsigned strLen(const char *p){
    const char* q = p;
    std::cout << "Valor de *p: " << *p << std::endl;
    std::cout << "Valor de p: " << p << std::endl;
    std::cout << "Valor de *q: " << *q << std::endl;
    std::cout << "Valor de q: " << q << std::endl;
    while (* q ++){
            std::cout << "Valor de *q: " << *q << std::endl;
            std::cout << "Valor de q: " << q << std::endl;
    }
    std::cout << "Valor de (q-p-1): " << (q-p-1) << std::endl;
    return (q-p-1);
}

int main(){
    char s[]="pai";
    std::cout << "A palavra " << s << " tem " << strLen(s) << " caracteres" << std::endl;
    return 0;
}
