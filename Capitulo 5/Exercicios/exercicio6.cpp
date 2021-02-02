/** Exercicio 6
 *  Usando a classe DateTime, pedida no exercicio 5:
 *      a)  Reformule o programa da alinea 4.a) acima, por forma a aceitar data e horas
 *          de principio e fim de tarefa
 *      b)  Reformule o programa da alinea 4.b) por forma a deixar de impor limites de 
 *          estacionamento, recebendo informação DateTime de começo e fim
 *  
 *  Os programas devem recusar informações incoerentes, impondo ao utilizador
 *  a devida correcção.
 * 
 *  Para simplificar os metodos publicos, definir os métodos auxiliares privados
 *  que se julguem adequados.*/

#include "DateTime.h"
#include <iostream>
#include <iomanip>
#include <cstring>

typedef const char* arr;
typedef void (*func)();

void funcA();
void funcB();

func funcarr[]={funcA,funcB};

const arr menustr[]={"1 - Tempo entre horarios","2 - Parquimetro","0 - Sair"};

int menu(){
    int escolha, max_len=0;

    for (int i=0;i<3;i++)
        if(max_len < strlen(menustr[i]))
            max_len = strlen(menustr[i])+1;
    
    if(max_len%2)
        max_len++;
    
    do{
        std::cout << '+' <<std::setw((max_len/2)+2) << std::setfill('-') << "Menu" << std::setw((max_len/2)-2) <<'+' << std::endl;
        std::cout << "|" <<menustr[0]<< std::setw(max_len-strlen(menustr[0])) << std::setfill(' ') << "|" << std::endl;
        std::cout << "|" <<menustr[1]<< std::setw(max_len-strlen(menustr[1])) << std::setfill(' ') << "|" << std::endl;
        std::cout << "|" << std::setw(max_len) << std::setfill(' ') << "|" << std::endl;
        std::cout << "|" <<menustr[2]<< std::setw(max_len-strlen(menustr[2])) << std::setfill(' ') << "|" << std::endl;
        std::cout << '+' << std::setw(max_len) << std::setfill('-') << '+' << std::endl;
        std::cout << "Escolha: ";
        std::cin >> escolha;
        if (escolha < 0 || escolha > 2)
            std::cout << "Escolha invalida.\n\n";
    }while(escolha < 0 || escolha > 2);
    return escolha;
}

DateTime askTime(const char * msg){
    char s[20]={""};
    do{
        std::cout << msg << "(yyyy-mm-dd@hh:mm:ss): ";
        std::cin >> s;
    }while(!DateTime().isValid(s));
    return DateTime(s);
}

void funcA(){
    
    DateTime init = askTime("Tempo de Inicio");
    DateTime end = askTime("Tempo de Fim");
    DateTime dt_dif = init.theTimeBetween(end);

    std::cout << "Diferenca de tempo entre ";
    init.printOn();
    std::cout << " e ";
    end.printOn();
    std::cout << " : " << std::endl;
    int i=0;
    
    if((i=dt_dif.getData().getYear()))
        std::cout << i << " ano" << (i>1?"s, ":", ");
    if((i=dt_dif.getData().getMonth()))
        std::cout << i << " mes" <<(i>1?"es, ":", ");
    if((i=dt_dif.getData().getDay()))
        std::cout << i << " dia" << (i>1?"s, ":", ");
    
    if((i=dt_dif.getTime().getHour()))
        std::cout << i << " hora" << (i>1?"s, ":", ");
    if((i=dt_dif.getTime().getMinute()))
        std::cout << i << " minuto" <<(i>1?"s, ":", ");
    if((i=dt_dif.getTime().getSecond()))
        std::cout << i << " segundo" << (i>1?"s, ":", ");

    std::cout << std::endl;
}
void funcB(){
    DateTime init = askTime("Tempo de Inicio");
    DateTime end =  askTime("Tempo de Fim:");
    Time time_dif = init.getTimeBetween(end);
    int hours = time_dif.getHour();
    int minutes = time_dif.getMinute();
    int seconds = time_dif.getSecond();
    if(minutes || seconds)
        hours++;
    float prix=0;
    for (int i = 0; i<hours; i++)
        if (i==0)
            prix=0.5;
        else if (i > 0 && i < 7)
            prix+=0.25;
        else
            prix+=1;
    std::cout << "Pagamento de " << hours << "h corresponde a " << prix << "€" << std::endl;
}

int main(int argc, char ** argv){
    int escolha=0;
    while(1){
        escolha=menu();
        if(!escolha)
            break;
        funcarr[escolha-1]();
    }
    return 0;
}