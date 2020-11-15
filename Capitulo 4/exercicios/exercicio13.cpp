#include <iostream>
/*Numeros perfeitos, diz se que um numero e perfeito quando a soma dos deus divisores e igual ao proprio numero*/
int divider(int n, int d){ //funçao para ver se n e divisivel por d
    if(n%d==0){
        return d; //se for divisivel retorna o divisor
    }
    return 0; //se nao for divisivel retorna 0, que é um elemento nulo para a subtraçao/divisao.
}
bool perfNumber(int n, int (*func)(int, int)){ //funçao que testa se o nuemro e perfeito, recebe o numero e a funçao comparadora
    int sum=0; //soma dos divisores
    for (int i=1; i<n; i++) //ciclo que esta todos os numeros ate n
        sum += func(n,i); //soma o retorno de divider(int, int) a variavel soma
    if(sum == n){ //testa se a soma e igual ao numero
        return 1; //1 se for perfeito
    }
    return 0; //0 se nao for perfeito
}
int main(){
    std::cout << "Insira um numero: ";
    int number;
    std::cin >> number;
    std::cout << "O numero " << number << " " << (perfNumber(number, divider)?"e'":"nao e'") << "perfeito." << std::endl;
    return 0;
}
