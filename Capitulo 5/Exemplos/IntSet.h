#include "IntDList.h"
#include <iostream>
class IntSet{
    IntDList list; //lista representativa
public:
    IntSet() {};    //construtor de conjunto vazio
    IntSet(int * pu, int n);    //construtor a partir de array
    void insertN(int n){list.insertNode(n);}
    void removeN(int n){list.removeNode(n);}
    void reset(){list.reset();}
    void next(){list.next();}
    int getCurr() const{return list.current();}
    //n pertence a *this
    bool contain(int n){return list.contain(n);}
    bool empty() const {return list.isEmpty();}
    void display(){list.display();}
    void andS(IntSet &res, IntSet &s);  //res = *this && s
    void orS(IntSet &res, IntSet &s);   //res = *this || s
    void clear(){list.removeAll();}
};
IntSet::IntSet(int * pu, int n){
    for (int i=0; i < n; i++){
        insertN(pu[i]);
    }
}
void IntSet::andS(IntSet &res, IntSet &s){
    res.clear();
    list.reset();
    s.list.reset();
    int e, es;
    while (! list.eol() && ! s.list.eol()){
        e = list.current();
        es = s.list.current();
        if(e==es)
            res.insertN(e);
        if(e<=es)
            list.next();
        if(e>=es)
            s.list.next();
    }
}
void IntSet::orS(IntSet &res, IntSet &s){
    res.clear();
    for(list.reset(); ! list.eol(); list.next())
        res.insertN(list.current());
    for(s.list.reset();! s.list.eol(); s.list.next())
        res.insertN(s.list.current());
}
