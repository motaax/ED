#include <iostream>
using namespace std;

int main() {
    int *v = new int[100]; //Aloca dinamicamente memoria para o vetor v do tipo int

    delete [] v; //Libera a memoria apontada pelo vetor v
    v = nullptr; //Evita ponteiro "solto"

    return 0;
}