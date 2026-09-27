#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> fila(n);
    for (int i = 0; i < n; i++) {
        cin >> fila[i];
    }

    int m;
    cin >> m;

    vector<int> sairam(m);
    for (int i = 0; i < m; i++) {
        cin >> sairam[i];
    }

    // Percorre a fila original
    for (int i = 0; i < n; i++) {
        bool pessoa_saiu = false;

        // Verifica se a pessoa i esta na lista de quem saiu
        for (int j = 0; j < m; j++) {
            if (fila[i] == sairam[j]) {
                pessoa_saiu = true;
                break;
            }
        }

        // Se a pessoa nao saiu, imprime o numero seguido de um espaco
        if (!pessoa_saiu) {
            cout << fila[i] << " ";
        }
    }

    cout << endl;

    return 0;
}