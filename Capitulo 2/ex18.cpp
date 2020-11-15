#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main(){
    char strings[9] = "inverter";
    int i, j;
    cout << "A string \"" << strings << "\" invertida e \"";
    for (i=0, j = strlen(strings)-1; i < j; i++, j--){
        char tmp = strings[i];
        strings[i] = strings[j];
        strings[j] = tmp;
    }
    cout << strings << "\"." << endl;
    return 0;
}
