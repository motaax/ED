#include <iostream>
#include <vector>
using namespace std;

// Funcao iterativa que recebe um vetor de inteiros V e uma chave k
int busca_generica(vector <int> v, int k) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == k) return i;
    }

    return -1;
}

int main() {
    int n, k;

    cout << "Digite o tamanho do vetor: " << "\n";
    cin >> n;

    vector <int> vet(n);

    cout << "Digite os numeros do vetor: " << "\n";

    for(int i = 0; i < vet.size(); i++) {
        cin >> vet[i];
    }

    cout << "Vetor digitado:" << "\n";

    for(int i = 0; i < vet.size(); i++) {
        cout << vet[i] << "\n";
    }

    cout << "Digite a chave que deseja buscar: " << "\n";
    cin >> k;

    int resultado = busca_generica(vet, k);

    if(resultado != -1) {
        cout << "Chave encontrada na posicao: " << resultado << "\n";
    }
    else {
        cout << "Chave nao encontrada." << "\n";
    }

    return 0;
}