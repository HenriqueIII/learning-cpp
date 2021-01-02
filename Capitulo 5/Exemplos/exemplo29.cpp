#include "IntList.h"

int main(int argc, char ** argv){
    int n [] = {8,2,9,1,7}, i;
    IntList l1;
    for(i=0;i<5;++i){
        l1.insertNode(n[i]);
        l1.display();
    }
    for (i=4;i>=0; -- i){
        l1.removeNode(n[i]);
        l1.display();
    }
    return 0;
}
