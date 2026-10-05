#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
    Lista_Encadeada lista; //Cria uma lista vazia

    lista.push_front(3);
    lista.push_front(2);
    lista.print();

    return 0;
}