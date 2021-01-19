/** Exercicio 4
 * Usando a classe Time, definida anteriormente, escreva os seguintes programas:
 *  a)  Programa que recebendo através do keyboard duas informações horárias
 *      (strings formatadas), mostre no ecrã uma mensagem indicando o tempo que
 *      medeia entre elas.
 *  b)  Pressupondo que o estacionamento de um carro não ultrapassa os limites de
 *      um dia(entre as zero horas e as 24 horas), e que o preço do estacionamento
 *      obedece ao seguinte preçário:
 *          Até uma hora: 0,50€
 *          De 1 a 7 horas 0,25€ por hora.
 *          Tempo que exceda as 7 horas de  estacionamento 1,00€
 *      Escreva um programa que recolha pelo teclado a informação da hora de 
 *      inicio e fim do estacionamento, indique a quantia a pagar.*/
#include "Time.h"
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

Time askTime(const char * msg){
    std::cout << msg << "(hh:mm:ss): ";
    char s[10];
    std::cin >> s;
    return Time(s);
}

void funcA(){
    Time init = askTime("Hora de Inicio");
    Time end = askTime("Hora de Fim");
    if(!init.isLessThan(end) && !init.isEqual(end)){
        std::cout << "Horas de fim maior que inicio, trocando...." << std::endl;
        Time aux(end);
        end.setTime(init);
        init.setTime(aux);
    }
    int seconds_between = init.theTimeBetween(end);
    int hours = Time(long(seconds_between)).getHour();
    int minutes = Time(long(seconds_between)).getMinute();
    int seconds = Time(long(seconds_between)).getSecond();
    std::cout << "Diferenca de tempo entre ";
    init.printOn();
    std::cout << " e ";
    end.printOn();
    std::cout << " :" << std::endl;
    if (hours)
        std::cout << hours << "h ";
    if (minutes)
        std::cout << minutes << "m ";
    if (seconds)
        std::cout << seconds << "s ";
    if(!hours && !minutes && !seconds)
        std::cout << "0h 0m 0s";
    std::cout << std::endl;
}
void funcB(){
    Time init = askTime("Hora de Inicio");
    Time end =  askTime("Hora de Fim:");
    if(!init.isLessThan(end) && !init.isEqual(end)){
        std::cout << "Horas de fim maior que inicio, trocando...." << std::endl;
        Time aux(end);
        end.setTime(init);
        init.setTime(aux);
    }
    int seconds_between = init.theTimeBetween(end);
    int hours = Time(long(seconds_between)).getHour();
    int minutes = Time(long(seconds_between)).getMinute();
    int seconds = Time(long(seconds_between)).getSecond();
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