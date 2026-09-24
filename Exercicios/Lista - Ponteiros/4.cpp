#include <iostream>
#include <vector>

using namespace std;

void MAX(int n, const vector<vector<int>>& A, int* k, int* l, int* c) {
    // Inicializa k com o primeiro elemento da matriz
    *k = A[0][0];
    *l = 0;
    *c = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] > *k) {
                *k = A[i][j];
                *l = i;
                *c = j;
            }
        }
    }
}

int main() {
    int n = 3;

    vector<vector<int>> A = {
        { 3,  8,  2 },
        { 5, 12,  7 },
        { 1, 12,  4 }
    };

    int k, l, c;

    MAX(n, A, &k, &l, &c);

    cout << "Maior elemento (k): " << k << "\n";
    cout << "Linha (l): " << l << "\n";
    cout << "Coluna (c): " << c << "\n";

    return 0;
}