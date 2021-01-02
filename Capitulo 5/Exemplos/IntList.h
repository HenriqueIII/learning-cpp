#include <iostream>
#include <cassert>

class IntList{

    struct IntNode{                 //Classe interna para os nós da lista
        int data;
        IntNode *ptNext;
        IntNode( int n ){data=n;}   //Construtor com int n.
    };

    IntNode * ptList; // Apontador para o primeiro nó

    bool find( int val, IntNode * &prev, IntNode * &next) const;
    //Inviabilizar a construção por cópia e a afectação
    IntList(const IntList&){}
    void operator=(const IntList&){}

public:
    IntList(){ ptList=NULL; }   //Iniciar a lista
    ~IntList(){ removeAll();}   //Destruir todos os nós
    bool insertNode(int val);   //Inserir ordenado
    bool removeNode(int val);   //Remover se existir
    int removeHead();           //Remover o 1º nó da lista
    bool contain(int val) const;//Testar se existe val.
    void display() const;       //Apresenta os elementos
    bool isEmpty() const{       //Testar se a lista esta vazia
        return ptList==NULL;
    }
    void removeAll();           //Remover todos os elementos
};

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
