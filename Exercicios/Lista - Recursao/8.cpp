#include <iostream>

using namespace std;

void primosDecrescente(int n, int divisor = 2) {
    // Caso base:
    if (n < 2) return;

    if (divisor * divisor > n) {
        cout << n << " ";
        primosDecrescente(n - 1, 2);
        return;
    }

    if (n % divisor == 0) {
        primosDecrescente(n - 1, 2);
        return;
    }

    primosDecrescente(n, divisor + 1);
}

int main() {
    int n;
    cin >> n;

    primosDecrescente(n);
    cout << "\n";

    return 0;
}