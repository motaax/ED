#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
    Lista_Encadeada l1; //Cria uma lista vazia

    for(int i = 0; i < 10; i++) {
        l1.push_back(i);
    }

    Lista_Encadeada l2 (l1); //Cria uma lista l2 copiada da lista l1

    l2.print();
    
    return 0;
}