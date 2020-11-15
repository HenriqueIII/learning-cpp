#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctype.h>

const int LINES_PAG=23, MAX_CHARS=16, MAX_IGNORE=256;

using namespace std;

int main(){
    char fileName[MAX_CHARS];
    cout << "Nome do ficheiro a visualizar? ";
    cin >> setw(MAX_CHARS) >> fileName;

    cin.ignore(MAX_IGNORE,'\n');

    int ch,n1=0;

    ifstream source(fileName);

    while ((ch=source.get())!= EOF){
        cout.put(isprint(ch) || isspace(ch) ? (char)ch:'?');

        if (ch == '\n' && !(++n1 % LINES_PAG)){
            cout << setw(40) << "RETURN ->";
            while(cin.get() != '\n');
        }
    }
    return 0;
}
