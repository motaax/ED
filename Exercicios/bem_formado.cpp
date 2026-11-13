#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Função que verifica se a expressão é bem formada
bool bemFormada(const string &expressao) {
    stack<char> pilha;

    // Percorre cada caractere 'c' dentro da string 'expressao'
    for (char c : expressao) {
        // 1. Se leu '(' ou '[', empilha o símbolo lido[cite: 1]
        if (c == '(' || c == '[') {
            pilha.push(c);
        } 
        // 2. Se leu ']', verifica se o topo é '[' e desempilha[cite: 1]
        else if (c == ']') {
            if (pilha.empty() || pilha.top() != '[') {
                return false; // Malformada[cite: 1]
            }
            pilha.pop();
        } 
        // 3. Se leu ')', verifica se o topo é '(' e desempilha[cite: 1]
        else if (c == ')') {
            if (pilha.empty() || pilha.top() != '(') {
                return false; // Malformada[cite: 1]
            }
            pilha.pop();
        }
    }

    return pilha.empty();
}

int main() {
    string expressao;
    getline(cin, expressao);

    if (bemFormada(expressao)) {
        cout << "Bem-formada" << "\n";
    } else {
        cout << "Malformada" << "\n";
    }

    return 0;
}