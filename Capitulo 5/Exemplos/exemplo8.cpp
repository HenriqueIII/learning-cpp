#include <iostream>

class Spy{
    int s;
public:
    Spy (int ss)    {std::cout << "Inicio - " << (s = ss) << std::endl;}
    ~Spy()          {std::cout << "Fim -" << s << std::endl;}
};

int factorial(int n){
    Spy s(n);
    return (n > 1) ? n*factorial (n-1) : 1;
}

int main(){
    std::cout << factorial(5) << std::endl;
    return 0;
}
