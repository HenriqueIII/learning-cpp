#include <iostream>

class CharPtr{
    char * ptr;                             //Atributo Dinamico
public:
    CharPtr(int len){ptr = new char[len];}  //construtor
    ~CharPtr()      {delete [] ptr;}        //destrutor
    char *getPtr()  {return ptr;}           //apontador
    void print(){
        std::cout << ptr << std::endl;
    }
    friend std::ostream& operator<<(std::ostream &, CharPtr &);
    void setPtr(const char * str){
        int i=0;
        for (;*str; *str++, i++){
            ptr[i] = *str;
        }
        ptr[i]=0;
    }
};

std::ostream & operator<<(std::ostream & out, CharPtr & p){
    return out << p.ptr;
}

void f1(){
    CharPtr p(1000);
    p.setPtr("Teste");
    std::cout << p << std::endl;
}


int main(){
    f1();
    return 0;
}
