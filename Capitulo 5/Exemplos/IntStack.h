#include "IntArray.h"

class IntStack{
    unsigned top;
    IntArray buffer;
public:
    IntStack(unsigned tam) : buffer(tam)    {top = 0;}
    void push(int n)                        {buffer.setValueAt(n, top++);}
    int pop()                               {return buffer.getValueAt(--top);}
    bool isEmpty() const                    {return top == 0;}
};
