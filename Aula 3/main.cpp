#include <iostream>
using namespace std;

//Funcao recursiva que calcula a soma dos n primeiros inteiros positivos
//Recebe como entrada o numero n e retorna o valor do somatorio
int soma(int n) { 
    //Caso base 
    if(n == 1) return 1;

    return n + soma(n - 1);
}

int main() {
    int n;
    cout << "Digite um numero inteiro positivo: ";
    cin >> n;
    cout << "S(" << n << ") = " << soma(n) << "\n";

    return 0;
}