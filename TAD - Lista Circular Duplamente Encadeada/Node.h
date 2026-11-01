//Felipe Mota Mendes Oliveira - 604804
#ifndef NODE_H
#define NODE_H

// Estrutura que representa cada nó da lista
struct Node {
    int key;
    Node* prev;
    Node* next;

    Node(int k = 0, Node* p = nullptr, Node* n = nullptr): key(k), prev(p), next(n) {}
};

#endif