#include <iostream>

using namespace std;

int fibonacci(int n) {
    //Caso base
    if(n <= 0) return 0;
    if(n == 1) return 1;

    //Caso geral
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cin >> n;

    cout << "O " << n << "° termo da sequencia de Fibonacci e: " << fibonacci(n) << "\n";

    return 0;
}