#include <iostream>
using namespace std;

int min(int vet[], int ini, int fim) {
    // Caso base:
    if (ini == fim) {
        return vet[ini];
    } else {
        int min1 = min(vet, ini + 1, fim);

        if (vet[ini] < min1) {
            return vet[ini];
        } else {
            return min1;
        }
    }
}

int main() {
    int n;

    cout << "Digite o tamanho do vetor: ";
    cin >> n;

    int vet[n];

    cout << "Digite os elementos: ";
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    int menor = min(vet, 0, n - 1);

    cout << "Valor minimo do vetor: " << menor << "\n";

    return 0;
}