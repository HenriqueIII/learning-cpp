#include <iostream>
#include <fstream>

const int NUMINT=20;

using namespace std;

int main(){
    int inicio, fim;
    fstream farray ("array.dat", ios::in|ios::out|ios::binary);

    if (!farray){
        cout << "Error opening file." << endl; return 0;
    }

    for (int i = 0; i < NUMINT; i++)
        farray.write((char *)&i, sizeof(int));

    for (inicio=0, fim=NUMINT-1; inicio<fim ; ++inicio, --fim){

        int auxInicio, auxFim;

        farray.seekg(inicio*sizeof(int));
        farray.read((char*)&auxInicio, sizeof(int));

        farray.seekg(fim*sizeof(int));
        farray.read((char*)&auxFim, sizeof(int));

        farray.seekp(inicio*sizeof(int));
        farray.write((char*)&auxFim, sizeof(int));

        farray.seekp(fim*sizeof(int));
        farray.write((char*)&auxInicio, sizeof(int));
    }

    farray.seekg(0);
    int aux;
    while(farray.read((char*)&aux, sizeof(int)))
        cout << aux << ' ';
    cout << endl;
    return 0;
}
