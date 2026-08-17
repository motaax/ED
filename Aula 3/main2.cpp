#include <iostream>
using namespace std;

// Função recursiva
void print_asterisco(int n) {
    // Caso base
    if (n == 0) {
        cout << "\n";
        return;
    }

    cout << "*";
    print_asterisco(n - 1);
}

int main() {
    int n;
    cout << "Digite um numero inteiro positivo: ";
    cin >> n;

    print_asterisco(n);

    return 0;
}