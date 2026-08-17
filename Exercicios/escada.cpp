#include <iostream>
using namespace std;

int sobe_escada(int n) {
    //Caso base
    if(n == 1) return 1;

    if(n == 2) return 1;

    if(n == 3) return 2;

    return sobe_escada(n - 1) + sobe_escada(n - 3);
}

int main() {
    int n;
    cin >> n;

    cout << sobe_escada(n) << "\n";

    return 0;
}