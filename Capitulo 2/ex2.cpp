#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int lastNumber, inc, number;

    lastNumber = 16;
    inc=1;

    cout << "dec\thex\toctal" << endl;

    for(number=0;number<=lastNumber;number=number+inc){
        cout << dec << number << '\t' << hex << number << '\t' << oct << number << endl;
    }
    return 0;
}
