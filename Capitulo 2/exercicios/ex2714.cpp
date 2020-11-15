#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float x1, x2;
    int a, b, c;

    cout << "Insira os coeficientes da equacao de 2 grau(a b c): " << endl;
    cin >> a >> b >> c;

    x1 = (-b+(sqrt((b*b)-4*a*c)))/(2*a);
    x2 = (-b-(sqrt((b*b)-4*a*c)))/(2*a);

    if (x2>x1){
        float tmp = x1;
        x1 = x2;
        x2 = tmp;
    }

    if (!(isnanf(x1)))
        cout << "Conjunto de solução: {" << x1 << " ; " << x2 << "}" << endl;
    else
        cout << "Nao existe raizes reais" << endl;
    return 0;
}
