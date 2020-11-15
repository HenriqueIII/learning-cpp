#include <iostream>
#include <iomanip>

inline void swapI(int &a, int &b){
    int aux= a;
    a=b;
    b=aux;
}

void bubblesort(int v[], int n){
    int cont=0;
    for(int i=n;i>1;--i){
        int f1=0;
        for (int j=0; j<i-1; ++j){
            if (v[j]<v[j+1]){
                swapI(v[j+1], v[j]);
                f1++;
            }
        }
        if(!(f1)){
            std::cout << "Terminado em " << cont << " passagens." << std::endl;
            return;
        }
        cont++;
    }
    std::cout << "Terminado em " << cont << " passagens." << std::endl;
}

void show(int v[], int n){
    for (int i=0; i<n; ++i){
        std::cout << std::setw(6) << v[i];
        if ((i+1)%12==0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

char atoi(char word[]){
    int num = 0;
    int i=(word[0]=='+'||word[0]=='-');
    for (; word[i]!=0; ++i){
        (num *= 10) += (word[i]-'0');
    }
    if (word[0]=='-')
        num = -num;

    return num;
}

void error(char nome[]){
    std::cout << "Como Usar:" << nome << " int1 int2 ... intN" << std::endl;
    exit(1);
}


int main(int argc, char * argv[]){

    if(argc<2)              //caso nao sejam passados parametros
        error(argv[0]);     //o programa encerra e imprime um prototipo de como usar

    int f[argc-1];          //declara array que vai conter todos os argumentos

    for (int i=0; i < argc-1; ++i){     //atribuiçao de valores convertidos para int
        f[i]=atoi(argv[i+1]);           //da linha de comandos ao array f[]
    }

    bubblesort(f, argc-1);  //ordena array f
    show(f, argc-1);        //mostra array f
}
