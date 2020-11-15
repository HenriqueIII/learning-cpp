#include <iostream>
#include <fstream>
#include <cstring>

const int MAX_IGNORE=256, SIZEOFP=46, NAME_MAX=255;

int main(){
    char palavra[SIZEOFP], filename[NAME_MAX],fileword[SIZEOFP];
    int cont=0;

    std::cout << "Abrir ficheiro -> ";
    std::cin.getline(filename, NAME_MAX);

//    std::cin.ignore(MAX_IGNORE, '/n');

    std::fstream file(filename, std::ios::in);

    if(!file){
        std::cout << "Error opening file.";
        return 0;
    }

    std::cout << "Palavra a procurar -> ";

    std::cin.getline(palavra, SIZEOFP);

    for (int j=0; j<SIZEOFP; j++)
        palavra[j]=tolower(palavra[j]);


    std::cout << palavra << std::endl;

    char ch;
    int i=0;

    while((ch=file.get())!= EOF){
        if(!isalnum(ch)){
            if(strcmp(fileword,palavra)==0)
                ++cont;
            i=0;
            for (int j=0;j<SIZEOFP-1;j++)
                fileword[j]='\0';
            continue;
        }
        fileword[i]=tolower(ch);
        ++i;
    }
    std::cout << "A Palavra \"" << palavra << "\" aparece no ficheiro " << cont << " vezes." << std::endl;
    return 0;
}
