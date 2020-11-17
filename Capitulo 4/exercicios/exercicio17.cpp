#include <iostream>
#include <ctype.h>
#include <iomanip>

const int MAX=255;

int respSim(){
    char resp;
    std::cout << " (S/N)? ";
    std::cin >> resp;
    return (toupper(resp)=='S');
}

void lista(int bit){
    int i=0;
    for (int n=0;n <=MAX; ++n){
        if (n & bit){
            std::cout << std::setw(4) << n;
            i++;
        }
        if ((i+1%16)==0)
            std::cout << std::endl;
    }
}

int adivinha_i(){
    int bit = 1;
    int num = 0;
    for(int bit=1;bit<=MAX;bit=bit<<1){
        lista(bit);
        std::cout << "\nbit: " << bit << std::endl;
        std::cout << "\n O Numero pertence a esta lista";
        int resp=respSim();
        if(resp){
            num += bit;
        }
    }
    return num;
}

int adivinha(int bit){
    if (bit >= MAX)
        return 0;
    lista (bit);
    std::cout << "\nbit: " << bit << std::endl;
    std::cout << "\n O Numero pertence a esta lista";
    int resp = respSim();
    return (resp ? bit : 0) | (adivinha(bit<<1));
}

int main(){
    std::cout << "Pense num valor no intervalo [0.." <<MAX<<"]\n";
    std::cout << "e prima ENTER" << std::endl;
    while(std::cin.get() != '\n');
    int res=adivinha_i();
    std::cout << "O numero que pensou foi " << res << std::endl;
    return 0;
}
