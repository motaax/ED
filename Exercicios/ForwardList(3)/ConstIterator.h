#ifndef CONST_ITERATOR_H
#define CONST_ITERATOR_H
#include "Node.h"
 
class ConstIterator {
private:
    Node* m_pointer; // ponteiro para nó
    friend class ForwardList;

public:
    // Construtor default
    ConstIterator() : m_pointer{nullptr} {}

    // Construtor que recebe um ponteiro para Node
    explicit ConstIterator(Node *ptr) : m_pointer{ptr} {}
    
    // Sobrecarga do operator*: retorna o valor que está guardado no nó apontado
    int operator*() const {
        return m_pointer->value;
    }

    // Sobrecarga do operador de pre-incremento
    ConstIterator& operator++() {
        m_pointer = m_pointer->next;
        return *this;
    }

    // Sobrecarga do operador de pós-incremento
    ConstIterator operator++(int) {
        ConstIterator temp(m_pointer);
        m_pointer = m_pointer->next;
        return temp;
    }

    // Sobrecarga do operador==
    bool operator==(const ConstIterator& it) const {
        return m_pointer == it.m_pointer;
    }

    // Retorna true se e somente se são diferentes
    bool operator!=(const ConstIterator& it) const {
        return m_pointer != it.m_pointer;
    }
};

#endif