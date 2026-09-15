#include <iostream>
using namespace std;

int main() {
    int x = 99;

    //Referência
    int &ref = x;

    cout << x << "\n";
    cout << ref << "\n"; //99

    //Alterando o valor de x com referência
    ref = 77;

    cout << x << "\n"; //77

    return 0;
}