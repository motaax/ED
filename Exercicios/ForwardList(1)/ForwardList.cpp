#include "ForwardList.h"

// Retorna uma referência para o primeiro elemento da lista
int& ForwardList::front() {
    return m_head->next->value;
}

// Retorna uma referência constante para o primeiro elemento da lista
const int& ForwardList::front() const {
    return m_head->next->value;
}

// Retorna uma referência para o último elemento da lista
int& ForwardList::back() {
    Node* curr = m_head->next;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    return curr->value;
}

// Retorna uma referência constante para o último elemento da lista
const int& ForwardList::back() const {
    Node* curr = m_head->next;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    return curr->value;
}

// Insere um elemento no final da lista
void ForwardList::push_back(int val) {
    Node* curr = m_head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = new Node(val, nullptr);
    m_size++;
}

// Deleta o último elemento da lista
void ForwardList::pop_back() {
    if (m_head->next == nullptr) return; // Lista vazia

    Node* curr = m_head;
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
    m_size--;
}

// Construtor de cópia
ForwardList::ForwardList(const ForwardList& lst) {
    m_head = new Node(0, nullptr);
    m_size = 0;
    
    Node* tail = m_head;
    Node* curr = lst.m_head->next;
    
    while (curr != nullptr) {
        tail->next = new Node(curr->value, nullptr);
        tail = tail->next;
        curr = curr->next;
        m_size++;
    }
}