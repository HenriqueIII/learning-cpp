#include <iostream>
#include <iomanip>
class IntList{

    struct Node{ // Classe interna para armazenar nodes
        int data;
        Node * next;
        Node(int val, Node * pt){data = val; next = pt;}
        Node(){next=this;}
    };

    Node head;    //Primeiro nó da lista. next = &head
    bool find(int val, Node* &p, Node* &n);
public:
    IntList(){};
    void insertNode(int val);
    void removeNode(int val);
    bool isEmpty();
    bool contain(int val);
    void removeHead();
    void removeAll();
    void display();
    void displayAsNode();
    ~IntList(){
        removeAll();
    };
};

bool IntList::find(int val, Node* &p, Node* &n){
    head.data=val;
    p=&head;
    n=head.next;
    while(n->data < val){
        p=n;
        n=n->next;
    }
    return n != &head && n->data == val;
}

void IntList::insertNode(int val){
    Node *p, *n;
    if(find(val,p,n)){
        return;
    }
    p->next=new Node(val,n);
}
void IntList::removeNode(int val){
    Node *p,*n;
    if(!find(val,p,n)){
        return;
    }
    p->next=n->next;
    delete n;
}

bool IntList::isEmpty(){
    return head.next==&head;
}

bool IntList::contain(int val){
    Node * curr = head.next;
    while(curr->data != val && curr != &head)
        curr=curr->next;
    return curr!=&head;
}

void IntList::removeHead(){
    if(head.next!=&head){
        Node * aux;
        aux = head.next;
        head.next = aux -> next;
        delete aux;
    }
}

void IntList::removeAll(){
    while(!isEmpty()){
        removeHead();
    }
}

void IntList::display(){
    Node * n = head.next;
    while(n != &head){
        std::cout << n->data << ' ';
        n=n->next;
    }
    std::cout << std::endl;
}

void IntList::displayAsNode(){
    Node * n = head.next;
    int width=23;

    std::cout << '+' << std::setw(width) << std::setfill('-') << '+'<<std::endl;
    std::cout << "||data||"<< std::setfill(' ') << head.next<<"||->"<<std::endl;
    std::cout << '+' << std::setw(width) << std::setfill('-') << '+'<<std::endl;
    std::cout << std::endl;
    while(n != &head){
        std::cout << '+' << std::setw(18) << std::setfill('-') << n <<std::setw(5) << '+'<<std::endl;
        std::cout << "||"<< std::setfill(' ')<< std::setw(4) << n-> data << "||" << n->next <<"||->"<<std::endl;
        std::cout << '+' << std::setw(width) << std::setfill('-') << '+'<<std::endl;
        std::cout << std::endl;
        n=n->next;
    }
    std::cout << std::endl;
}
