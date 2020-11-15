#include <iostream>

using namespace std;

int main(){
    int i, j;
    bool isPrimo=1;
    for (i = 2; i <= 100; i++){
        for (j=i-1; j >= 2; j--){
            if (!(i%j))
                isPrimo=0;
        }
        if (isPrimo)
            cout << i << endl;
        isPrimo=1;
    }
    return 0;
}
