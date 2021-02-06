#include <cstring>
#include <iostream>
#include <ios>

static bool point=true;

class String{
    char * p;   // Apontador para string
    int size;   // Tamanho da String

    // Metodo auxiliar invocado na construção e na afectaçao
    void init(const char *, int);
public:
    // Construtores
    String(const char * ="");  // Construtor com string
    String(const String &);       // Construtor por cópia
    // Destrutor
    ~String() {delete [] p;}
    // Operador de afetação
    void operator=(const String&);
    void operator=(const char *);
    // Acrescentar à String receptora, a cadeia de caracteres
    // da String que lhe seja passada como parametro 
    void concate(const String &);
    //Compara duas Strings
    bool isEqual(const String &);
    // Retorna a String
    const char * getStr() const {return p;}
    // Retorna o tamanho da String
    int lenght() const          {return size-1;}
    friend std::istream &operator>>( std::istream  &input, String &D );
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
String::String(const String & s){
    init(s.p, s.size);
}
void String::operator=(const String & s){
    if (this != &s){
        delete [] p;
        init (s.p, s.size);
    }
}
void String::operator=(const char * s){
    init(s,strlen(s)+1);
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
bool String::isEqual(const String & other){
    return !strcmp(p, other.p);
}

std::istream &operator>>( std::istream  &input, String &D ){
    char c;
    while((c=input.get())==' ');
    input.putback(c);
    while(c=input.get()){
        if(point){
            if (strchr("\n\t ",c))
                break;
        }else{
           if (strchr("\n\t .,",c))
                break;
        } 
        if (c == EOF){
            input.setstate(std::ios::eofbit);
            break;
        }
        char d[2]={c};
        D.concate(d);
    }
    return input;
}
