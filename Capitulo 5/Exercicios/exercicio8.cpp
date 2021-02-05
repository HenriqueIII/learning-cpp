/** 8.  Acrescentar na classe IntArray, os seguintes metodos:
 *      //Mostrar a sequência de inteiros contidos no IntArray.
 *      void display();
 *      // Ordenar por ordem crescente os elementos contidos no
 *      // IntArray, usando o algortimo quickSort().
 *      void ordIntArray();
 *      // Remover os inteiros repetidos.
 *      void removeEqual();
 *  a)  Criar uma função main() que permita o teste dos novos metodos criados.
 */

#include <iostream>
#include "IntArray.h"

int main(int argc, char ** argv){
    int arr1[] = {9,8,7,6,5,4,3,2,1,0};
    int arr2[] = {1,3,4,2,3,1,2,5,1};
    int size2 = 9;
    int size1 = 10;
    IntArray l1(10);
    IntArray l2(9);
    IntArray l3(9);
    for (int i=0; i<size1; i++)
        l1.setValueAt(arr1[i],i);
    for (int i=0; i<size2; i++)
        l2.setValueAt(arr2[i],i);
    for (int i=0; i<size2; i++)
        l3.setValueAt(arr2[i],i);
    l1.ordIntArray();
    l1.display();
    l2.removeEqual();
    l2.display();
    l3.ordIntArray();
    l3.display();
    return 0;
}