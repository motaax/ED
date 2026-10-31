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

// Concatenar a lista atual com a lista lst
void ForwardList::concat(ForwardList& lst) {
    if (lst.m_head->next == nullptr) return;

    Node* curr = m_head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = lst.m_head->next;
    m_size += lst.m_size;

    lst.m_head->next = nullptr;
    lst.m_size = 0;
}

// Remove todas as ocorrências do valor 'x' da lista
void ForwardList::remove(int x) {
    Node* curr = m_head;
    while (curr->next != nullptr) {
        if (curr->next->value == x) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            m_size--;
        } else {
            curr = curr->next;
        }
    }
}

// Troca o conteúdo da lista pelo conteúdo de lst
void ForwardList::swap(ForwardList& lst) {
    Node* tempHead = m_head;
    m_head = lst.m_head;
    lst.m_head = tempHead;

    int tempSize = m_size;
    m_size = lst.m_size;
    lst.m_size = tempSize;
}

// Sobrecarga do operador de igualdade
bool ForwardList::operator==(const ForwardList& lst) const {
    if (m_size != lst.m_size) return false;

    Node* p1 = m_head->next;
    Node* p2 = lst.m_head->next;

    while (p1 != nullptr && p2 != nullptr) {
        if (p1->value != p2->value) return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1 == nullptr && p2 == nullptr;
}

// Sobrecarga do operador de diferença
bool ForwardList::operator!=(const ForwardList& lst) const {
    return !(*this == lst);
}

// Reverte a ordem dos elementos da lista
void ForwardList::reverse() {
    if (m_head->next == nullptr || m_head->next->next == nullptr) return;

    Node* prev = nullptr;
    Node* curr = m_head->next;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    m_head->next = prev;
}