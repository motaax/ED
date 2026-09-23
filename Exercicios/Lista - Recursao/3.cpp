#include <iostream>

using namespace std;

int fat_duplo(int n) {
    // Caso base para números pares ou negativos
    if (n % 2 == 0 || n < 0) {
        return -1;
    }

    // Caso base para números ímpares
    if (n == 1) {
        return 1;
    }

    // Caso geral
    return n * fat_duplo(n - 2);
}

int main() {
    int n;
    cin >> n;

    int resultado = fat_duplo(n);

    if (resultado == -1) {
        cout << "Erro!\n";
    } else {
        cout << "O fatorial duplo de " << n << " e: " << resultado << "\n";
    }

    return 0;
}