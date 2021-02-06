#include <iostream>
#include "WordArray.h"

typedef const char * arr;

int main(int argc, char ** argv){
    arr list[]={"Teste", "Teste", "Imagem", "Imagem"};
    WordArray wa2;
    WordArray wa(5);
    for(int i=0; i<4; i++)
        wa2.setValueAt(list[i],i);
    wa2.display();
    wa2.ordArray();
    wa2.display();
    wa2.removeEqual();
    wa2.display();
    return 0;
}