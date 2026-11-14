#include <iostream>
#include <stack>
#include <string>

using namespace std;

void inverteFrase(string &frase) {
    stack <char> pilha;
    int escrita = 0;

    for (int i = 0; i <= (int)frase.length(); i++) {
        // Se chegou ao fim da string ou encontrou um espaço, desempilha a palavra
        if (i == (int)frase.length() || frase[i] == ' ') {
            while (!pilha.empty()) {
                frase[escrita] = pilha.top();
                pilha.pop();
                escrita++;
            }

            // Se não for o fim da frase, mantém o espaço
            if (i < (int)frase.length()) {
                frase[escrita] = ' ';
                escrita++;
            }
        } else { 
            // Se for uma letra, empilha
            pilha.push(frase[i]);
        }
    }
}

int main() {
    string frase;
    getline(cin, frase);

    inverteFrase(frase);

    cout << frase << "\n";

    return 0;
}