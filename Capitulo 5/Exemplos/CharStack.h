class CharStack{
    int size;
    char *top, *buffer;
    //Inviabilizar a constru��o por c�pia e a afecta��o
    CharStack(CharStack &){}
    void operator=(CharStack &){}
public:
    CharStack(int sz){
        top = buffer = new char[size = sz];
    }
    ~CharStack(){
        delete [] buffer;
    }
    void push(char c){
        *top ++ = c;
    }
    char pop(){
        return * --top;
    }
    bool isFull() const{
        return (top-buffer)==size;
    }
    bool isEmpty(){
        return top == buffer;
    }
};
