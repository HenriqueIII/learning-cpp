#include <iostream>
#include <iomanip>
const int MAX_NUMBER = 16;
const int MAX_LINE = 256;

using namespace std;

int main(){
    int num[MAX_NUMBER], cont=0, base=10;
    char ch;
    char line[MAX_LINE];

    cout << "Insira numeros em base dec, octal ou hexadecimal separados por espaco->" << endl;

    cin.getline(line, MAX_LINE);

    num[cont]=0;

    for (int i=0; line[i]!='\0';i++){
        if (i==0 || isspace(line[i])){

            if (isspace(line[i])){
                num[++cont]=0;
                ++i;
            }

            if ((char)line[i]=='0' && line [i+1] != 'x'){
                base=8;
            }else if((char)line[i]=='0' && line[i+1]=='x'){
                base=16;
            }else{
                base=10;
            }
        }


        if(isdigit(line[i])){
            (num[cont]*=base)+= line[i]-'0';
        }

    }

    cout << "oct\tdec\thex" << endl;
    for(int i=0; i<=cont; i++)
        cout << oct << num[i] << '\t' << dec << num[i] << '\t' << hex << num[i] << endl;
    return 0;
}
