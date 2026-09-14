#include <iostream>
#include "Caixa.h"
using namespace std;

int main() {
    Caixa p1;
    Caixa p2(100, 2.5, 9.2);
    

    cout << "Volume da caixa 1: " << p1.volume() << "\n";
    cout << "Volume da caixa 3: " << p2.volume() << "\n";

    return 0;
}