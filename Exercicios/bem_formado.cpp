#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Função que verifica se a expressão é bem formada
bool bemFormada(const string &expressao) {
    stack<char> pilha;

    for (char c : expressao) {
        // 1. Se leu '(' ou '[', empilha 
        if (c == '(' || c == '[') {
            pilha.push(c);
        } 
        // 2. Se leu ']', verifica se o topo é '[' e desempilha
        else if (c == ']') {
            if (pilha.empty() || pilha.top() != '[') {
                return false; // Malformada[cite: 1]
            }
            pilha.pop();
        } 
        // 3. Se leu ')', verifica se o topo é '(' e desempilha
        else if (c == ')') {
            if (pilha.empty() || pilha.top() != '(') {
                return false; // Malformada
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