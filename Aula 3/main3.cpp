#include <iostream>
using namespace std;

//Funcao recursiva
int fatorial(int n) {
    //Caso base
    if(n == 0) return 1;

    return n * fatorial(n - 1);
}

int main() {
    int n;
    cout << "Digite um numero inteiro positivo: ";
    cin >> n;
    cout << fatorial(n) << "\n";

    return 0;
}