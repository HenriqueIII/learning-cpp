#include <iostream>
using namespace std;

int main(){
    const float pi = 3.14159265F;
    int radius;
    float area;
    cout<<"Qual � o raio do circulo?";
    cin>>radius;
    area=pi *(radius*radius);
    cout<< "A area do circulo � "<<area<<endl;
    return 0;
}
