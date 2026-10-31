#ifndef NODE_H
#define NODE_H

struct Node {
    int value; // variavel que guarda o valor
    Node *next; // ponteiro para o proximo elemento

    Node(int value, Node* next) {
        this->value = value;
        this->next = next;
    }
};

#endif