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

    /********************************************************
    *   Exemplo: inserir o numero 32 001 no set             *
    *   vect[32001 >> 3] |= 1 << (32001 & 0x07)             *
    *                                                       *
    *   32.000 base 2 = 0111 1101 0000 0001                 *
    *   32.000 >> 3 = 0000 1111 1010 0000 = 4000            *
    *   vect[4000] = 0000 0000                              *
    *                                                       *
    *   32.000 & 0x07 =                                     *
    *   0111 1101 0000 0001                                 *
    *  &0000 0000 0000 0111                                 *
    *   --------------------                                *
    *   0000 0000 0000 0001                                 *
    *                                                       *
    *   1 << 0000 0000 0000 0001 =                          *
    *   0000 0000 0000 0010                                 *
    *                                                       *
    *   vect[4000]|=0000 0000 0000 0010                     *
    *   se ainda nao tiverem sido introduzidos nums         *
    *   o vect[4000]=0000 0000                              *
    *                                                       *
    *   0000 0000                                           *
    *  |0000 0010                                           *
    *   ---------                                           *
    *   0000 0010                                           *
    *                                                       *
    *   ou seja, quando o byte 4000 tiver o 2 bit a "1"     *
    *   quer dizer que o numero 32.001 pertence ao conjunto *
    *                                                       *
    *                                                       *
    ********************************************************/



    /*  � equivalente a:
        u_byte b = elem / 8;    //Indice do byte a afectar
        u_char sh = elem % 8;   //Indice do bit dentro do bit
        //mascara auxiliar no or. Todos os bits a zero menos o bit a afetar.
        u_char mask = 1 << sh;
        vect[b] |= mask;
    */
}

//remover elem do conjunto
void UIntSet::remove(u_int elem){
    //a espress�o: ~(1 << (elem & 0x07)) coloca
    //todos os bits a UM, menos o bit a afectar no and
    vect[elem >> 3] &= ~(1 << (elem & 0x07));
}

//Afectar o conjunto res, com o resultado da
//intercep��o do conjunto receptor com o conjunto s.

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

//Testar se o conjunto est� vazio.
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
    //representado e mostr�-lo no ecr�
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
