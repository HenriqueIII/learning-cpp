#include <iostream>
#include <iomanip>

int dividers(unsigned n){
    int div = 0;
    for (int i=2; i<n; ++i)
        if (n%i==0)
            div++;

    return div;
}

int main(){
    int n = 100;
    int cont = 0;
    for (int i=2; cont < n; i++){
        if (!(dividers(i))){
            cont++;
            std::cout << std::setw(4) << i;
            if ((cont)%10==0)
                std::cout << std::endl;
        }
    }
}
