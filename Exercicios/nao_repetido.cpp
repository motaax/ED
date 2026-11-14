#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    string entrada;
    cin >> entrada;

    string saida = "";

    queue<char> fila;
    int freq[26] = {0};

    for (int i = 0; i < (int)entrada.size(); i++) {
        char atual = entrada[i];
        int pos = atual - 'a';

        freq[pos]++;

        if (freq[pos] == 1) {
            fila.push(atual);
        }

        // Remove quem apareceu mais de uma vez
        while (!fila.empty() && freq[fila.front() - 'a'] > 1) {
            fila.pop();
        }

        // Concatena o resultado na string de saida
        if (fila.empty()) {
            saida += '#';
        } else {
            saida += fila.front();
        }
    }

    cout << saida << "\n";

    return 0;
}