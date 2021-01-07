#include <iostream>
#include <cassert>

class IntList{

    class IntNode{                 //Classe interna para os nós da lista
    public:
        int data;
        IntNode *ptNext;
        IntNode( int n, IntNode * next){ // Construir nó
            data=n;
            ptNext=next;
        }
        IntNode(){  // Construir sentinela
            ptNext=this;
        }
    };

    guard = new IntNode; // Nó auxiliar que simplifica algoritmos

    bool find( int val, IntNode * &prev, IntNode * &next) const;
public:
    ~IntList(){ removeAll();}   //Destruir todos os nós
    bool insertNode(int val);   //Inserir ordenado
    bool removeNode(int val);   //Remover se existir
    int removeHead();           //Remover o 1º nó da lista
    bool contain(int val) const;//Testar se existe val.
    void display() const;       //Apresenta os elementos
    bool isEmpty() const{       //Testar se a lista esta vazia
        return guard.ptNext == &guard;
    }
    void removeAll();           //Remover todos os elementos
};

bool IntList::contain(int val) const{
    IntNode *curr = guard.ptNext;       //Apontador para o inicio
    //Enquanto nao chegar ao fim e o corrente for menor
    while(curr -> data < val && curr != &guard)
        curr = curr -> ptNext;        //Avança para o sucessor
    return curr != &guard && curr -> data == val;
}

bool IntList::find(int val, IntNode* & prev, IntNode* & next) const {
    guard.data = val;

    for(next = guard.ptNext, prev = &guard;
        next -> data < val ;
        prev = next, next = next ->ptNext);

    return next != &guard && next->data == val;
}

bool IntList::insertNode(int val){
    IntNode *prev, *next;
    if (find(val, prev, next)){
        return false;   // se existe não insere
    }
    prev -> ptNext = new IntNode(val, next);
    return true;
}

bool IntList::removeNode(int val){
    IntNode *prev, *next;
    if ( !find(val, prev, next))
        return false;   // Se nao existe retorna
    prev -> ptNext = next ->ptNext;
    delete next;
    return true;
}

// Remover o primeiro IntNode, retornando o seu valor
int IntList::removeHead(){
    assert(!isEmpty()); // lista nao deve estar vazia
    IntNode * first = guard.ptNext;
    int n = first -> data;      //Valor do primeiro IntNode
    guard.ptNext = first -> ptNext;   //Desliga o IntNode da cabeça
    delete first;               //Liberta a memória
    return n;                   //Retorna o valor
}

//Remover todos os nós
void IntList::removeAll(){
    IntNode * first;
    while(!isEmpty()){
        first = guard.ptNext;
        guard.ptNext = first -> ptNext;
        delete first;
    }
}

//Mostrar os valores dos elementos numa linha de texto
void IntList::display() const{
    for(IntNode * curr = guard.ptNext ;curr != & guard; curr = curr->ptNext)
        std::cout << curr -> data << ' ';
    std::cout << std::endl;
}
