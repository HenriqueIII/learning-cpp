#include <cstdlib>  //for atoi
#include <cstring>
#include <iostream>
#include <ctime>

time_t t = time(0);
struct tm * now = localtime(&t);

enum WeekDay {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY, INVALID};
static const int DAYS_OF_ONE_WEEK = 7;
const int JAN=31, FEV=28, MAR=31, APR=30, MAY=31, JUN=30, JUL=31, AGO=31, SEP=30, OCT=31, NOV=30, DEC=31;
const int MONTHDAYS[12]={JAN,FEV,MAR,APR,MAY,JUN,JUL,AGO,SEP,OCT,NOV,DEC};
const char sep[]="-/.";


class Date{
private:
    unsigned int year;          //ano
    unsigned char month, day;   //Mês e dia do ano
    int yearDay;                //Numero de dias desde 1 de Janeiro
                                //-1 indica que ainda nao foi calculado.
    WeekDay yearWeekDay;        //Dia da semana de 1 de Janeiro.
                                //INVALID indica que nao foi calculado
    bool leapYear(int y){       //Ano Bissexto
        return (y % 4 == 0) && (y % 100) || (y % 400 == 0);
    }
    int getYearDay();
    WeekDay getYearWeekDay(); //Dia da semana de 1 de Janeiro.
public:
    Date(const Date & other){
        setYear(other.getYear());
        setMonth(other.getMonth());
        setDay(other.getDay());
    }
    void operator=(const Date & other){
        setYear(other.getYear());
        setMonth(other.getMonth());
        setDay(other.getDay());
    }
    Date(int y = 0, int m = 0, int d = 0){  //construtor default
        setYear((y?y:getYearToday()));
        setMonth((m?m:getMonthToday()));
        setDay((d?d:getDayToday()));
    }

    Date(const char * str);
    
    Date(long days){
        int d=0, m=0, y=0;
        while(days-365+leapYear(y)>0){
                days-=365+leapYear(y);
                y++;
        }
        while((days-=(MONTHDAYS[m]+(m+1==2?leapYear(y):0)))>0)
            m++;

        d = -days;
        setYear(y);
        setMonth(m);
        setDay(d);
    }

    void setYear(int y){            //afectar o ano
        year = y;
        yearWeekDay = INVALID;
        yearDay = -1;
    }
    void setMonth(int m){           //afectar o mes
        month = m;
        yearDay = -1;
    }
    void setDay(int d){             //afectar o dia
        if(yearDay!=-1)
            yearDay +=d -day;

        day=d;
    }
    int getDay() const{
        return day;
    }
    int getYear() const{
        return year;
    }
    int getMonth() const{
        return month;
    }
    WeekDay getWeekDay();           //retornar o dia da semana
    const char * getMonthName();    //retornar o nome do mes
    const char * getWeekDayName();  //retornar o nome do dia da semana
    long getDays(Date);
    long subNorm(Date);
    int cmp(const Date &) const;
    int getYearToday();
    int getMonthToday();
    int getDayToday();
    //Mostrar a data na forma de string normalzada
    void displayDate() const;
    //Testar se duas datas são iguais
    bool isEqual(const Date & testdate) const;
    //Testar a ordem cronologica entre datas
    bool isLess(const Date & testdate) const;
    //Testar a validade de uma data expressa em forma de string
    bool validDate(const char*);
    //Retorna os dias entre datas.
    int theDaysBetween(const Date & testdate);
    Date tomorrow();
    Date yesterday();
};
Date::Date(const char * str){
    if (!validDate(str)){
        std::cout << "Data Invalida. Afetando com default(hoje)" << std::endl;
        setYear(getYearToday());
        setMonth(getMonthToday());
        setDay(getDayToday());
        return;
    }   
    int size = strlen(str)+1;
    char data[size];
    strcpy(data, str);
    char * token = strtok(data,sep);
    char * year = token;
    token = strtok(NULL,sep);
    char * month = token;
    token = strtok(NULL,sep);
    char * day = token;
    setYear(atoi(year));
    setMonth(atoi(month));
    setDay(atoi(day));
}
WeekDay Date::getWeekDay(){
    if (yearWeekDay == INVALID)
        yearWeekDay = getYearWeekDay();
    if (yearDay == -1)
        yearDay = getYearDay();
    return WeekDay((yearWeekDay+yearDay)%DAYS_OF_ONE_WEEK);
}
const char * Date::getWeekDayName(){
    static const char * weekDayName[]={"Segunda-Feira", "Terça-Feira", "Quarta-Feira", "Quinta-Feira", "Sexta-Feira", "Sabado", "Domingo"};
    return weekDayName[getWeekDay()];
}
const char * Date::getMonthName(){
    static const char * monthName[]={"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    return monthName[month-1];
}
int Date::getYearDay(){
    static int daysTillMonth[13]={
        0,
        JAN,
        JAN+FEV,
        JAN+FEV+MAR,
        JAN+FEV+MAR+APR,
        JAN+FEV+MAR+APR+MAY,
        JAN+FEV+MAR+APR+MAY+JUN,
        JAN+FEV+MAR+APR+MAY+JUN+JUL,
        JAN+FEV+MAR+APR+MAY+JUN+JUL+AGO,
        JAN+FEV+MAR+APR+MAY+JUN+JUL+AGO+SEP,
        JAN+FEV+MAR+APR+MAY+JUN+JUL+AGO+SEP+OCT,
        JAN+FEV+MAR+APR+MAY+JUN+JUL+AGO+SEP+OCT+NOV,
        JAN+FEV+MAR+APR+MAY+JUN+JUL+AGO+SEP+OCT+NOV+DEC
    };
    return day-1 + daysTillMonth[month-1]+(month>2 && leapYear(year));
}
WeekDay Date::getYearWeekDay(){
    //  Toma-se como referencia 1/1/1 Segunda Feira.
    //  Tem-se em consideraçao que o dia de ano novo
    //  num ano não bissexto avança um dia (365%7=1) e
    //  nos anos bissextos avança dois dias (366%7=2).

    unsigned int d = MONDAY;
    for (int y=1;y<year;++y)
        d+=leapYear(y)?2:1;
    return WeekDay (d%DAYS_OF_ONE_WEEK);
}
long Date::getDays(Date other){
    if (cmp (other) > 0){
        return subNorm(other);
    }
    return -other.subNorm(*this);
}
long Date::subNorm( Date less ){ // subtração normalizada entre duas datas em que *this >= less
    if ( less.year == year )
        return getYearDay() - less.getYearDay();

    //numero de dias até ao fim do ano da menor das datas
    long days = 365 + leapYear(less.year) - less.getYearDay();

    //somatorio da diferença de anos em dias
    for (int y=less.year+1; y<year;++ y){
        days += 365 + leapYear(y);
    }

    //numero de dias até ao fim do ano da maior.
    return days + getYearDay();
}
int Date::cmp(const Date &other) const{ //comparação entre duas datas.
    if(year != other.year)
        return year - other.year;
    if (month != other.month)
        return month - other.month;
    return day - other.day;
}
inline void Date::displayDate() const{
    std::cout << year << "-" << int(month) << "-" << int(day);
}
int Date::getYearToday(){
    return (now->tm_year+1900);
}
int Date::getMonthToday(){
    return (now->tm_mon+1);
}
int Date::getDayToday(){
    return now->tm_mday;
}
bool Date::isEqual(const Date & testdate)const{
    if(year == testdate.year)
        if(month == testdate.month)
            if(day == testdate.day)
                return true;
    return false;
}
bool Date::isLess(const Date & testdate)const{
    if(year<testdate.year)
        return true;
    if(year==testdate.year && month < testdate.month)
        return true;
    if(year==testdate.year && month == testdate.month && day < testdate.day)
        return true;
    return false;
}
bool Date::validDate(const char * str){
    int members=0;
    char * tok[3];
    char strcopy[strlen(str)+1];
    strcpy(strcopy, str);
    char * token = strtok(strcopy, sep);
    while(token){
        tok[members]=token;
        members++;
        token=strtok(NULL, sep);
    }
    if(members!=3)
        return false;
    
    for (int i = 0; i<3; ++i)
        for (int j=0; j < strlen(tok[i]);j++)
            if(!isdigit(tok[i][j])){
                std::cout << "A data contem caracteres nao suportados. \""<< tok[i][j] << "\"." << std::endl;
                return false;
            }

    if( strlen(tok[0])!=4 || strlen(tok[1])>2 || strlen(tok[2]) > 2){
        std::cout << "A data deverá ser YYYY-MM-DD" << std::endl;
        return false;
    }
    int check_month = atoi(tok[1]);
    int check_day = atoi(tok[2]);
    if (check_month < 1 || check_month > 12){
        std::cout << "O mes deverá ser compreendido entre 1 e 12" << std::endl;
        return false;
    }
    int monthdays=0;
    if (check_month == 2)
        monthdays = MONTHDAYS[1] + (leapYear(atoi(tok[0]))?1:0);
    else
        monthdays = MONTHDAYS[check_month-1];
    
    if (check_day < 1 || check_day > monthdays){
        std::cout << "O dia devera ser compreendido entre 1 e " << monthdays << std::endl;
        return false; 
    }
    return true;
}

Date Date::tomorrow(){
    int monthdays=MONTHDAYS[month-1];
    if (month==2)
        monthdays=MONTHDAYS[1]+(leapYear(year)?1:0);
    int d=day,m=month,y=year;
    if (++d > monthdays){
        d=1;
        if (++m > 12){
            m=1;
            y++;
        }
    }
    return Date(y,m,d);
}
Date Date::yesterday(){
    int d=day,m=month,y=year;
    if (--d < 1){
        if(--m <1){
            m=12;
            y--;
        }
        d = MONTHDAYS[m-1]+(m==2?(leapYear(year)?1:0):0);
    }
    return Date(y,m,d);
}

bool validateDate(char * datastr){
    Date test;
    return test.validDate(datastr);
}
