//sequencia de fibonacci
//0 1 1 2 3 5 8 13 21
#include <iostream>

void fibonacci(int n, int fib){
    if (n==0)
    {

    }
    if (n==1)
    {

    }
    if (n<1){
        std::cout << fib << " ";
        return;
    }
    fib+=fib;
    std::cout << fib << " ";
    fibonacci(n-1, fib);
}

int main(){
    fibonacci(6, 0);
    return 0;
}
