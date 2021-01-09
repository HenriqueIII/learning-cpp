#include <cmath>
#include <iostream>

int main(int argc, char ** argv){
    float param, res, res2;
    param = 2;
    res = std::roundf(sqrt(param));
    res2 = sqrt(param);
    std::cout << res << ' ' << res2 << std::endl;
    return 0;
}