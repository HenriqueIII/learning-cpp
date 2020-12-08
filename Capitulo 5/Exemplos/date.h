enum WeekDay {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY, INVALID};
static const int DAYS_OF_ONE_WEEK = 7;

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

    Date(int y = 1998, int m = 1, int d = 1){   //construtor
        setYear(y);
        setMonth(m);
        setDay(d);
    }

    Date(const char * datastr){
        int ano;
        int mes;
        int dia;
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

    WeekDay getWeekDay();           //retornar o dia da semana

    const char * getMonthName();    //retornar o nome do mes

    const char * getWeekDayName();  //retornar o nome do dia da semana

    const char * getNormDate(const char*);

    int concat (char *, const char *, int);
};
char * toStr(int val, int len){
    const int MAX_BUF = sizeof(int)*8+1;
    static char str[MAX_BUF];
    char *ptr = str+MAX_BUF;
    *--ptr=0;
    if (val>0)
        do{
            *--ptr = val%10+'0';
            val/=10;
            --len;
        }while(val>0);
    else{
        *--ptr='0';
        --len;
    }
    while(len--){
        *--ptr='0';
    }
    return ptr;
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
    const int JAN=31, FEV=28, MAR=31, APR=30, MAY=31, JUN=30, JUL=31, AGO=31, SEP=30, OCT=31, NOV=30, DEC=31;
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
int Date::concat(char * s1, const char * s2, int p){
    //Dado a posição p, concatena s2 a s1 a partir de p.
    char * q = (char*)s2;
    while(*q++);
    int lens2 = q - s2 - 1;
    int i=p;
    for (int j=0; j<lens2; ++i, ++j){
        s1[i] = s2[j];
    }
    return i;
}
const char * Date::getNormDate(const char * sep="/"){
    //Retorna a data normalizada dd/mm/aaaa.
    //O separador podera ser diferente.

    static char datestr[11];
    char * res = datestr+11;
    char *dStr = toStr(day,2);
    int p = concat(res, dStr, 0);
    p = concat(res, sep, p);
    char *mStr = toStr(month,2);
    p = concat(res, mStr, p);
    p = concat(res, sep, p);
    char *yStr = toStr(year,4);
    p = concat(res, yStr, p);
    res[p+1]=0;
    return res;
}
