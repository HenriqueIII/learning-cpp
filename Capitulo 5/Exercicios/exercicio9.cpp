/** 9.  Na classe IntList analisada no texto e que consta do CD-ROM
 *      acrescentar os métodos públicos:
 *          // Construtor por cópia
 *          IntList(const IntList&);
 *          // Construir uma IntList por cópia de um objecto IntArray
 *          IntList(const IntArray&);
 *          // Testar se as duas listas são iguais (se contêm
 *          // exatamente os mesmos elementos).
 *          bool isEqual(const IntList & ) const;
 *          // Inverter a ordem dos objectos de lista usando um 
 *          // algoritmo eficiente. A lista fica ordenada por ordem
 *          // decrescente.
 *          void invert();
 *          // Inserir ordenado e sem repetição de valores, os
 *          // elementos da lista idl. Usar um algoritmo eficiente.
 *          void insert(const IntList &);
 *          int removeTail(); // Remover o último elemento da lista.
 *          void swap (IntList & idl); // Trocar o conteúdo das listas;
 * */

#include <iostream>
#include "IntList.h"

int main(int argc, char ** argv){
    int n [] = {8,2,9,1,7};
    int arr1[] = {9,8,7,6,5,4,3,2,1,0};
    int arr2[] = {9,8,7,6,5,4,3,2,1,0};
    IntArray ia1;
    for (int i=0; i<(sizeof(arr1)/sizeof(arr1[0])); i++)
        ia1.setValueAt(arr1[i],i);
    IntArray ia2;
    for (int i=0; i<2; i++)
        ia2.setValueAt(arr1[i],i);
    IntArray ia3;
    for (int i=0; i<(sizeof(arr2)/sizeof(arr2[0])); i++)
        ia3.setValueAt(arr2[i],i);
    IntList l1(ia2);
    IntList l2(ia1);
    IntList l3(l2);
    IntList l4(ia3);
    std::cout << "l1: ";
    l1.display();
    std::cout << "l2: ";
    l2.display();
    std::cout << "l3: ";
    l3.display();
    std::cout << "l4: ";
    l4.display();
    while (!l1.isEmpty()){
        std::cout << l1.removeTail() << ' ';
    }
    std::cout << '\n';
    std::cout << "swap l1 com l2\n";
    l1.swap(l2);
    std::cout << "l1: ";
    l1.display();
    std::cout << "l2: ";
    l2.display();
    std::cout << "inverter l3\n";
    l3.invert();
    l3.display();
    std::cout << "\nIgualdades\n";
    std::cout << "l1: ";
    l1.display();
    std::cout << "l2: ";
    l2.display();
    std::cout << "l3: ";
    l3.display();
    std::cout << "l4: ";
    l4.display();
    std::cout << "l2 é " << (l2.isEqual(l3)?"igual a":"diferente de") << " l3\n";
    std::cout << "l4 é " << (l4.isEqual(l1)?"igual a":"diferente de") << " l1\n";
    std::cout << "l3 é " << (l3.isEqual(l4)?"igual a":"diferente de") << " l4\n";
    std::cout << "l2 é " << (l2.isEqual(l2)?"igual a":"diferente de") << " l2\n";
}