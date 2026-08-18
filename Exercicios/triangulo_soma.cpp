#include <iostream>
using namespace std;

void triangulo(int vet[], int n) {
    // Caso base
    if (n == 0)
        return;

    if (n > 1) {
        int soma[n - 1];

        for (int i = 0; i < n - 1; i++) {
            soma[i] = vet[i] + vet[i + 1];
        }

        triangulo(soma, n - 1);
    }

    cout << "[";

    for (int i = 0; i < n; i++) {
        cout << vet[i];

        if (i < n - 1)
            cout << ", ";
    }

    cout << "]\n";
}

int main() {
    int n;
    cin >> n;

    int vet[n];

    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    triangulo(vet, n);

    return 0;
}