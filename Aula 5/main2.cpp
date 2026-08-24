#include <iostream>
using namespace std;

// Recursão de cauda
int fatorial(int n, int acumulador) {
    if (n == 0) return acumulador;

    return fatorial(n - 1, n * acumulador);
}

int main() {
    int n;
    cout << "Digite um numero inteiro positivo: ";
    cin >> n;

    cout << fatorial(n, 1) << "\n";

    return 0;
}