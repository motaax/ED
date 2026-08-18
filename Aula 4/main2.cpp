#include <iostream>
using namespace std;

int max(int vet[], int ini, int fim) {
    //Caso base
    if(ini == fim) {
        return vet[ini];
    } else {
        int max1 = max(vet, ini + 1, fim);

        if(vet[ini] > max1) {
            return vet[ini];
        } else {
            return max1;
        }
    }

    return max(vet, ini, fim);
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

    int maior = max(vet, 0, n - 1);

    cout << "Valor maximo do vetor: ";
    
    cout << maior << "\n";

    return 0;
}