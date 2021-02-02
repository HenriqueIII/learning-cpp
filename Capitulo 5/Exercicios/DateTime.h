#include "date.h"
#include "Time.h"
#include <iostream>
#include <cstring>
#include <iomanip>

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
    //Função para ordenar as datas
    void arrange(DateTime *&, DateTime *&);
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
    //Devolve um objecto Time com a diferença
    Time getTimeBetween(DateTime &);
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
DateTime DateTime::theTimeBetween(DateTime & other){
    int d=0, m=0, y=0;
    //copiar as datas para nao afectar os objectos passados
    DateTime dt1(*this);
    DateTime dt2(other);
    //ordenar a data
    DateTime *__init=&dt1;
    DateTime *__end=&dt2;
    arrange(__init,__end);
    //declarar variaveis auxiliares para ajudar nos algortimos    
    Date aux = __init->__date;  //Iniciar uma data começando na data menor
    Time t = __init->__time;    //Iniciar um tempo com o tempo da data menor
    //contar o numero de anos
    while(aux.getYear() != __end->getData().getYear()){ //incrementa ano da data até serem iguais
        aux.opYear('+');    //Equivale a aux.setYear(aux.getYear()+1)
        y++;                //incrementa o contador de anos para devolver no futuro
    }
    //teste para saber se o ultimo ano foi completo
    if (aux.getMonth() > __end->getData().getMonth() ||
    (aux.getMonth() == __end->getData().getMonth() && 
    aux.getDay() > __end->getData().getDay())){
        y--;
        aux.opYear('-');
    }
    //contar o numero de meses restantes
    while (aux.getYear() < __end->getData().getYear() || aux.getMonth() != __end->getData().getMonth()){
        aux.opMonth('+');
        m++;
    }
    //teste para saber se o mês foi completo
    if(aux.getDay() > __end->getData().getDay()){
        m--;
        aux.opMonth('-');
    }
    //contar o numero de dias
    while (aux.isLess(__end->getData())){
        d++;
        aux = aux.tomorrow();
    }
    //testar se passou um dia completo
    if(__end->getTime().isLessThan(t))
        d--;
    aux.setDay(d);
    aux.setMonth(m);
    aux.setYear(y);
    //calcular o tempo
    long secs_between=t.theTimeBetween(__end->getTime());
    Time dif(secs_between);
    return DateTime(aux,dif);
}
//Função que calcula o tempo em horas da diferença de tempo
//Deverá receber uma diferença, não uma data
Time DateTime::getTimeBetween(DateTime & other){
    //Variaveis para construir o objecto Time
    int h=0, m=0, s=0;
    //Copia de objecto
    DateTime dt1=*this;
    DateTime dt2=other;
    //Ponteiro para copia de objecto
    DateTime * init = &dt1;
    DateTime * end = &dt2;
    //ordenar as datas
    arrange(init, end);
    //Numero de dias que medeiam ambas as datas
    long days = end->getData().getDays(init->getData());
    //Converter dias para horas
    if (end->getTime().isLessThan(init->getTime()))
        days--;
    while(days--){
        h+=24;
    }
    //ver quantas horas medeiam entre os tempos
    Time aux = init->getTime();

    while(aux.getHour() != end->getTime().getHour()){
        h++;
        aux.incHour();
    }

    Time res = init->getTime().theTimeBetween(end->getTime());
    res.setHour(h,true);
    return res;
}
void DateTime::arrange(DateTime *&dt1, DateTime *&dt2){
    if(dt2->isLess(*dt1)){
        DateTime aux(*dt2);
        dt2->setData(dt1->__date);
        dt2->setTime(dt1->__time);
        dt1->setData(aux.__date);
        dt1->setTime(aux.__time);
    } 
}
bool DateTime::isEqual(DateTime & dt){
    if(__date.isEqual(dt.__date) && __time.isEqual(dt.__time))
        return true;
    return false;
}
bool DateTime::isLess(DateTime & dt){
    if(__date.isLess(dt.__date))
        return true;
    if(__date.isEqual(dt.__date) && __time.isLessThan(dt.__time))
            return true;
    return false;
}