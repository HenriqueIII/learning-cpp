#include "uintset.h"
#include <iostream>

const int MAX = 16;

UIntSet crivo;
int main(int argc, char ** argv){
    const u_int N = 60000U;
    for(u_int j = 2; j <= N; ++j){
        crivo.insert(j);
    }
    for(u_int i = 2; i<= N/2; ++i){
        if(crivo.contain(i)){
            for (u_int j=2; j <= N/i; j++){
                crivo.remove(i*j);
            }
        }
    }
    crivo.display();
    std::cout << "\n\n\n";
    u_int newarr[MAX];
    int n=0;
    for (int i=0; i<MAX;i++)
        if((i+1)%2==0){
            newarr[n] = i+1;
            ++n;
        }

    UIntSet set1(newarr, n);
    set1.display();
    return 0;
}

