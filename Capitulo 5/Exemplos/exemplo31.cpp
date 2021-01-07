#include "SentList.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(int argc, char ** argv){
    IntList l;
    srand(0);
    clock_t init = clock();
    int arr[]={7,3,2,4,3,1};
    for (int i=0; i<6;++i){
        l.insertNode(arr[i]);
        l.display();
    }
    l.displayAsNode();
    l.removeHead();
    l.display();
    std::cout << "A lista" << (l.contain(10)?" ":" nao ")<< "contem 10." << std::endl;
    std::cout << "A lista" << (l.contain(4)?" ":" nao ")<< "contem 4." << std::endl;
    for (int i=6; i>0; --i){
        l.removeNode(arr[i-1]);
        l.display();
    }
    std::cout << "A lista" << (l.isEmpty()?" ":" nao ") << "esta vazia" << std::endl;
    l.~IntList();
    float secs = (float(clock()-init))/1000;
    std::cout << '\n' << secs << " segundos." << std::endl;
}
