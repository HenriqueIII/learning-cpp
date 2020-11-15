#include <iostream>

using namespace std;

const int NUMBER_LINES=20;

int main(){
    int i=1;
    while(i <= 100){
        cout << i << endl;
        if (!(i++%NUMBER_LINES)){
            if (i>100){
                continue;
            }
            cout << "RETURN ->";
            while(cin.get() != '\n');
        }

    }
    return 0;
}
