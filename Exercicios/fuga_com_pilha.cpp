#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

//Navegação
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int main() {
    int linhas, colunas;
    if (!(cin >> linhas >> colunas)) return 0;
    cin.ignore();

    vector <string> labirinto(linhas);
    int inicio = -1, fim = -1;

    for (int r = 0; r < linhas; ++r) {
        getline(cin, labirinto[r]);
        for (int c = 0; c < colunas; ++c) {
            if (labirinto[r][c] == 'I') inicio = r * colunas + c;
            else if (labirinto[r][c] == 'F') fim = r * colunas + c;
        }
    }

    vector <vector<bool>> visitado(linhas, vector <bool>(colunas, false));
    stack <int> pilha;

    visitado[inicio / colunas][inicio % colunas] = true;
    pilha.push(inicio);

    // Busca com a pilha
    while (!pilha.empty() && pilha.top() != fim) {
        int r = pilha.top() / colunas;
        int c = pilha.top() % colunas;
        bool moveu = false;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < linhas && nc >= 0 && nc < colunas &&
                labirinto[nr][nc] != '#' && !visitado[nr][nc]) {
                
                visitado[nr][nc] = true;
                pilha.push(nr * colunas + nc);
                moveu = true;
                break; 
            }
        }

        if (!moveu) {
            pilha.pop();
        }
    }

    // Marca o caminho final com '.' na matriz
    while (!pilha.empty()) {
        int p = pilha.top();
        pilha.pop();
        labirinto[p / colunas][p % colunas] = '.';
    }

    for (int r = 0; r < linhas; ++r) {
        cout << labirinto[r] << "\n";
    }

    return 0;
}