#include <iostream>

int strLen(char * p){
    char*q=p;
    while (*q++);
    return q-p-1;
}
void swapI(char &a, char &b){
    char aux=a;
    a=b;
    b=aux;
}

void bubblesort(char * lista, int len){
    //std::cout << std::endl;
    for (int i=len-1; i>0; --i){
        for (int j=0; j<i; ++j){
            //std::cout << lista[j];
            if(lista[j]>lista[j+1])
                swapI(lista[j],lista[j+1]);
        }
        //std::cout << std::endl << lista << std::endl;
    }
    //std::cout << lista <<std::endl;
}

char * duplicates(char * lista, int len){
    int i=0, j=0;
    static char * res;

    if (lista)
        res=lista;

    do{
        if(lista[i]!=lista[i+1]){
            res[j++]=lista[i++];
        }else{
            ++i;
        }
    }while(lista[i]!='\0');

    res[j]='\0';
    return res;
}

int main(){
    std::cout << "Insira uma string: ";
    char arr[15];
    std::cin >> arr;
    std::cout << "A string \"" << arr << "\" ordenada \"";
    bubblesort(arr, strLen(arr));
    std::cout << arr << "\" e sem duplicados e' \"";
    std::cout << duplicates(arr, 13) << "\"." << std::endl;
    return 0;
}
