#include <cstring>
#include <cassert>

class String{
    char * str;
    int cp; //Dimens�o do espa�o reservado para a cadeia
    int len; //Numero de caracteres validos da cadeia

public:
    String(const char *s = NULL, int len = -1); //construtor
    ~String();                                  //Destrutor

    void removeChar(int idx);
    void insertChar(int idx, char c = ' ');
    void assignStr(const char * s, int lenght = -1);
    void assignStr(const String &s);

    //metodos inline
    int lenght() const          {return len;    }
    int capacity() const        {return cp - 1; }
    const char * getStr() const {return str;    }
    void display();

    //construtor por c�pia.
    String(const String &s)             {String(s.str, s.len);      }
    //operador de afecta��o
    String & operator= (const String &s){assignStr(s);return *this; }
};

//Constroi String com string de dimens�o lenght
String::String(const char *s, int lenght){
    len = (lenght != -1 ) ? lenght : (s ? strlen(s):0);
    str = new char [cp = len + 1];
    if(len)
        strncpy(str,s,len);
    str[len]=0;
}

inline String::~String(){
    delete [] str;
}

//Afecta String com lenght chars da cadeia s.
void String::assignStr(const char * s, int lenght){
    if (lenght == -1)
        lenght = (s)?strlen(s):0;
    if (lenght + 1 > cp){               //Se espa�o insuficiente
        delete [] str;                  //Devolve espa�o anterior
        str = new char[cp=lenght+1];    //Reserva novo Espa�o
    }
    if(lenght)
        strncpy(str,s,lenght);          //Copia os caracteres
    str[len=lenght] = 0;                //Terminador de String
}

inline void String::assignStr(const String &s){
    assignStr(s.str,s.len);
}

//Insere o caracter c no indice idx
void String::insertChar(int idx, char c){
    assert(idx <= len && idx >= 0);
    if (len + 1 == cp){
        char * aux = str;
        str = new char[++cp];   //Reserva novo bloco.
        strcpy(str, aux);       //Copia para la a cadeia actual
        delete [] aux;          //Disponibiliza o espa�o anterior
    }
    for (int i=len;i>=idx; --i) //Abre Espa�o
        str[i+1] = str[i];
    str[idx] = c;
    ++len;
}

// Remove o caracter que se situe no indice idx
void String::removeChar(int idx){
    assert(idx < len);
    for (int i = idx; i<len; ++i)
        str[i]=str[i+1];
    --len;
}

// Mostra no console output a cadeia de caracteres.
inline void String::display(){
    std::cout << str << std::endl;
}
