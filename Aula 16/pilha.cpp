#include <iostream>
#include <stack>

using namespace std;

int main() {
    //Cria a pilha
    stack <int> s1;
    int n;
    cin >> n;

    //Lê os valores de n
    for(int i = 1; i <= n; i++) {
        int valor;
        cin >> valor;
        s1.push(valor);
    }

    //Imprime os valores de n e remove
    while(!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }

    cout << "\n";

    return 0;
}