//Exemplo 4.18 Dimensao de int sem usar sizeof()
#include <iostream>

int main(){
    int v[1]={1};
    int* p = v;
    std::cout << "Sizeof(char) = 1"<< std::endl;
    std::cout << "p+1" << (p+1) <<std::endl;
    std::cout << "p" << (p)<<std::endl;
    std::cout << "Sizeof(int) = " << ((char*)(p+1)-(char*)p) << std::endl;
}
