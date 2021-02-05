#include <iostream>
#include <cstring>

class IntArray{
    int *v; // apontador para array de inteiros
    unsigned sz;
    // inviabilizar o construtor por copia e afecta�ao
    IntArray(const IntArray &){};
    void operator=(const IntArray &){};
    void quickSort(int, int);
    void swap_e(int &, int &);
public:
    IntArray(unsigned size=0, int val = 0); //Construtor
    ~IntArray(); // destrutor
    int getValueAt (unsigned ind) const;    //retorna v[ind]
    void setValueAt (int value, unsigned ind);  //afecta v[ind]
    void deleteValueAt (int ind);
    void resizeArr(unsigned size, int val=0);
    unsigned size() const { return sz; }
    // Mostrar a sequência de inteiros contidos no IntArray.
    void display();
    // Ordenar por ordem crescente os elementos contidos no
    // IntArray, usand o algoritmo quickSort().
    void ordIntArray();
    // Remover os inteiros repetidos.
    void removeEqual();
};

IntArray::IntArray(unsigned size, int val){
    v = ((sz = size) == 0) ? NULL : new int[sz];
    while(size){
        v[--size] = val;
    }
}

IntArray::~IntArray(){
    delete [] v; //se v == NULL n�o faz nada
}

int IntArray::getValueAt(unsigned i) const{
    if (i >= sz ){
        std::cout << "Error: Access out of bounds." << std::endl;
        exit (1);
    }
    return v[i];
}

void IntArray::resizeArr(unsigned size, int val){
    int* p = new int[size]; //reserva novo espa�o
    unsigned minSize = sz < size ? sz:size;
    memcpy(p, v, minSize * sizeof(int));    //Copia antigo
    delete [] v;    //Devolve o espa�o anterior.
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
void IntArray::display(){
    for (int i=0; i < sz; i++)
        std::cout << v[i] << ' ';
    std::cout << '\n';
}
void IntArray::ordIntArray(){
    quickSort(0, sz-1);
}
//Função quickSort()
void IntArray::quickSort(int init, int end){
    if (init >= end)
        return;
    int j = init;
    for (int i=init; i < end; i++)
        if(v[i] <= v[end])
            swap_e(v[i],v[j++]);
    swap_e(v[j],v[end]);
    quickSort(init, j-1);
    quickSort(j+1, end);

}
//Função auxiliar para fazer troca de elementos
inline void IntArray::swap_e(int &a, int &b){
    if(&a!=&b){
        a = a + b;
        b = a - b;
        a = a - b;
    } 
}
void IntArray::removeEqual(){
    for (int i = 0; i < sz; i++)
        for (int j = sz-1; j > i; --j)
            if (v[i]==v[j])
                deleteValueAt(j);
}

//Função para remover o elemento na posição ind
void IntArray::deleteValueAt(int ind){
    // Evitar que size adquira valores negativos 
    if(sz<1)
        return;
    for(int i = ind; (i+1) < sz; ++i)
        swap_e(v[i],v[i+1]);
    sz--;
    int * p = new int[sz];
    memcpy(p,v,sz*sizeof(int));
    delete [] v;
    v=p;
}