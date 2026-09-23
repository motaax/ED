#include <iostream>

using namespace std;

int fat(int n) {
    //Caso base
    if(n == 0) return 1;

    //Caso geral
    return n * fat(n - 1);
}

int main() {
    int n;
    cin >> n;

    cout << "O fatorial de " << n << " e: " << fat(n) << "\n";

    return 0;
}