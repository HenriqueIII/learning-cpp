#include <iostream>
#include "IntArray.h"
#include <cassert>

class IntList{

    struct IntNode{                 //Classe interna para os nós da lista
        int data;
        IntNode *ptNext;
        IntNode( int n ){data=n;ptNext=NULL;}   //Construtor com int n.
    };

    IntNode * ptList; // Apontador para o primeiro nó

    bool find( int val, IntNode * &prev, IntNode * &next) const;
    //Inviabilizar a afectação
    void operator=(const IntList&){}
public:
    // Construtor por cópia
    IntList(const IntList&);
    // Construir uma IntList por cópia de um objecto IntArray
    IntList(const IntArray&);
    IntList(){ ptList=NULL; }   //Iniciar a lista

    ~IntList(){ removeAll();}   //Destruir todos os nós

    bool insertNode(int val);   //Inserir ordenado
    // Inserir ordenado e sem repetição de valores, os
    // elementos da lista idl. Usar um algoritmo eficiente.
    void insert(const IntList & idl);

    bool removeNode(int val);   //Remover se existir

    int removeHead();           //Remover o 1º nó da lista
    int removeTail();           // Remover o último elemento da lista.

    bool contain(int val) const;//Testar se existe val.
    void display() const;       //Apresenta os elementos

    // Testar se as duas listas são iguais (se contêm
    // exatamente os mesmos elementos).
    bool isEqual(const IntList & ) const;
    bool isEmpty() const{       //Testar se a lista esta vazia
        return ptList==NULL;
    }
    
    // Inverter a ordem dos objectos de lista usando um 
    // algoritmo eficiente. A lista fica ordenada por ordem
    // decrescente.
    void invert();
    void swap (IntList & idl); // Trocar o conteúdo das listas;
    
    void removeAll();           //Remover todos os elementos
};

IntList::IntList(const IntList &src){
    ptList=NULL;
    insert(src);
}

IntList::IntList(const IntArray &src){
    ptList=NULL;
    for (int i=0; i < src.size(); i++)
        insertNode(src.getValueAt(i));
}

bool IntList::contain(int val) const{
    IntNode *pt = ptList;       //Apontador para o inicio
    //Enquanto nao chegar ao fim e o corrente for menor
    while(pt && pt -> data < val)
        pt = pt -> ptNext;        //Avança para o sucessor
    return pt && pt -> data == val;
}

bool IntList::find(int val, IntNode* & prev, IntNode* & next) const {

    for(next = ptList, prev = NULL;
        next && next -> data < val;
        prev = next, next = next ->ptNext);

    return next && next->data == val;
}

bool IntList::insertNode(int val){
    IntNode *prev, *next;
    if (find(val, prev, next)){
        return false;   // se existe não insere
    }
    IntNode * n = new IntNode(val); // Reserva a memoria
    if (prev == NULL)
        ptList = n;
    else
        prev -> ptNext = n;

    n -> ptNext = next;
    return true;
}

void IntList::insert(const IntList & src){
    IntNode * pt = src.ptList;
    while(pt){
        insertNode(pt->data);
        pt=pt->ptNext;
    }    
}

bool IntList::removeNode(int val){
    IntNode *prev, *next;
    if ( !find(val, prev, next))
        return false;   // Se nao existe retorna

    if (prev == NULL)
        ptList = next -> ptNext;
    else
        prev -> ptNext = next -> ptNext;
    delete next;
    return true;
}

// Remover o primeiro IntNode, retornando o seu valor
int IntList::removeHead(){
    assert(ptList);             // ptList deve ser diferente de NULL
    IntNode * first = ptList;
    int n = first -> data;      //Valor do primeiro IntNode
    ptList = first -> ptNext;   //Desliga o IntNode da cabeça
    delete first;               //Liberta a memória
    return n;                   //Retorna o valor
}
// Remover o ultimo IntNode, retornando o seu valor
int IntList::removeTail(){
    IntNode * prev=NULL, * next=ptList;
    while(next->ptNext){
        prev=next;
        next = next->ptNext;
    }
    int n = next->data;
    if (prev){
        delete prev->ptNext;
        prev->ptNext=NULL;
    }else{
        delete next;
        ptList=NULL;
    }
    return n;
}

void IntList::invert(){
    IntNode * prev=NULL, * next=ptList, * aux;
    while(next){
        aux = next->ptNext;
        next->ptNext=prev;
        prev = next;
        next = aux;
    }
    ptList=prev;
}

bool IntList::isEqual(const IntList & idl) const{
    IntNode * next = ptList, * idlnext = idl.ptList, * prev=NULL, * idlprev=NULL;
    while(next && idlnext){
        if(next->data!=idlnext->data)
            return false;
        prev=next;
        idlprev=idlnext;
        next=next->ptNext;
        idlnext=idlnext->ptNext;
    }
    if(!next && idlnext || next && !idlnext)
        return false;
    return (prev&&idlprev?prev->data==idlprev->data:true);
}

void IntList::swap(IntList & idl){
    IntNode * aux = ptList;
    ptList = idl.ptList;
    idl.ptList = aux;
}

//Remover todos os nós
void IntList::removeAll(){
    while(!isEmpty())
        removeHead();
}

//Mostrar os valores dos elementos numa linha de texto
void IntList::display() const{
    for(IntNode * pt = ptList;pt;pt=pt->ptNext)
        std::cout << pt -> data << ' ';
    std::cout << std::endl;
}
