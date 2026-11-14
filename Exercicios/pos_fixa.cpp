#include <iostream>
#include <stack>
#include <string>

using namespace std;

int posFixa(const string &expressao) {
    stack <int> pilha;
    string token = "";

    // Percorre a string até processar o último token
    for (size_t i = 0; i <= expressao.length(); i++) {
        // Se encontrar um espaço ou chegar ao fim da string, processa o token
        if (i == expressao.length() || expressao[i] == ' ') {
            if (!token.empty()) {
                if (token == "+" || token == "-" || token == "*" || token == "/") {
                    int operando1 = pilha.top();
                    pilha.pop();
                    
                    int operando2 = pilha.top();
                    pilha.pop();

                    if (token == "+") pilha.push(operando2 + operando1);
                    else if (token == "-") pilha.push(operando2 - operando1);
                    else if (token == "*") pilha.push(operando2 * operando1);
                    else if (token == "/") pilha.push(operando2 / operando1);
                } else {
                    pilha.push(stoi(token));
                }
                token = ""; // Limpa o token para ler o próximo elemento
            }
        } else {
            // Vai juntando os caracteres até encontrar um espaço
            token += expressao[i];
        }
    }

    return pilha.top();
}

int main() {
    string expressao;
    getline(cin, expressao);

    cout << posFixa(expressao) << "\n";

    return 0;
}