#include <iostream>
#include <iomanip>

int main(int argc, char ** argv){
    bool isprime=true;
    int num=1;
    for (int i = 2;i<100000;i++){

        for (int j=2; j<i-1;j++)

            if (i%j==0){
                isprime=false;
                break;
            }

        if (isprime){
            std::cout << std::setw(7) << i;
            num++;
        }
        if(num%21==0){
            num=1;
            std::cout << std::endl;
        }
        isprime=true;
    }
    std::cout << std::endl;
    return 0;
}