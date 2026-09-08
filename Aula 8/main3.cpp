#include <iostream>
using namespace std;

void preencheArray(int *V, int n) {
    for(int i = 0; i < n; i++) {
        cin >> V[i];
    }
}

void imprimeArray(int *V, int n) {
    for(int i = 0; i < n; i++) {
        cout << V[i] << " ";
    }

    cout << "\n";
}

int main() {
    int n;
    cout << "Digite o tamanho do vetor: ";
    cin >> n;

    int *v = new int[n]; //Alocando dinamicamente o vetor

    cout << "Digite os valores: ";
    preencheArray(v, n);
    imprimeArray(v, n);
    
    delete [] v; //Desalocando dinamicamente o vetor
    v = nullptr; //Evita ponteiro "solto"

    return 0;
}