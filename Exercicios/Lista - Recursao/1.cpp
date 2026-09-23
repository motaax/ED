#include <iostream>

using namespace std;

void inverte_vet(double vet[], int ini, int fim) {
    //Caso base
    if(ini >= fim) return;

    //Troca os elementos
    double aux = vet[ini];
    vet[ini] = vet[fim];
    vet[fim] = aux;

    //Chamada recursiva
    inverte_vet(vet, ini + 1, fim - 1);
}

int main() {
    int n;
    cin >> n;

    double vet[n];

    //Leitura do vetor
    for(int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    inverte_vet(vet, 0, n - 1);

    //Imprime o vetor
    for(int i = 0; i < n; i++) {
        cout << vet[i] << " ";
    }

    return 0;
}