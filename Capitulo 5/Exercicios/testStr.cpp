#include <iostream>

char * strChr(const char * str, int character){
    char * res = (char*)str;
    //std::cout << "StrChr res1: " << res << " strChr char1: " << (char)character << std::endl;
    while (*res && *res != character)
        res++;
    //std::cout << "StrChr res2: " << res << " strChr char2: " << (char)character << std::endl;
    if (*res)
        return res;
    return NULL; 
}

char * strTok(char * str, const char * delim){
    static char * res;
    char * pch;

    if (str)
        res = str; 
    while(*res && strChr(delim, *res)){  //Consome separadores
        res++;
    }
    if (!*res)
        return 0;
    char * tmp = res;
    while (*res && !strChr(delim, *res))
        res++;
    if (*res)
        *res++=0;
    return tmp;
}


int main(int argc, char ** argv){
    const char str[11]="1999-01-01";
    char * ptr = (char*)str;
    char * token = strTok("1999-01-01","-");
    char * year = token;
    token = strTok(NULL, "-");
    char * month = token;
    token = strTok(NULL, "-");
    char * day = token;



    std::cout << "Ano: " << atoi(year) << "\nMes: "<< atoi(month)<<"\nDia: " << atoi(day) << std::endl;
    return 0;
}