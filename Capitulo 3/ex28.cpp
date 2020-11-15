#include <iostream>
#include <fstream>

using namespace std;

int main(){

    fstream file ("facess.txt", ios::in|ios::out);

    if (!file){
        cout << "Error opening file." << endl; return 0;
    }

    file << "Acesso sequencial no ficheiro." << endl;

    file.seekp(-25, ios::cur);

    file << "aleatorio ";

    file.seekg(0);

    char ch;

    while(file.get(ch))
        cout.put(ch);
    return 0;
}
