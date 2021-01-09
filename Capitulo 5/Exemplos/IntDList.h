#include <iostream>
class IntDList{

    //Classe interna que declara o nó.
    struct Node{
        int data;
        Node * prev, * next;
        Node(int val, Node * p);
        Node();
        ~Node();
    };

    Node guard; //Nó sentinela
public:
    bool insertNode(int val);
    bool removeNode(int val);
    int removeHead();
    bool contain(int val);
    bool isEmpty() const;
    void display();
    void removeAll();
    ~IntDList();
//Membros que suportam um iterador sobre a lista
private:
    Node * curr;    //Apontador para o nó corrente
public:
    //Iniciar curr com o primeiro nó da lista
    void reset(){
        curr = guard.next;
    }
    //Testar se esta no fim da lista
    bool eol() const{
        return curr == &guard;
    }
    //Avançar para o próximo nó
    void next(){
        curr = curr -> next;
    }
    int current() const{
        return curr -> data;
    }
    void save(int val){
        guard.data = val;
    }
};
//Construtor com dois parametros
inline IntDList::Node::Node(int val, Node * n){
    data = val;
    next = n;
    prev = n -> prev;
    next -> prev = prev -> next = this;
}
//Construtor do nó guard
inline IntDList::Node::Node(){
    next = prev = this;
}
IntDList::Node::~Node(){
    prev -> next = next;
    next -> prev = prev;
}
bool IntDList::insertNode(int val){
    if (contain(val))
        return false;
    new Node(val, curr);
    return true;
}
bool IntDList::removeNode(int val){
    if(!contain(val))
        return false;
    delete curr;
    return true;
}
int IntDList::removeHead(){
    if (!(isEmpty())){
        int val = guard.next -> data;
        delete guard.next;
        return val;
    }
    return 0;
}
bool IntDList::contain(int val){
    save(val);
    reset();
    while(current()<val)
        next();
    return !eol() && current() == val;
}
inline bool IntDList::isEmpty() const{
    return (guard.next==&guard);
}
void IntDList::display(){
    reset();
    while (!eol()){
        std::cout << current() << ' ';
        next();
    }
    std::cout << std::endl;
}
void IntDList::removeAll(){
    while (!isEmpty())
        delete guard.next;
}
inline IntDList::~IntDList(){
    removeAll();
}