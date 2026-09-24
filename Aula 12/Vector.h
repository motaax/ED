#ifndef VECTOR
#define VECTOR
#include <stdexcept>

class Vector {
private:
    int* m_list; // ponteiro para a lista de inteiros
    int m_capacity; // capacidade da lista
    int m_size; // tamanho da lista

public:
    // Construtor default: cria uma lista vazia com capacidade de 16 elementos
    Vector() {
        m_size = 0;
        m_capacity = 16;
        m_list = new int[m_capacity];
    }

    // Construtor de cópia: recebe como entrada uma referência para um vector e cria uma cópia dele.
    Vector(const Vector& v) {
        m_capacity = v.m_capacity;
        m_size = v.m_size;
        m_list = new int[m_capacity];

        for(int i = 0; i < m_size; i++) {
            m_list[i] = v.m_list[i];
        }
    }

    // Destrutor
    ~Vector() {
        delete[] m_list;
    }

    // Retorna a capacidade da lista 
    int capacity() const {
        return m_capacity;
    }

    // Retorna o tamanho atual da lista 
    int size() const {
        return m_size;
    }

    // Retorna se a lista está vazia
    bool empty() const {
        if(m_size == 0) {
            return true;
        }
        else {
            return false;
        }    
    }

    // A funcao verifica se k está dentro do vetor, lançando ’out_of_range’ se não estiver.
    int& at (int k) {
        if(k >= 0 && k < m_size) {
            return m_list[k];
        } else {
            throw std::out_of_range("índice inválido");
        }
    }

    // Versão constante da função at()
    const int& at (int k) const {
        if(k >= 0 && k < m_size) {
            return m_list[k];
        } else {
            throw std::out_of_range("índice inválido");
        }
    }

    // A funcao faz com que a lista aumente sua capacidade realocando os elementos para o novo vetor
    void reserve(int n) {
        if(m_capacity < n) {
            int *aux = new int[n];
            for(int i = 0; i < m_size; i++) {
                aux[i] = m_list[i];
            }

            delete [] m_list;
            m_list = aux;
            m_capacity = n;
        }
    }

    // Função que insere um elemento ao final da lista
    void push_back(int value) {
        if(m_size == m_capacity) {
            reserve(2*m_capacity);
        }

        m_list[m_size] = value;
        m_size++;
    }

    // Função que compara dois vetores e diz se
    // eles são idênticos.
    bool operator==(const Vector& v) {
        if(m_size != v.m_size) {
            return false;
        }

        for(int i = 0; i < m_size; i++) {
            if(m_list[i] != v.m_list[i]) {
                return false;
            }
        }

        return true;
    }

    // Função que retorna uma referência para o elemento que estiver naquela posição.
    int& operator[](int i) {
        return m_list[i];
    }

    // Versão const
    const int& operator[](int i) const {
        return m_list[i];
    }

    // Remove o ultimo elemento da lista se a lista não estiver vazia.
    void pop_back() {
        if(!empty()) {
            m_size--;
        }
    }

    // Remove o elemento com ı́ndice k na lista.
    void removeAt(int k) {
        if(k<0 && k>=m_size) return;

        for(; k<m_size-1; k++) {
            m_list[k] = m_list[k+1];
        }

        m_size--;
    } 

    void removeAll(int value) {
        int i = 0;
        while(i < m_size) {
            if(m_list[i] == value) {
                removeAt(i);
            } else {
                i++;
            }
        }
    } 


};

#endif