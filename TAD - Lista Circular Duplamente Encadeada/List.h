//Felipe Mota Mendes Oliveira - 604804
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>
#include "Node.h"

// Classe TAD List
class List {
private:
    Node* head; // Nó sentinela
    int count;  // Quantidade de elementos armazenados

public:
    // Construtor e Destrutor
    List();
    ~List();

    // Construtor de Cópia
    List(const List& lst);

    // Operações de Modificação
    void push_back(int key);
    int pop_back();
    void insertAfter(int key, int k);
    void remove(int key);
    void removeAll(int key);
    void clear();
    void concat(List& lst);

    // Operações de Consulta e Impressão
    void print() const;
    void printReverse() const;
    bool empty() const;
    int size() const;

    // Operadores Sobrecarregados
    List& operator=(const List& lst);
    bool operator==(const List& lst) const;
    bool operator!=(const List& lst) const;
};

#endif