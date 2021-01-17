/**
 * Exercicio 2
 * Usando uma classe Date com a interface acrescida com os metodos definidos
 * no exercicio anterior, escreva os seguintes programas:
 * 
 * a)   Um programa que peça ao utilizador as datas de inicio e fim de uma tarefa e
 *      mostre uma mensagem informando quantos dias uteis durou a tarefa 
 *      (excluindo Sabados e Domingos)
 * b)   Um programa que o convide a informar qual o dia dos seus anos e o informe a
 *      que dia da semana ocorre, no ano corrente.
 * c)   Um programa que mostre no ecrã os dias que medeiam entre a data do seu
 *      nascimento e o dia corrente.
 * 
 * Os programas devem recusar-se a aceitar datas incoerentes, impondo ao utilizador
 * a sua correção
 */

#include <iostream>
#include <iomanip>
#include "date.h"

Date askDate(const char * msg){
    char datastr[11];
    do{
        std::cout << msg;
        std::cin >> datastr;
    }while(!validateDate(datastr));
    return Date(datastr);
}

void errorMsg(const char * msg){
    std::cout << msg << std::endl;
}

bool isWeekend(int weekday){
    if (weekday==SATURDAY || weekday==SUNDAY)
        return true;
    return false;
}

void exercicio2a (){
    Date inicio = askDate("Insira a data de inicio: ");
    Date fim = askDate("Insira a data de fim: ");
    if(!inicio.isLess(fim)){
        errorMsg("Data de fim menor que data de inicio.\n-> Trocando as datas.");
        Date aux(fim);
        fim=inicio;
        inicio=aux;
    }
    int i=1;
    Date aux(inicio);
    while(!aux.isEqual(fim)){
        if (!isWeekend(aux.getWeekDay()))
            i++;
        aux=aux.tomorrow();
    }
    std::cout << "O serviço iniciado a ";
    inicio.displayDate();
    std::cout << " levou " << i << " dias uteis a ser concluido, e terminou a ";
    fim.displayDate();
    std::cout << std::endl;
}

void exercicio2b (){
    int dia, mes;
    //TO-DO: Validar a data;
        std::cout << "\nInsira o dia e o mes que nasceu separados por espaço: ";
        std::cin >> dia >> mes;
    Date aniv(0, mes, dia);
    std::cout << "A data ";
    aniv.displayDate();
    std::cout << " ocorre numa " << aniv.getWeekDayName() << std::endl;
}

void exercicio2c (){
    Date inicio = askDate("Insira a data do seu nascimento: ");
    Date aniv;
    std::cout << "Desde ";
    inicio.displayDate();
    std::cout << " ate ";
    aniv.displayDate();
    std::cout << " ja se passou " << aniv.subNorm(inicio) << " dias." << std::endl;
}

int menu(){
    int escolha;
    do{
        std::cout << '+' <<std::setw(35) << std::setfill('-') << "Menu" << std::setw(32) <<'+' << std::endl;
        std::cout << "|" <<" 1 - Exercicio A, dias que medeiam duas datas. "<< std::setw(20) << std::setfill(' ') << "|" << std::endl;
        std::cout << "|" <<" 2 - Exercicio B, dia da semana neste ano do seu aniversario. " << std::setw(5) << std::setfill(' ') << "|" << std::endl;
        std::cout << "|" <<" 3 - Exercicio C, dias que medeiam entre hoje e o seu nascimento. " << "|" << std::endl;
        std::cout << "|" << std::setw(67) << std::setfill(' ') << "|" << std::endl;
        std::cout << "|" <<" 0 - Sair. " << std::setw(56) << std::setfill(' ') << "|" << std::endl;
        std::cout << '+' << std::setw(67) << std::setfill('-') << '+' << std::endl;
        std::cout << "Escolha: ";
        std::cin >> escolha;
        if (escolha < 0 || escolha > 3)
            std::cout << "Escolha invalida.\n\n";
    }while(escolha < 0 || escolha > 3);
    return escolha;
}

int main(int argc, char ** argv){
    int escolha;
    do{
        escolha = menu();
        switch (escolha)
        {
        case 1:
            exercicio2a();
            break;
        case 2:
            exercicio2b();
            break;
        case 3:
            exercicio2c();
            break;
        default:
            break;
        }
    }while(escolha != 0);
    return 0;
}