#ifndef VECTOR
#define VECTOR
#include <stdexcept>

class Vector {
private:
    int *m_list; // Ponteiro para a lista
    int m_capacity; // Capacidade da lista
    int m_size; // Tamanho da lista

public:
    // Construtor default: cria uma lista vazia com capacidade inicial de 16
    Vector() {
        m_size = 0;
        m_capacity = 16;
        m_list = new int[m_capacity];
    }

    // Destrutor: libera toda a memória que foi alocada
    ~Vector() {
        delete [] m_list;
    }

    // Retorna a capacidade da lista
    int capacity() {
        return m_capacity;
    }

    // Retorna o tamanho atual da lista
    int size() {
        return m_size;
    }

    // Retorna se a lista está vazia
    bool empty() {
        if (m_size == 0) {
            return true;
        } else {
            return false;
        }
    }

    // Verifica se k está dentro dos limites de elementos válidos
    int &at(int k) {
        if (k >= 0 && k < m_size) {
            return m_list[k];
        } else {
            throw std::out_of_range("indice invalido");
        }
    }

    // Aumenta a capacidade realocando os elementos
    void reserve(int n) {
        if (m_capacity < n) {
            int *aux = new int[n];

            for (int i = 0; i < m_size; i++) {
                aux[i] = m_list[i];
            }

            delete [] m_list;
            m_list = aux;
            m_capacity = n;
        }
    }

    // Adiciona um inteiro após o último elemento da lista
    void push_back(int value) {
        if (m_size == m_capacity) {
            reserve(m_capacity * 2);
        }

        m_list[m_size] = value;
        m_size++;
    }

    // Remove o último elemento da lista
    void pop_back() {
        if (m_size > 0) {
            m_size--;
        }
    }
};

#endif