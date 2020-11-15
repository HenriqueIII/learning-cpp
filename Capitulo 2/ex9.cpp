#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int ano;
    cout << "Ano -> ";cin >> ano;
    if (ano % 400 == 0 || (ano %100 != 0 && ano % 4 == 0)){
        cout << "E";
    }else{
        cout << "Nao e";
    }
    cout << " um ano bisexto";
    return 0;
}
