class IntList{

    struct IntNode{                 //Classe interna para os n�s da lista
        int data;
        IntNode *ptNext;
        IntNode( int n ){data=n;}   //Construtor com int n.
    };

    IntNode * ptList; // Apontador para o primeiro n�

    bool find( int val, IntNode * &prev, IntNode * &next) const;
    //Inviabilizar a constru��o por c�pia e a afecta��o
    IntList(const IntList&){}
    void operator=(const IntList&){}

public:
    IntList(){ ptList=NULL; }   //Iniciar a lista
    ~IntList(){ removeAll();}   //Destruir todos os n�s
    bool insertNode(int val);   //Inserir ordenado
    bool removeNode(int val);   //Remover se existir
    int removeHead();           //Remover o 1� n� da lista
    bool contain(int val) const;//Testar se existe val.
    void display() const;       //Apresenta os elementos
    bool isEmpty() const{       //Testar se a lista esta vazia
        return ptList==NULL
    }
    void removeAll();           //Remover todos os elementos
};

bool IntList::contain(int val) const{
    IntNode *pt = ptList;       //Apontador para o inicio
    //Enquanto nao chegar ao fim e o corrente for menor
    while(pt && pt -> data < val)
        pt = pt -> ptNext;        //Avan�a para o sucessor
    return pt && pt -> data == val;
}


