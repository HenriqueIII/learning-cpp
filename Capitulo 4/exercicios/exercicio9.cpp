#include <iostream>
#include <fstream>

const int MAX_CHAR_LINE=80;
const int MAX_CHAR_NAME=20;
const int MAXWORDS=40;
const char SEP[]=" .,\t";

int strLen(const char * str){
    char *q = (char*) str;
    while(*q++);
    return q-str-1;
}
char * strChr(const char * str, int c){
    int len = strLen(str);
    for (int i=0; i<len; ++i){
        if (str[i]==c){
            return (char*)str+i;
        }
    }
    return NULL;
}
char * strTok(char* txt, const char * SEPS){
    /*Funçao comparada a strtok da biblioteca string.h que coloca um '\0' no final da string.*/
    static char* pt;

    if (txt)
        pt=txt;

    while(*pt&&strChr(SEPS, *pt))
        pt++;

    if (!*pt)
        return NULL;

    char * tmp = pt;

    while(*pt && !strChr(SEPS, *pt))
        pt++;

    if (*pt)
        *pt++='\0';

    return tmp;
}
void error(char n[]){
    std::cout << n << " \"nome_ficheiro.txt\""<<std::endl;
    exit(1);
}
void print(char * nome){
    char * word[MAXWORDS];
    int i;

    for(i=0, word[i]=strTok(nome,SEP);word[i]!=NULL&&i<MAXWORDS;word[++i]=strTok(NULL, SEP));

    //std::cout << "Numero de palavras da linha: " << i << std::endl;
    if (i==1){
        std::cout << word[i-1] << std::endl;
        return;
    }
    std::cout << word[0] << ' ' << word[i-1] << std::endl;
}
int main(int argc, char* argv[]){
    if (argc<2){
        error(argv[0]);
    }
    std::fstream f (argv[1], std::ios::in);
    if (!f){
        std::cout << "Error opening the file \""<<argv[1]<<"\"."<<std::endl;
        return 0;
    }
    char line[MAX_CHAR_LINE];
    while(f.getline(line, MAX_CHAR_LINE, '\n')){
        print(line);
    }
    return 0;
}
