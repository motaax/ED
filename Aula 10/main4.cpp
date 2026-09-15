#include <iostream>
using namespace std;

//Função usando const e referência
int soma(const int &x, const int &y) {
    return x + y;
}

int main() {
    cout << soma(4, 5) << "\n"; //funciona por causa do const

    int a = 10;
    int b = 40;
    cout << soma(a, b) << "\n";

    return 0;
}