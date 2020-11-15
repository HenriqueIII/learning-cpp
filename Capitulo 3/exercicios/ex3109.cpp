#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    char ch;
    fstream file ("file.dat", ios::binary|ios::in|ios::out|ios::trunc);
    for (int i=0; i<255; i++){
            ch = i;
            file.write(&ch, sizeof(char));
            if (i+1%3==0)
                file.write((char*)'\n', sizeof(char));
    }

    file.seekg(0);
    while(file.read(&ch, sizeof(char)))
          cout <<"byte: " << ch << " dec: " << dec << (int)ch << " hex: " << hex << (int)ch << endl;
    return 0;
}
