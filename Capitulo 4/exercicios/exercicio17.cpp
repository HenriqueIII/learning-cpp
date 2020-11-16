#include <iostream>
#include <ctype.h>

const int MAX=15;

int respSim(){
    char resp;
    std::cout << " (S/N)? ";
    std::cin >> resp;
    return (toupper(resp)=='S');
}

void lista(int bit){
    for (int n=0;n <=MAX; ++n)
        if (n & bit)
            std::cout << ' ' << n;
}

int adivinha(int bit){
    if (bit >= MAX)
        return 0;
    lista (bit);
    std::cout << "\n O Numero pertence a esta lista";
    int resp = respSim();
    return (resp ? bit : 0) | (adivinha(bit<<1));
}

int main(){
    std::cout << "Pense num valor no intervalo [0.." <<MAX<<"]\n";
    std::cout << "e prima ENTER" << std::endl;
    while(std::cin.get() != '\n');
    int res=adivinha(1);
    std::cout << "O numero que pensou foi " << res << std::endl;
    return 0;
}
