#include <iostream>

using namespace std;

int main(){
    unsigned int num;
    cout << "Insira um numero: " << endl;
    cin >> num;
    cout << "O numero " << num << " e " << (num % 2 == 0 ? "Par" : "Impar") << endl;
    return 0;
}
