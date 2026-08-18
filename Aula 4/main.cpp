#include <iostream>
using namespace std;

void inverter(int a[], int ini, int fim) {
    // Caso geral
    if (ini < fim) {
        int aux = a[ini];
        a[ini] = a[fim];
        a[fim] = aux;

        inverter(a, ini + 1, fim - 1);
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

    cout << "Vetor normal: ";
    for (int i = 0; i < n; i++) {
        cout << vet[i] << " ";
    }

    inverter(vet, 0, n - 1);

    cout << "\nVetor invertido: ";
    for (int i = 0; i < n; i++) {
        cout << vet[i] << " ";
    }

    cout << "\n";

    return 0;
}