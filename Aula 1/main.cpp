#include <iostream>
using namespace std;

//Data: 10/08/2026
int main() {
    int x = 100;
    unsigned int y = -2; //Reduz o intervalo de valores que o tipo int suporta
    float z = (float) 23 / 4; //Casting 

    cout << "Hello world!\n"; 
    cout << y << "\n";
    cout << sizeof(x) << "\n"; //Exibe o tamanho do tipo int
    cout << z << "\n";

    return 0;
}