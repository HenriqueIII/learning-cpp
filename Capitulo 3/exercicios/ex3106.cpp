#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double num;
    cout << "Insira um numero fracionario -> ";
    cin >> num;

    cout << "NUM\tArred Unid.\tArred Dec.\tArred Cent.\tArred Mil." << endl;
    cout << setw(8) << num << fixed << setw(11) << setprecision(0) << num << '\t' << setw(10) << setprecision(1) << num <<"\t" << setw(11) << setprecision(2) << num << '\t' << setw(10) << setprecision(3) << num << '\t' << endl;
}
