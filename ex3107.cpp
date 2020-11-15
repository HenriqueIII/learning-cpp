#include <iostream>
#include <fstream>

const int MAX_IGNORE = 256, MAX_FILENAME=16;

using namespace std;

int main(){
    char filename[MAX_FILENAME];
    cout << "Qual é o nome do ficheiro? -> ";
    cin >> filename;
    cin.ignore(MAX_IGNORE,'\n');
    fstream file(filename, ios::trunc|ios::in|ios::out);

    if(!file){
        cout << "Error opening file";
        return 0;
    }

    cout << "Digite um texto acabado com ponto final(.) -> ";

    char ch;

    while ((ch=cin.get()) != '.'){
        file.put(ch);
    }
    file.put('.');

    file.seekg(0);


    while ((ch=file.get())!='.')
        cout << ch;
    cout << '.';
    cout << endl;
    return 0;
}
