#include <iostream>
using namespace std;

int main() {
    int *p = new int; //Aloca dinamicamente memoria para p do tipo int
    *p = 42;

    cout << *p << "\n"; //42

    delete p; //Libera a memoria apontada por p
    p = nullptr; //Evita ponteiro "solto"

    return 0;
}