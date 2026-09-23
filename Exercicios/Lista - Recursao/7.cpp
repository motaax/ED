#include <iostream>

using namespace std;

void decrescente(int n){
    // Se for ímpar, ajusta para o número par menor mais próximo
    if (n % 2 != 0) {
        n = n - 1;
    }

    // Caso base:
    if (n < 0) return;

    cout << n << " ";

    // Caso geral:
    decrescente(n - 2);
}

int main() {
    int n;
    cin >> n;

    decrescente(n);

    cout << "\n";

    return 0;
}