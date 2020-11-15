#include <iostream>

using namespace std;

int main(){
    int i, cont=0;
    cout << "char oct dec hex | char oct dec hex | char oct dec hex" << endl;
    for (i=33; i<= 126; i++){
        if (i< 64)
            cout <<"   " << (char) i << "  " << oct << i << "  " << dec << i << "  " << hex << i;
        else if (i<100)
            cout <<"   " << (char) i << " " << oct << i << "  " << dec << i << "  " << hex << i;
        else
            cout <<"   " << (char) i << " " << oct << i << " " << dec << i << "  " << hex << i;

        if (cont==0 || cont==1){
            cout << " | ";
            cont++;
        }else{
            cont = 0;
        }

        if ((i+1)%3==0)
            cout << endl;
    }
    cout << endl;
    return 0;
}
