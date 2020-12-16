/************************************************************************************
* Na Implementação de um Cojunto de Valores Inteiros Positivos desde 0 a 65532,     *
* vamos representar cada elemento por um bit, por forma a reduzir para 8192 a       *
* dimensao em bytes do array representativo de todos esses valores. Por exemplo,    *
* no byte índice 6 do array, ficarao representadas as presenças(ou ausencias) dos   *
* valores desde 48 a 55. Um zero no bit de peso 16 do byte indice 6 significa a     *
* ausencia do inteiro 52.                                                           *
************************************************************************************/

typedef unsigned char byte;
typedef unsigned int u_int;
typedef unsigned char u_char;
typedef unsigned long u_long;

const u_int BITS_OF_BYTE = 8;
const u_long MAXBITS = (u_long)64*1024; //64 kbit
const u_int MAXBYTES = u_int(MAXBITS/BITS_OF_BYTE); //8k


class UIntSet{
    byte vect[MAXBYTES];                    //array representativo.
public:
    UIntSet();                              //Construtor vazio.
    UIntSet(u_int * pu, u_int n);           //Construtor a partir de um array de n numeros
    void insert(u_int elem);                //Inserir elem no conjunto
    void remove(u_int elem);                //Remover elem no conjunto
    bool contain(u_int elem) const;         //Testa se elem pertence ao conjunto
    void e(UIntSet & res, const UIntSet & s);     //afeta &res , com o resultado da intercepção do conjunto (*this) com o conjunto (s)
    void ou(UIntSet & res, const UIntSet & s);    //afeta &res , com o resultado da união do conjunto (*this) com o conjunto (s)
    bool empty() const;                     //Testa se o conjunto está vazio
    void display() const;                   //Mostra o conjunto
};
