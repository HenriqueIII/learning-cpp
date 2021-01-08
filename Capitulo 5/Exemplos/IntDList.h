class IntDList{

    //Classe interna que declara o nó.
    struct Node{
        int data;
        Node * prev;
        Node * next;
        Node(int val, Node * p, Node * n){
            data = val;
            prev = p;
            next = n;
        }
        Node(){
            prev=this;
            next=this;
        }
    };

    Node guard; //Nó sentinela
    
};