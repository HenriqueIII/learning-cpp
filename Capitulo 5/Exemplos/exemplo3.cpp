#include <iostream>

struct X{
private:
    int m;
public:
    int getM(){
        return m;
    }
    void setM(int n){
        m=n;
    }
};

int main(){
    X xa;
    int a, b;
    xa.setM(6);
    a=xa.getM();
    //b=xa.m; *erro: int X::m e privado, int X::m pode sr acedido via int X::getM();
}
