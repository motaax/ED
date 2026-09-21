#include <iostream>
#include "vector.h"

using namespace std;

int main() {

    Vector vet;

    // Adiciona elementos
    vet.push_back(9);
    vet.push_back(20);
    vet.push_back(30);

    cout << "Elemento 0: " << vet.at(0) << "\n";
    cout << "Elemento 1: " << vet.at(1) << "\n";
    cout << "Elemento 2: " << vet.at(2) << "\n";

    vet.at(0) = 77;

    cout << "Elemento 0 depois da alteracao: " << vet.at(0) << "\n";
    cout << "Tamanho: " << vet.size() << "\n";
    cout << "Capacidade: " << vet.capacity() << "\n";

    vet.reserve(1000);

    cout << "Capacidade depois do reserve: " << vet.capacity() << "\n";

    // Remove o ultimo elemento
    vet.pop_back();

    cout << "Tamanho depois do pop_back: " << vet.size() << "\n";
    cout << "Vetor vazio? " << (vet.empty() ? "sim" : "nao") << "\n";

    return 0;
}