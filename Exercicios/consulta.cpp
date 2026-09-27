#include <iostream>
#include <vector>
#include <string>

using namespace std;

void matchingStrings(vector<string> strings, vector<string> consultas) {
    for (size_t i = 0; i < consultas.size(); i++) {
        int contador = 0;
        
        for (size_t j = 0; j < strings.size(); j++) {
            if (consultas[i] == strings[j]) {
                contador++;
            }
        }
        
        cout << contador;
        
        // Imprime o espaço entre os números
        if (i + 1 < consultas.size()) {
            cout << " ";
        }
    }
    cout << "\n";
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    int q;
    cin >> q;

    vector<string> consultas(q);
    for (int i = 0; i < q; i++) {
        cin >> consultas[i];
    }

    matchingStrings(strings, consultas);

    return 0;
}