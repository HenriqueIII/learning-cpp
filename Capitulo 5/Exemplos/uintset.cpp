#include <iostream>
#include <cstring>
#include "uintset.h"

//Construtor de conjunto vazio

UIntSet::UIntSet(){
    memset(vect, 0, sizeof(vect));
}

//construtor a partir de um array de n numeros
UIntSet::UIntSet(u_int * pu, u_int n){
    memset(vect, 0, sizeof(vect));
    for (u_int i=0;i < n;++i){
        insert(pu[i]);
    }
}

//inserir elem no conjunto
void UIntSet::insert(u_int elem){
    vect[elem >> 3] |= 1 << (elem & 0x07);

    /*  É equivalente a:
        u_byte b = elem / 8;    //Indice do byte a afectar
        u_char sh = elem % 8;   //Indice do bit dentro do bit
        //mascara auxiliar no or. Todos os bits a zero menos o bit a afetar.
        u_char mask = 1 << sh;
        vect[b] |= mask;
    */
}

//remover elem do conjunto
void UIntSet::remove(u_int elem){
    //a espressão: ~(1 << (elem & 0x07)) coloca
    //todos os bits a UM, menos o bit a afectar no and
    vect[elem >> 3] &= ~(1 << (elem & 0x07));
}

//Afectar o conjunto res, com o resultado da
//intercepção do conjunto receptor com o conjunto s.

void UIntSet::e(UIntSet & res, const UIntSet & s){
    //AND bit a bit dos bytes dos arrays.
    for (u_int i = 0; i < MAXBYTES;++i){
        res.vect[i] = vect[i] & s.vect[i];
    }
}

void UIntSet::ou(UIntSet & res, const UIntSet & s){
    //OR bit a bit dos bytes dos arrays.
    for (u_int i=0; i< MAXBYTES;++i){
        res.vect[i] = vect[i] | s.vect[i];
    }
}

//Testar se elem pertence ao conjunto
//retornando true se pertencer(se bit a 1).
bool UIntSet::contain(u_int elem) const{
    return (vect[elem >> 3] & (1 << (elem & 0x07))) != 0;
}

//Testar se o conjunto está vazio.
bool UIntSet::empty() const{
    for (u_int i=0; i < MAXBYTES;++i){
        if (vect[i] != 0)
            return false;
    }
    return true;
}

//Mostrar os elementos do conjunto
void UIntSet::display() const{
    //converter todos os bits a UM no unsigned int
    //representado e mostrá-lo no ecrã
    int j;
    u_char mask;
    for (u_int i=0;i<MAXBYTES;++i){
        if (vect[i]){
            for (j=0, mask = 1; j< 8; ++j, mask <<= 1){
                if(vect[i] & mask){
                    std::cout << (u_int(i) * 8 + j) << ' ';
                }
            }
        }
    }
    std::cout << std::endl;
}
