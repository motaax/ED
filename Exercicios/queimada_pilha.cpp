#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int nl, nc, r, c;

    if (!(cin >> nl >> nc >> r >> c)) return 0;

    string mat[100];
    for (int i = 0; i < nl; i++) {
        cin >> mat[i];
    }

    stack<int> pilha_r;
    stack<int> pilha_c;

    // Se a posição possuir '#', queima e empilha
    if (r >= 0 && r < nl && c >= 0 && c < nc && mat[r][c] == '#') {
        mat[r][c] = 'o';
        pilha_r.push(r);
        pilha_c.push(c);
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // Iterar a pilha
    while (!pilha_r.empty()) {
        int cr = pilha_r.top();
        int cc = pilha_c.top();

        bool achou_vizinho = false;

        // Procura o primeiro vizinho queimável
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int n_c = cc + dc[i];

            if (nr >= 0 && nr < nl && n_c >= 0 && n_c < nc && mat[nr][n_c] == '#') {
                mat[nr][n_c] = 'o';
                pilha_r.push(nr);
                pilha_c.push(n_c);
                achou_vizinho = true;
                break; // Empilha e avança na busca
            }
        }

        // Se a lista de vizinhos queimáveis for vazia, realiza o desempilhamento
        if (!achou_vizinho) {
            pilha_r.pop();
            pilha_c.pop();
        }
    }

    for (int i = 0; i < nl; i++) {
        cout << mat[i] << "\n";
    }

    return 0;
}