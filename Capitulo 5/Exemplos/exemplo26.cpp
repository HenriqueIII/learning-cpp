#include "IntStack.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

const int MAX_VALUE=100;

int main(int argc, char ** argv){
    IntStack s1(1);
    int v;
    for (int i=0; i<MAX_VALUE; i++){
        s1.push(rand() % 100);
    }
    int cont = 0;
    while(!s1.isEmpty()){
        std::cout << std::setw(3) << s1.pop();
        if (!(++cont%39))
            std::cout << std::endl;
    }
    return 0;
}
