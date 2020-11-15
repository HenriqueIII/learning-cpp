#include <iostream>
#include <fstream>
#include <cstring>

const int MAX_IGNORE = 256, MAX_FILENAME=16;

using namespace std;

int main(){
    char filename1[MAX_FILENAME], filename2[MAX_FILENAME];

    cout << "Qual é o nome do ficheiro? -> ";
    cin >> filename1;
    cin.ignore(MAX_IGNORE,'\n');

    for(int i=0; i<MAX_FILENAME-1; ++i){
        if(filename1[i]=='.')
            break;
        else
            filename2[i]=filename1[i];
    }
    strncat(filename2,".MAI", 4);


    ifstream srcfile(filename1);
    ofstream destfile(filename2, ios::trunc);

    char ch;

    while((ch = srcfile.get()) != EOF){
        destfile.put(toupper(ch));
    }

    /*if(!file){
        cout << "Error opening file";
        return 0;
    }

    */
    return 0;
}
