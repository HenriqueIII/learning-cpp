#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){
    int numLines = 7, espaco;
    for (int line=0; line < numLines; ++line){
        espaco = abs((numLines >> 1)-1);
        cout << setfill(' ') << setw(espaco+1) << '<';
        espaco = numLines/2 - espaco + ((espaco < numLines/3)?numLines:1);
        cout << setfill('=') << setw(espaco) << '|' << endl;
    }
    return 0;
}
