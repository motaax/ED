#include <iostream>
using namespace std;

void troca(int *p1, int *p2) {
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

int main() {
    int x = 10;
    int y = 20;

    cout << "Antes: \n";
    cout << x << "\n";
    cout << y << "\n";
    
    troca(&x, &y);

    cout << "Depois: \n";
    cout << x << "\n";
    cout << y << "\n";

    return 0;
}