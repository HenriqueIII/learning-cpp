#include <iostream>
#include <iomanip>
typedef int Disks;
enum Post {A='A', B, C};
int moves=0;

void moveD(Disks n, Post src, Post aux, Post dest){
    if (n==1){
        std::cout << std::setw(4) << ++moves << " Movimento: Mover disco da estaca " << char(src) << " para a estaca " << char(dest) << ".\n";
    }else{
        moveD(n-1, src, dest, aux);
        moveD(1, src, aux, dest);
        moveD(n-1, aux, src, dest);
    }
}

int main(){
    Disks k;
    do{
        std::cout << "Numero de discos (0 termina): ";
        std::cin >> k;
        if (!(k))
            break;
        moveD(k, A, B, C);
        moves=0;
    }while(k!=0);
}
