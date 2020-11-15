#include <iostream>

int f(int* x){
    *x=3;
    return *x;
}

int main(){
    int x=4;
    int *ptr;
    std::cout << "valor de x: " << x << std::endl;
    ptr=&x;
    f(ptr);
    std::cout << "valor de ptr: " << ptr << std::endl;
//    std::cout << "valor de n: " << n << std::endl;
    std::cout << "valor de x: " << x << std::endl;
    return 0;
}
