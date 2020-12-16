class CharSet{
    enum {MAX=256};
    bool vect[MAX];                             // Array de representações
    int n;                                      // numero de elementos do set
public:
    int cardinal() const {
        return n;
    }

    void insert (char c){                       //inserir c(char) e actualizar o numero de elementos
        if(!vect[c]){
            vect[c]=true;
            ++n;
        }
    }

    bool contain (char c) const{                //Testar se c pertence ou não ao conjunto
        return vect[c];
    }

    void remove(char c){                        //remover c(char) e actualizar o numero de elementos
        if(vect[c]){
            vect[c]=false;
            --n;
        }
    }

    void empty();                                //Tornar o conjunto vazio
    void e (CharSet & res, const CharSet & s); //Reunião de conjuntos: res = (*this) and (s)
    void ou (CharSet & res, const CharSet & s);  //Reunião de conjuntos: res = (*this) or (s)
    void display() const;

    CharSet(){                                  //Construtor vazio
        empty();
    }
    CharSet(const char *);                             //Construtor a partir de uma String
};


void CharSet::empty(){
    n=0;
    for (int i=0; i<MAX; ++i){
        vect[i] = 0;
    }
}

CharSet::CharSet(const char * s){
    empty();
    for (int i=0; s[i]; i++){
        insert(s[i]);
    }
}

//intersecção de conjuntos: res = (*this) and (s)

void CharSet::e(CharSet & res, const CharSet & s){
    res.n=0;
    for (int i=0; i < MAX; ++i){
        if(res.vect[i] = vect[i] && s.vect[i] == true)
            ++res.n;
    }
}

//Reunião de conjuntos: res = (*this) or (s)
void CharSet::ou(CharSet & res, const CharSet & s){
    res.n=0;
    for (int i=0;i < MAX; ++i){
        if(res.vect[i] = vect[i] || s.vect[i] == true){
            ++res.n;
        }
    }
}

//Mostrar ordenadamente os caracteres do conjunto
void CharSet::display() const{
    for (int i=0; i < MAX; ++i){
        if(vect[i]){
            std::cout << char(i);
        }
    }
    std::cout << std::endl;
}
