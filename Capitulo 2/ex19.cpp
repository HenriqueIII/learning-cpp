#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main(){
    char strings[] = "kfjiokaslkmvisjfdsvmsdlvsdiv";
    int i, j;
    cout << "A string \"" << strings << "\" ordenada e \"";
    for (i = sizeof(strings) - 2; i > 0; i--)
    for (j = 0; j < i; j++){
        if (strings[j] > strings[j+1]){
            char ch = strings[j];
            strings[j] = strings[j+1];
            strings[j+1]=ch;
        }
    }
    cout << strings << "\"." << endl;
    return 0;
}
