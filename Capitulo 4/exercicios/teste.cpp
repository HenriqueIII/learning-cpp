#include <iostream>

int main(){
    int bit = 2;
    for (int n=0; n<= 10; n++)
        std::cout <<  (n & bit) << ' ';
    std::cout << std::endl;
}
