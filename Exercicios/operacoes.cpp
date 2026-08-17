#include <iostream>
#include <vector>
using namespace std;

void imprime(const vector<int>& v, int i) {
    if (i == (int)v.size()) return;

    cout << v[i];
    if (i + 1 < (int)v.size())
        cout << " ";

    imprime(v, i + 1);
}

void imprimeReverso(const vector<int>& v, int i) {
    if (i < 0) return;

    cout << v[i];
    if (i > 0)
        cout << " ";

    imprimeReverso(v, i - 1);
}

int soma(const vector<int>& v, int i) {
    if (i == (int)v.size())
        return 0;

    return v[i] + soma(v, i + 1);
}

int multiplicacao(const vector<int>& v, int i) {
    if (i == (int)v.size())
        return 1;

    return v[i] * multiplicacao(v, i + 1);
}

int menor(const vector<int>& v, int i) {
    if (i == (int)v.size() - 1)
        return v[i];

    int m = menor(v, i + 1);
    return v[i] < m ? v[i] : m;
}

void troca(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void inverte(vector<int>& v, int inicio, int fim) {
    if (inicio >= fim)
        return;

    troca(v[inicio], v[fim]);
    inverte(v, inicio + 1, fim - 1);
}

int main() {
    vector<int> vet;
    int x;

    while (cin >> x) {
        vet.push_back(x);
    }

    cout << "vet : [ ";
    imprime(vet, 0);
    cout << " ]\n";

    cout << "rvet: [ ";
    imprimeReverso(vet, vet.size() - 1);
    cout << " ]\n";

    cout << "sum : " << soma(vet, 0) << "\n";
    cout << "mult: " << multiplicacao(vet, 0) << "\n";
    cout << "min : " << menor(vet, 0) << "\n";

    inverte(vet, 0, vet.size() - 1);

    cout << "inv : [ ";
    imprime(vet, 0);
    cout << " ]\n";

    return 0;
}