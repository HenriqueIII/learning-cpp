#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    char ch;
    cout << "Prima uma tecla:" << endl;
    ch = (char) cin.get();
    if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n')
        cout << "E´" << endl;
    else
        cout << "Nao e´" << endl;
    return 0;
}
