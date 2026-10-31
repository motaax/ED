#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include "Iterator.h"
#include "ConstIterator.h"
#include "Node.h"
#include <iostream>

class ForwardList {
private:
    Node* m_head; // ponteiro para o sentinela
    int m_size;   // numero de elementos na lista

public:
    // retorna um Iterator apontando para o primeiro elemento
    Iterator begin() {
        return Iterator(m_head->next);
    }

    // retorna um Iterator apontando para a posicao anterior ao primeiro elemento
    Iterator before_begin() {
        return Iterator(m_head);
    }

    // retorna um Iterator para a posicao após o ultimo elemento
    Iterator end() {
        return Iterator(nullptr);
    }

    // retorna um ConstIterator apontando para o primeiro elemento da lista
    ConstIterator begin() const {
        return ConstIterator(m_head->next);
    }

    // retorna um ConstIterator apontando para a posicao anterior ao primeiro elemento da lista
    ConstIterator before_begin() const {
        return ConstIterator(m_head);
    }

    // retorna um ConstIterator para a posicao apos o ultimo elemento
    ConstIterator end() const {
        return ConstIterator(nullptr);
    }

    // Construtor default: cria lista vazia
    ForwardList() {
        m_head = new Node(0, nullptr);
        m_size = 0;
    }

    // Insere um elemento no inicio da lista
    void push_front(int val) {
        Node *aux = new Node(val, m_head->next);
        m_head->next = aux;
        m_size++;
    }

    // Funcao que remove o primeiro elemento da lista
    void pop_front() {
        if(m_head->next != nullptr) {
            // aponta para o primeiro elemento
            Node* aux1 = m_head->next; 
            // faz o sentinela apontar para o segundo
            m_head->next = aux1->next;
            // delete o primeiro elemento
            delete aux1;
            // decrementa m_size
            m_size--;
        }
    }

    // Funcao que retorna o tamanho da lista
    int size() const {
        return m_size;
    }

    // Funcao que diz se a lista esta vazia
    bool empty() const {
        return m_head->next == nullptr;
    }

    // Funcao que deixa a lista vazia, com 0 elementos
    void clear() {
        while(!empty()) {
            pop_front();
        }
    }    

    // Destrutor: libera todos os nos
    ~ForwardList() {
        clear();
        delete m_head;
    }

    // Faz uma copia da lista passada como entrada
    ForwardList& operator=(const ForwardList& lst) {
        if (this == &lst) {
            return *this;
        }
        this->clear(); // limpa a lista
        Node* atual = lst.m_head->next;
        Node* ultimo = this->m_head;
        while(atual != nullptr) {
            ultimo->next = new Node(atual->value, nullptr);
            ultimo = ultimo->next;
            atual= atual->next;
        }
        this->m_size = lst.m_size;
        return *this;
    }
    
    // Esse operador permite imprimir o conteudo da lista no terminal cout
    friend std::ostream& operator<<(std::ostream& out, const ForwardList& lst) {
        out << "[ ";
        for(auto it = lst.begin(); it != lst.end(); ++it) {
            out << *it << " ";
        }
        out << "]";
        return out;
    }

    // Retorna uma referencia para o primeiro elemento da lista
    int& front();

    // Retorna uma referencia constante para o primeiro elemento da lista
    const int& front() const;

    // Insere um elemento ao final da lista
    void push_back(int value);

    // Remove o ultimo elemento da lista
    void pop_back();

    // Retorna uma referencia para o ultimo elemento da lista
    int& back();
    
    // Retorna uma referencia constante para o ultimo elemento da lista
    const int& back() const;

    // Construtor de copia: recebe uma referencia para uma ForwardList
    ForwardList(const ForwardList& lst);

    // Concatenar a lista atual com a lista lst
    void concat(ForwardList& lst) {
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
    void remove(int x) {
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
    void swap(ForwardList& lst) {
        Node* tempHead = m_head;
        m_head = lst.m_head;
        lst.m_head = tempHead;

        int tempSize = m_size;
        m_size = lst.m_size;
        lst.m_size = tempSize;
    }

    // Sobrecarga do operador de igualdade
    bool operator==(const ForwardList& lst) const {
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
    bool operator!=(const ForwardList& lst) const {
        return !(*this == lst);
    }

    // Reverte a ordem dos elementos da lista
    void reverse() {
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

    // Insere 'value' logo após o nó apontado por 'position'
    Iterator insert_after(const Iterator position, int val) {
        if (position.m_pointer == nullptr) {
            return position;
        }

        Node* newNode = new Node(val, position.m_pointer->next);
        position.m_pointer->next = newNode;
        m_size++;

        return Iterator(newNode);
    }

    // Remove o elemento após o iterador 'position'
    Iterator erase_after(Iterator position) {
        if (position.m_pointer == nullptr || position.m_pointer->next == nullptr) {
            return position;
        }

        Node* toDelete = position.m_pointer->next;
        position.m_pointer->next = toDelete->next;

        Iterator nextIt(position.m_pointer->next);
        delete toDelete;
        m_size--;

        return nextIt;
    }

};

// Construtor de cópia
inline ForwardList::ForwardList(const ForwardList& lst) {
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

#endif