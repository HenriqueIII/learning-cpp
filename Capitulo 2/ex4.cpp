#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int intNumber=255;
    float floatNumber=99.9989F;
    long bigNumber=12505007L;
    cout << "12345678901234567890" << endl;
    cout << intNumber << endl;
    cout << setw(6) << intNumber << endl;
    cout << bigNumber << endl;
    cout << floatNumber <<endl;

    return 0;
}
