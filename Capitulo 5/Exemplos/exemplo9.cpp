#include <iostream>
class Message{
public:
    Message(){std::cout << "Inicio do Programa." << std::endl;}
    ~Message(){std::cout << "Fim do Programa." << std::endl;}
};

Message msg;

int main(){
    std::cout << "MAIN..." << std::endl;
    return 0;
}
