#include <iostream>
#include <iomanip>

int menu(){
    std::cout << "+"<<std::setw(46)<< std::setfill('-') << "+"<<std::endl;
    std::cout << "| 1 - fibonacci recursivo (print n Elementos) |"<<std::endl;
    std::cout << "| 2 - fibonacci recursivo (n elemento)        |"<<std::endl;
    std::cout << "| 3 - fibonacci iterativo (print n Elementos) |"<<std::endl;
    std::cout << "| 4 - fibonacci iterativo (n elemento)        |"<<std::endl;
    std::cout << "| 0 - Sair                                    |"<<std::endl;
    std::cout << "+"<<std::setw(46)<< std::setfill('-') << "+"<<std::endl;
    int choose;
    std::cin >> choose;
    return choose;
}
void menu_error(){
    std::cout << "Numero Invalido" << std::endl;
}

int fib_r(int n){

    if (n == 1){
        return n;
    }

    if (n==0){
        return n;
    }

    return (fib_r(n-1)+fib_r(n-2));
}

int fib_i(int n){
    int f=1, s=1, soma=0;
    if (n<2)
        return 1;
    for (int i = 2; i <= n; ++i){
        soma = f+s;
        f=s;
        s=soma;
    }
    return soma;
}

int main(){
    int choose, range;
    do{
        choose=menu();

        if (choose && choose < 5){
            std::cout << "Imprimir" << (choose%2==0?" ":" ate' ") << "qual elemento: ";
            std::cin >> range;
        }

        switch (choose){
            case 1:
                for (int i = 1; i<range; i++)
                    std::cout << fib_r(i) << ' ';
            case 2:
                std::cout << fib_r(range) << std::endl;
                break;
            case 3:
                for (int i = 0; i<range-1; i++)
                    std::cout << fib_i(i) << ' ';

            case 4:
                std::cout << fib_i(range-1) << std::endl;
                break;
            case 0:
                break;
            default:
                menu_error();
                break;

        }

    }while(choose!=0);
    return 0;
}
