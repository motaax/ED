#include <iostream>
using namespace std;

int main() {
    int x = 10;
    //Criando o ponteiro p que aponta para o endereco da variavel x
    int *p = &x;

    cout << x << "\n";
    cout << &x << "\n";
    cout << p << "\n";
    cout << *p << "\n";

    //Muda o valor de 10 para 50 indiretamente
    *p = 50;
    cout << x << "\n";

    return 0;
}