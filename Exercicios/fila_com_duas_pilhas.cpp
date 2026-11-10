#include <iostream>
#include <stack>

using namespace std;

// Transfere os elementos do depósito para a prateleira se esta estiver vazia
void transferir(stack<int> &deposito, stack<int> &prateleira) {
    if (prateleira.empty()) {
        while (!deposito.empty()) {
            prateleira.push(deposito.top());
            deposito.pop();
        }
    }
}

int main() {
    stack<int> deposito;
    stack<int> prateleira;

    int q;

    if (!(cin >> q)) return 0;

    while (q--) {
        int tipo;
        cin >> tipo;

        switch (tipo) {
            case 1: {
                int x;
                cin >> x;
                deposito.push(x);
                break;
            }
            case 2:
                transferir(deposito, prateleira);
                if (!prateleira.empty()) {
                    prateleira.pop();
                }
                break;
            case 3:
                transferir(deposito, prateleira);
                if (!prateleira.empty()) {
                    cout << prateleira.top() << "\n";
                }
                break;
            default:
                cout << "operacao invalida!";
                break;
        }
    }

    return 0;
}