#include <iostream>
using namespace std;

//Função swap usando referência
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int x = 100;
    int y = 200;

    cout << "Antes: \n";
    cout << x << "\n"; //100
    cout << y << "\n"; //200
    
    swap(x, y);

    cout << "Depois: \n";
    cout << x << "\n"; //200
    cout << y << "\n"; //100

    return 0;
}