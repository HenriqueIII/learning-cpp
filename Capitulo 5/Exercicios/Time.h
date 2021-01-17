#include <iostream>
#include <ctime>
#include <cstring>

typedef unsigned char tinyint;
typedef tinyint * TimePtr; 
const char sep[]=":";

class Time{
    //hour < 24;minute < 60;second < 60
    tinyint hour, minute, second;
    //operador = exclusivo para uso dentro da classe.
    void operator=(const Time & t){
        hour = t.hour;
        minute = t.minute;
        second = t.second;
    }
    //subtracao normalizada entre horas, retorna em segundos a diferença
    int subNorm(Time &);
public:
    Time(); //Iniciar com o tempo corrente do sistema
    Time(int hours, int minutes=0, int seconds=0);
    Time(const Time &); //Construtor por cópia
    Time(long seconds); //Receber tempo recebido em segundos
    //Receber tempo na forma de string formatada 'hh:mm:ss'
    Time(const char * s);
    //Afectar os atributos recebendo uma string formatada
    void setTime(const char * s);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);
    unsigned getHour() const;
    unsigned getMinute() const;
    unsigned getSecond() const;
    //Mostrar o valor na forma de string formatada
    void printOn() const;
    //Retorna a diferença de tempo em segundos
    int theTimeBetween(Time&);
    bool isEqual(const Time&) const; // Retorna TRUE se forem iguais
    bool isLessThan(const Time & t); // Retorna TRUE se *this for menor que t
};
//função que retorna o tempo actual em objecto Time
Time getNow(){
    time_t t = time(0);
    struct tm * now = localtime(&t);
    unsigned s = now->tm_sec;
    unsigned m = now->tm_min;
    unsigned h = now->tm_hour;
    return Time(h,m,s);
}
//função para colocar um '0' a frente dos numeros quando menores que 10
char *  toStr(tinyint c){ 
    int n=c;
    char str[3];
    char *ptr = str+3;
    *--ptr=0;
    do{
        *--ptr=(n%10)+'0';
        n/=10;
    }while (n>0);
    if (int(c)<10)
        *--ptr='0';
    return ptr;
}
//Construtor vazio, afeta o objecto *this com o objecto Time retornado pela funcao getNow()
Time::Time(){
    *this=getNow();
}
//Construtor com 3 parametros.
Time::Time(int hours, int minutes, int seconds){
    if (seconds>=60){
        minutes += seconds / 60;
        seconds = seconds % 60;
    }
    if (minutes >= 60){
        hours += minutes / 60;
        minutes = minutes % 60;
    }
    if (hours >=24)
        hours = 0;
    setSecond(seconds);
    setMinute(minutes);
    setHour(hours);
}
//Construtor por cópia
Time::Time(const Time & t){
    hour = t.hour;
    minute = t.minute;
    second = t.second;
}
//Construtor por string no formato hh:mm:ss
Time::Time(const char * s){
    //Cria um array com os endereços das variaveis do objecto
    TimePtr Timearr[] = {&hour, &minute, &second};
    int size = strlen(s)+1, i=0;
    char timestr[size], *tok;
    //Copia o valor recebido para uma string local
    strcpy(timestr, s);
    /*Inicializa *tok com o primeiro valor 'hh'
    * Enquanto existir tokens corre o loop
    * Afeta *tok com os restantes tokens ('mm' e 'ss')*/
    for(tok = strtok(timestr, sep);tok;tok=strtok(NULL, sep),i++){
        *Timearr[i] = atoi(tok);//Afecta as variaveis hour,minute e second com o valor do token.
    }
}

Time::Time(long seconds){
    /*TimePtr Timearr[] = {&hour, &minute, &second};
    int j=0;
    for (int i= 3600; seconds > 0; i/=60){
        *Timearr[j++] = tinyint(seconds / i);
        seconds %= i;
    }*/
    setSecond(seconds);
}
//Afeta o objecto com a string(hh:mm:ss)
void Time::setTime(const char * s){
    *this=Time(s);
}

void Time::setHour(int h){
    if(h>=24)
        h=h%24;
    hour=h;
}
void Time::setMinute(int m){
    if (m >= 60){
        setHour(m/60);
        m=m%60;
    }
    minute=m;
}
void Time::setSecond(int sec){
    if (sec >= 60){
        setMinute(sec/60);
        sec=sec%60;
    }
    second=sec;
}
inline unsigned int Time::getHour() const{
    return hour;
}
inline unsigned int Time::getMinute() const{
    return minute;
}
inline unsigned int Time::getSecond() const{
    return second;
}
inline void Time::printOn() const{
    std::cout << toStr(hour) << ':' << toStr(minute) << ':' << toStr(second) << std::endl;
}
int Time::theTimeBetween(Time & t){
    if(isLessThan(t))
        return subNorm(t);
    return -t.subNorm(*this);
}
bool Time::isEqual(const Time & t) const{
    if (hour==t.hour && minute==t.minute && second==t.second)
        return true;
    return false;
}
bool Time::isLessThan(const Time & t){
    if(hour < t.hour)
        return true;
    if(hour == t.hour && minute < t.minute)
        return true;
    if(hour == t.hour && minute==t.minute && second < t.second)
        return true;
    return false;       
}
int Time::subNorm(Time & t){
    int seconds = t.second - second;
    int minutes = t.minute - minute;
    int hours = t.hour - hour;
    minutes+=hours*60;
    seconds+=minutes*60;
    return seconds;
}