#ifndef ITERATOR_H
#define ITERATOR_H
#include "Node.h"

class Iterator {
private:
    Node* m_pointer; // ponteiro para nó
    friend class ForwardList;

public:
    // Construtor default
    Iterator() : m_pointer{nullptr} {}

    // Construtor que recebe um ponteiro para Node
    explicit Iterator(Node *ptr) : m_pointer{ptr} {}
    
    // Sobrecarga do operator*: retorna o valor que está guardado no nó apontado
    int& operator*() const {
        return m_pointer->value;
    }

    // Sobrecarga do operador de pre-incremento
    Iterator& operator++() {
        m_pointer = m_pointer->next;
        return *this;
    }

    // Sobrecarga do operador de pós-incremento
    Iterator operator++(int) {
        Iterator temp(m_pointer);
        m_pointer = m_pointer->next;
        return temp;
    }

    // Sobrecarga do operador==
    bool operator==(const Iterator& it) const {
        return m_pointer == it.m_pointer;
    }

    // Sobrecarga do operador!=
    bool operator!=(const Iterator& it) const {
        return m_pointer != it.m_pointer;
    }
};

#endif