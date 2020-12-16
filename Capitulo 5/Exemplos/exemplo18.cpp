#include <iostream>

class X{
    int i;
public:
    X()         {i=0;std::cout << "Construtor default."<<std::endl;}
    X(int ii)   {i=ii;std::cout << "Construtor (" << i << ')' << std::endl;}
    ~X()        {std::cout << "Destrutor (" << i <<')' << std::endl;}
};

int main(int argc, char ** argv){
    std::cout << "Entrada em main()" << std::endl;
    //Criar um objecto alojado dianamicamente.
    std::cout << "Operacao new X(5)" << std::endl;
    X * px = new X(5); //construtor com parametro
    std::cout << "Operacao delete *px." << std::endl;
    delete px;
    //Criar um array de objectos dinamicamente,
    std::cout << "Operacao new X[5]" << std::endl;
    px = new X[5]; // construtor sem parametros.
    std::cout << "Operacao delete [] px" << std::endl;
    delete [] px;
    std::cout << "Saida de main()" << std::endl;
    return 0;
}
