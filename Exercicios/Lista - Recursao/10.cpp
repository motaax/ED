#include <iostream>

using namespace std;

void binario(int n) {
    if (n > 1) {
        binario(n / 2);
    }
    
    cout << n % 2;
}

int main() {
    int n;
    cin >> n;
    
    cout << "O numero " << n << " em binario e: ";
    if (n == 0) {
        cout << 0;
    } else {
        binario(n);
    }
    cout << "\n";
    
    return 0;
}