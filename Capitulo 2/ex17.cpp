#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int buffers[10], i;
    cout << "Escreva 10 valores inteiros -> ";
    for (i=0;i<10;i++){
        cin >> buffers[i];
    }
    for (i=9;i>=0;i--)
        cout << buffers[i] << " ";
    return 0;
}
