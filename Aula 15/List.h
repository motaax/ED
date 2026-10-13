#ifndef LIST_H
#define LIST_H

#include <iostream>

//Lista duplamente encadeada circular com nó sentinela
class List {
private:
    struct Node {
        int key;
        Node *next;
        Node *prev;
    };

    Node *m_head; //Ponteiro para o nó sentinela
    int m_size;
public:
    //Construtor default
    List() {
        m_size = 0;
        m_head = new Node;
        m_head->key = 0;
        m_head->next = m_head;
        m_head->prev = m_head;
    };

    //Insere um valor no final da lista
    void push_back(int valor) {
        Node *novo = new Node;
        novo->key = valor;
        novo->prev = m_head->prev;
        novo->next = m_head;
        m_head->prev->next = novo;
        m_head->prev = novo;
        m_size++;
    }

    //Imprime na tela todos os elementos
    void print() {
        Node *aux = m_head;
        while(aux->next != m_head) {
            aux = aux->next;
            std::cout << aux->key << "\n";
        }
    }

};

#endif