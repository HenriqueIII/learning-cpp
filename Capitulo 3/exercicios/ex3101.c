#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int x=80, z=(x-=2);
    long y = x * 02000 * 0x400;
    char c1 = x+2, c2=(c1==80)?'z':z;

    cout << "\a\"Trabalho Pr\240tico I\"\nx=" << x << " y = 0x" << hex << y << " z+2 = 0" << oct << z+2;
    cout << '\n' << "c1 = \'" << c1 << "\'\tc2 = \'" << c2 << '\'' << endl;
    return 0;
}
