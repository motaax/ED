#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

class Vector {
private:
    unsigned int m_size{0};       // numero de elementos atualmente na lista
    unsigned int m_capacity{0};   // capacidade atual da lista: o tamanho real do vetor interno
    int *m_vet{nullptr};          // ponteiro para o vetor de inteiros

public:
    Vector() = default;
    
    Vector(unsigned int cap);
    
    Vector(const Vector& v);
    
    void reserve(unsigned int newCap);
    
    void push_back(int val);
    
    int& at(unsigned int i);
    
    const int& at(unsigned int i) const;
    
    ~Vector();
    
    unsigned int size() const;
    
    unsigned int capacity() const;
    
    bool empty() const;
    
    int& operator[](unsigned int i);
    
    const int& operator[](unsigned int i) const;
    
    void pop_back();
    
    Vector& operator=(const Vector& v) = delete;

    int& front();

    const int& front() const;

    int& back();

    const int& back() const;

    void remove_all(int elem);

    void insert_at(int elem, unsigned int index);

    void remove_at(unsigned int index);
};

#endif