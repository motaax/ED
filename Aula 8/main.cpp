#include <iostream>
using namespace std;

int main() {
    int *p = new int; //aloca dinamicamente memoria para p do tipo int
    *p = 42;

    cout << *p << "\n"; //42

    delete p; //Libera a memoria apontada por p
    p = nullptr; //evita ponteiro "solto"

    return 0;
}