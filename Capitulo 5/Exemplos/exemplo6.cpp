#include <iostream>
#include <cmath>
//definição da classe Complex.
class Complex{
private:
    double r; //Parte real do Complex
    double i; //Parte Imaginaria do Complex
public:
    //Construtor
    Complex (double real=0,double img=0){
        r=real,i=img;
    }
    double getMod() const{
        return sqrt(r*r + i*i);
    }
    friend Complex operator+(const Complex &, const Complex &);
    friend std::ostream& operator<<(std::ostream&, const Complex &);
};

Complex operator+(const Complex &c1, const Complex &c2){
    return Complex(c1.r + c2.r, c1.i + c2.i);
}

std::ostream& operator << (std::ostream & out, const Complex &c){
    return out << '(' << c.r << ((c.i >= 0)? "+":"-") << fabs(c.i) << "i)";
}

//programa
int main(){
    //instancias.
    Complex ca(5.6), cb=Complex(3,2), cd =2, ce;
    ce = ca + cb + cd;
    std::cout << ca << '+' << cb << '+' << cd << '=' << ce << std::endl;
    std::cout << 3 << " + " << cb << " + " << 4.7 << " = " << ( 3 + cb + 4.7) << std::endl;
    return 0;
}
