#include <iostream>
#include <cmath>
struct Complex{
    double r; //parte real
    double i; //parte Imaginaria
};
//calcular o modulo de Complex
inline double getMod(const Complex c){
    return sqrt(c.r * c.r + c.i * c.i);
}
//construir a estrutura Complex
inline void set (Complex &c, double real=0, double img=0){
    c.r = real;
    c.i = img;
}
//adicionar dois objectos Complex
Complex add (const Complex &c1, const Complex &c2){
    Complex temp;
    set (temp, c1.r+c2.r, c1.i + c2.i);
    return temp;
}
//imprimir o valor de Complex na forma (a + b j)
void print (const Complex & c){
    std::cout << "(";
    if (c.r != 0)
        std::cout << c.r;
    if (c.i != 0)
        if (c.i > 0)
            std::cout << (c.r != 0 ? " + ": "") << c.i << "i)";
        else
            std::cout << (c.r != 0 ? " - ": "") << fabs(c.i) << "i)";
}
int main(){
    Complex ca, cb, cc;
    set (ca, 5, 6);
    set (cb, -2, -2);
    cc = add(ca, cb);
    print (ca);
    std::cout << " + ";
    print (cb);
    std::cout << " = ";
    print (cc);
    std::cout << std::endl;
    std::cout << "Modulo de ";
    print (cc);
    std::cout << " = " << getMod(cc) << std::endl;
    return 0;
}
