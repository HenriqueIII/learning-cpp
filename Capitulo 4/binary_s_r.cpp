#include <iostream>

int bSearch(int v[], int key, int begin, int end){
    if (end < begin)
        return -1;
    int middle = (begin+end)/2;
    if (v[middle]==key)
        return middle;

    if (key < v[middle])
        return bSearch(v, key, begin, middle-1);
    else
        return bSearch(v, key, middle+1, end);
}

int main(){
    int v[]={0,1,2,3,4,5,6,7,8,9};
    int key=8;
    int pos = (bSearch(v, key, 0, 10)-1);
    if (pos < 0)
        std::cout<< key << " nao foi encontrado no seguinte array:"<< std::endl;
    else
        std::cout<< key << " foi encontrado no seguinte array:"<< std::endl;
    for (int i=0; i<10; pos==i++?std::cout << "[" << v[i] << "] ": std::cout << i << " ");
}
