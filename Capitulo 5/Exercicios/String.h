#include <cstring>

class String{
    char * p;   // Apontador para string
    int size;   // Tamanho da String

    // Metodo auxiliar invocado na construção e na afectaçao
    void init(const char *, int);
public:
    // Construtores
    String(const char * );  // Construtor com string
    String(String &);       // Construtor por cópia
    // Destrutor
    ~String() {delete [] p;}
    // Operador de afetação
    void operator=(String&);

    // Acrescentar à String receptora, a cadeia de caracteres
    // da String que lhe seja passada como parametro 
    void concate(const String &);
    // Retorna a String
    const char * getStr() const {return p;}
    // Retorna o tamanho da String
    int lenght() const          {return size-1;}
};
void String::init(const char * s, int n){
    p = new char[size=n];
    if (p != NULL){
        strcpy(p,s);
    }
}
String::String(const char * s){
    init(s, strlen(s)+1);
}
String::String(String & s){
    init(s.p, s.size);
}
void String::operator=(String & s){
    if (this != &s){
        delete [] p;
        init (s.p, s.size);
    }
}
void String::concate(const String & s){
    int newsize = lenght() + s.lenght();
    char * aux = new char [size];
    strcpy(aux,p);
    delete [] p;
    p = new char [size=newsize+1];
    strcpy(p, aux);
    strcat(p,s.p);
}
