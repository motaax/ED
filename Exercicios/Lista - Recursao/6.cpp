#include <iostream>

using namespace std;

void decrescente(int n){
    //Caso base
    if(n < 0) return;

    cout << n << " ";

    //Caso geral
    decrescente(n - 1);

}

int main() {
    int n;
    cin >> n;

    decrescente(n);

    cout << "\n";

    return 0;
}