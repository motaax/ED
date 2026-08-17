#include <iostream>
using namespace std;

void hanoi(int qte, char ini, char aux, char fim) {
    if(qte == 1) {
        cout << ini << "->" << fim << "\n";
    } else {
        hanoi(qte - 1, ini, fim, aux);

        cout << ini << "->" << fim << "\n";

        hanoi(qte - 1, aux, ini, fim);
    }
}

int main() {
   int qte;
   cin >> qte;
   hanoi(qte, 'A', 'B', 'C');
   return 0;
}