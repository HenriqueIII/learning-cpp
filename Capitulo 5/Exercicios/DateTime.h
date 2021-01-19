#include "date.h"
#include "Time.h"
#include <iostream>
#include <cstring>

//separadores
const char seps[]=".:/-";
const char sep_m[]="@";

class DateTime{
    Date __date;
    Time __time;
    void operator=(const DateTime & dt){
        __date=dt.__date;
        __time.setTime(dt.__time);
    }
public:
    DateTime(unsigned y, unsigned m, unsigned d, unsigned h, unsigned min, unsigned s);
    DateTime(const Date &,const Time &);
    // Recebe uma string normalizada "aaaa/mm/dd@hh:mm:ss"
    DateTime(const char *);
    // Construir o objecto com a data e hora actual
    DateTime();

    void setData(const Date & d){ // Afecta os atributos do objecto Date
        __date=d;
    }
    void setTime(const Time & t){ // Afecta os atributos do objecto Time 
        __time.setTime(t);
    }
    Date getData() const{
        return __date;
    }
    Time getTime() const{
        return __time;
    }

    //Mostrar a data e tempo na forma de string formatada
    void printOn();
    //Avaliar se a string é valida para iniciar o objecto
    bool isValid(const char *);
    //Devolve o tempo entre duas DateTime
    DateTime theTimeBetween(DateTime &);
    
    bool isEqual(DateTime &); // Retorna TRUE se forem iguais
    bool isLess(DateTime &);    // Retorna TRUE se *this for menor
};
//Função para converter char em const char *, para usar com strcat
const char * atos(char c){
    char convert[] = {c, '\0'};
    char *res = convert;
    return res;
}
//Construtores
DateTime::DateTime (unsigned y, unsigned m, unsigned d, unsigned h, unsigned min, unsigned s){
    char separators[] ={"//@::"};
    unsigned farg[6]={y,m,d,h,min,s}, j=0;
    char str[20]={""};
    for (int i=0;i<6;i++){
        strcat(str, toStr(farg[i]));
        strcat(str, atos(separators[j++]));
    }
    if(!isValid(str)){
        std::cout << "Parametros incorrectos. Afectando com a data/hora actual." << std::endl;
        *this=DateTime();
        return;
    }
    char * dateptr=strtok(str,"@");
    char * timeptr=strtok(NULL,"@");
    __date = Date(dateptr);
    __time.setTime(timeptr);
}
DateTime::DateTime(const Date & d, const Time & t){
    __date=d;
    __time.setTime(t);
}
DateTime::DateTime(const char * datetime_str){
    if(!isValid(datetime_str)){
        std::cout << "Inicialização incorreta, afetando com a data/hora actual" << std::endl;
        *this=DateTime();
        return;
    }

    char datetime_str_cpy[strlen(datetime_str)+1];
    strcpy(datetime_str_cpy,datetime_str);

    char * dateptr=strtok(datetime_str_cpy,"@");
    char * timeptr=strtok(NULL,"@");
    __date = Date(dateptr);
    __time.setTime(timeptr);
}
DateTime::DateTime(){
    __date=Date(0,0,0);
    __time.setTime(Time());
}
//Validação
bool DateTime::isValid(const char * s){
    //Copia do valor da string para uma string local
    int size = strlen(s);
    char DateTime_str[size+1];
    strcpy(DateTime_str,s);
    bool hasMiddleSeparator = false;
    
    //verificar se tem o @
    for (int i = 0; i < size; i++)
        if(strchr(sep_m,DateTime_str[i]))
            hasMiddleSeparator=true;
    if(!hasMiddleSeparator){
        std::cout << "A data deve ser separada do tempo por @" << std::endl;
        return false;
    }

    //dividir em duas substrings
    char * ptrdate = strtok(DateTime_str,sep_m);
    char * ptrtime = strtok(NULL, sep_m);

    //validar a data
    if(!validateDate(ptrdate))
        return false;
    
    //validar o tempo
    if(!validateTime(ptrtime))
        return false;

    return true;
}
//Imprimir
void DateTime::printOn(){
    __date.displayDate();
    std::cout << sep_m;
    __time.printOn();
}
//Funções de comparação
DateTime DateTime::theTimeBetween(DateTime & dt){
    int secs_dif=__time.theTimeBetween(dt.__time);
    long days_dif=__date.getDays(dt.__date);
    if (secs_dif < 0)
        secs_dif = -secs_dif;
    if (days_dif < 0)
        days_dif = -days_dif;
    Date date_dif(days_dif);
    Time time_dif("00:00:00");
    if (isLess(dt))
        time_dif.setTime(Time((long)secs_dif));
    return DateTime(date_dif, time_dif);
}
bool DateTime::isEqual(DateTime & dt){
    if(__date.isEqual(dt.__date) && __time.isEqual(dt.__time))
        return true;
    return false;
}
bool DateTime::isLess(DateTime & dt){
    if(__date.isLess(dt.__date) || __date.isEqual(dt.__date))
        if(__time.isLessThan(dt.__time))
            return true;
    return false;
}