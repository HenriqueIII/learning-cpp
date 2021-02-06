#include <iostream>
#include "String.h"

class WordArray{
private:
    String *v;
    int size;
    void swap_e(String &, String &);
    void copy(const String * __src, String * __dest, int n_members);
    void quickSort(int,int);
public:
    WordArray(int=0);
    ~WordArray();
    void display(); //Mostra a sequência de Strings contidas no array
    String getValueAt (unsigned ind) const;    //retorna v[ind]
    void setValueAt (const char * s, unsigned ind);  //afecta v[ind] com const char *
    void setValueAt (const String & s, unsigned ind);  //afecta v[ind] com String
    void deleteValueAt (int ind);
    void resizeArr(unsigned size);
    unsigned getSize() const { return size; }
    // Ordenar por ordem crescente os elementos contidos no
    // IntArray, usand o algoritmo quickSort().
    void ordArray();
    // Remover as Strings repetidas.
    void removeEqual();
};
void WordArray::copy(const String * __src, String * __dest, int n_members){
    if(&__src == &__dest)
        return;
    for (int i = 0; i < n_members; i++){
        __dest[i]=__src[i];
    }
}

void WordArray::quickSort(int init, int end){
    if (init >= end)
        return;
    int j = init;
    for (int i=init; i < end; i++)
        if(strcmp(v[i].getStr(), v[end].getStr())<=0)
            swap_e(v[i],v[j++]);
    swap_e(v[j],v[end]);
    quickSort(init, j-1);
    quickSort(j+1, end);

}

WordArray::WordArray(int sz){
    v = ((size=sz)==0) ? NULL : new String [size=sz];
    while(sz){
        v[--sz]="";
    }
}

WordArray::~WordArray(){
    delete [] v;
}

void WordArray::display(){
    for (int i=0;i<size;i++)
        if(strlen(v[i].getStr()))
            std::cout <<v[i].getStr() << " ";
    std::cout << "\n";
}

String WordArray::getValueAt(unsigned ind) const{
    if(ind>=size){
        std::cout << "Access out of bounds\n";
        exit(1);
    }
    return v[ind];
}
void WordArray::setValueAt(const char * s, unsigned ind){
    if(size <= ind){
        resizeArr(ind+1);
    }
    v[ind]=s;
}
void WordArray::setValueAt(const String & s, unsigned ind){
    if(size <= ind){
        resizeArr(ind+1);
    }
    v[ind]=s;
}
void WordArray::resizeArr(unsigned sz){
    String * p = new String[sz];
    copy(v,p,size);
    delete [] v;
    v=p;
    while(size<sz)
        v[size++]="";
    size=sz;
}
inline void WordArray::swap_e(String &a, String &b){
    if(&a!=&b){
        String aux = a;
        a=b;
        b=aux;
    } 
}
void WordArray::deleteValueAt(int ind){
    if(size<1)
        return;
    for(int i = ind; (i+1) < size; ++i)
        swap_e(v[i],v[i+1]);
    resizeArr(--size);
}
void WordArray::removeEqual(){
    for (int i = 0; i < size; i++)
        for (int j = size-1; j > i; --j)
            if (!strcmp(v[i].getStr(),v[j].getStr()))
                deleteValueAt(j);
}
void WordArray::ordArray(){
    quickSort(0,size-1);
}