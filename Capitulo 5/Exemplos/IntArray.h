#include <iostream>

class IntArray{
    int *v; // apontador para array de inteiros
    unsigned sz;
    // inviabilizar o construtor por copia e afectaçao
    IntArray(const IntArray &){};
    void operator=(const IntArray &){};
public:
    IntArray(unsigned size=0, int val = 0); //Construtor
    ~IntArray(); // destrutor
    int getValueAt (unsigned ind) const;    //retorna v[ind]
    void setValueAt (int value, unsigned ind);  //afecta v[ind]
    void resizeArr(unsigned size, int val=0);
    unsigned size() const { return sz; }
};

IntArray::IntArray(unsigned size, int val){
    v = ((sz = size) == 0) ? NULL : new int[sz];
    while(size){
        v[--size] = val;
    }
}

IntArray::~IntArray(){
    delete [] v; //se v == NULL não faz nada
}

int IntArray::getValueAt(unsigned i) const{
    if (i >= sz ){
        std::cout << "Error: Access out of bounds." << std::endl;
        exit (1);
    }
    return v[i];
}

void IntArray::resizeArr(unsigned size, int val){
    int* p = new int[size]; //reserva novo espaço
    unsigned minSize = sz < size ? sz:size;
    memcpy(p, v, minSize * sizeof(int));    //Copia antigo
    delete [] v;    //Devolve o espaço anterior.
    v = p;  //Actualiza o atributo v
    while(sz < size)
        v[sz++] = val;
    sz = size; // actualiza sz
}

void IntArray::setValueAt(int n, unsigned i){
    if (sz <= i)
        resizeArr(i +1);
    v[i] = n;
}
