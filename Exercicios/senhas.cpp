#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue <int> fila;
    string comando;

    int senha = 1;

    while(cin >> comando) {
        if(comando == "CHEGOU") {
            fila.push(senha);
            senha++;
        } else if(comando == "ATENDER") {
            if(fila.empty()) {
                cout << "Fila vazia" << "\n";
            } else {
                cout << fila.front() << "\n";
                fila.pop();
            }
        } else if(comando == "TAMANHO") {
            cout << fila.size() << "\n";
        }
    }

    return 0;
}