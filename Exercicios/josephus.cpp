#include <iostream>
#include <vector>

using namespace std;

int procurar_proximo_vivo(const vector<bool>& vivos, int size, int pos) {
    int prox = (pos + 1) % size;
    while (!vivos[prox]) {
        prox = (prox + 1) % size;
    }
    return prox;
}

void mostrar_fila(int n, const vector<bool>& vivos, int espada) {
    cout << "[ ";
    for (int i = 0; i < n; ++i) {
        if (vivos[i]) {
            cout << (i + 1);
            if (i == espada) {
                cout << ">";
            }
            cout << " ";
        }
    }
    cout << "]" << endl;
}

int main() {
    int n, e;
    if (!(cin >> n >> e)) return 0;

    vector<bool> vivos(n, true);
    
    // Converte e para índice do vetor
    int espada = e - 1;
    int vivos_restantes = n;

    while (vivos_restantes > 1) {
        mostrar_fila(n, vivos, espada);
        
        int vitima = procurar_proximo_vivo(vivos, n, espada);
        vivos[vitima] = false;
        vivos_restantes--;

        espada = procurar_proximo_vivo(vivos, n, vitima);
    }

    // Resta apenas o vencedor
    mostrar_fila(n, vivos, espada);

    return 0;
}