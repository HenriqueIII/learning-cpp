#include <iostream>
#include <cmath>
struct Complex{
//atributos (membros-dados)
    double r; //parte real do Complex
    double i; //parte Imaginaria do Complex
//metodos (membros-funcoes)
    //construtor
    void set (double real, double img){
        r = real;
        i= img;
    }
    //Calcular o Módulo do Complex
    double getMod() const{
        return sqrt(r*r+i*i);
    }
    //adicão com outro Complex
    Complex add(const Complex &c) const;
    //imprimir Complex
    void print() const;
};

//adicionar com outro Complex
Complex Complex::add (const Complex &c) const{
    Complex temp;
    temp.set (r+c.r, i+c.i);
    return temp;
}
//imprimir o valor de Complex na forma (a + b j)
void Complex::print () const{
    std::cout << "(";
    if (r != 0)
        std::cout << r;
    if (i != 0)
        if (i > 0)
            std::cout << (r != 0 ? " + ": "") << i << "i)";
        else
            std::cout << (r != 0 ? " - ": "") << fabs(i) << "i)";
    else
        std::cout << ")";
}
int main(){
    Complex ca, cb, cc;
    ca.set (5, 6);
    cb.set(-2, -2);
    cc = ca.add(cb);
    ca.print();
    std::cout << " + ";
    cb.print();
    std::cout << " = ";
    cc.print();
    std::cout << std::endl;
    std::cout << "Modulo de ";
    cc.print();
    std::cout << " = " << cc.getMod() << std::endl;
    return 0;
}

