#include <iostream>
#include <cstring>

class String{
    char *p; //apontador para char de arrays
    int capacity; //Dimensão do vector apontado por p.

    //Metodo auxiliar invocado na construçao e na afetaçao
    //void init(const char * s, int n){
    //    p = new char [capacity = n];
    //    if (p != NULL){
    //        strcpy(p, s);
    //    }
    //}

    //inviabilizar a cnstrução por copia e afetação
    String (const String &){};
    void operator=(const String &){};
public:
    String(const char * s){ //construtor
        //std::cout << s << " " << strlen(s) << std::endl;
        if ((p = new char[capacity = strlen(s)+1])!= NULL){
            //std::cout << "Allocating " << s << " in " << p << std::endl;
            strcpy(p,s);
        }
        //std::cout << p << " " << capacity << std::endl;
        //init (s, strlen(s)+1);
    }
    ~String(){
        delete [] p;
    }
    //void operator=(const String & a){//operador de afetação
    //    if (this != &a){
    //        delete [] p;
    //        init(a.p, a.capacity);
    //    }
    //}
    const char * getStr() const{
        return p;
    }
    int lenght() const{
        return capacity-1;
    }
};

void f(){
    String s1("blablabla");
    String s3("hahaha");
    String s2("BluBlu");
    //s1 = s2;
    std::cout << s1.getStr() << ' ' << s2.getStr() << std::endl;
}

void g(){
    String s1("Blabla");
    String s2("blublu");
    //String s2=s1;
    std::cout << s1.getStr() << ' ' << s2.getStr() << std::endl;
}
int main(int argc, char ** argv){
    f();
    g();
    return 0;
}
