#include "Vector.h"
#include <stdexcept>

Vector::Vector(unsigned int cap) 
    : m_size{0}, m_capacity{cap}
{
    m_vet = new int[m_capacity];
}

Vector::Vector(const Vector& v) {
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    m_vet = new int[m_capacity];
    for(unsigned int i = 0; i < m_size; ++i) {
        m_vet[i] = v.m_vet[i];
    }
}

void Vector::reserve(unsigned int newCap) {
    if(m_capacity < newCap) {
        m_capacity = newCap;
        int *aux = new int[m_capacity];
        if (m_vet != nullptr) {
            for(unsigned int i = 0; i < m_size; ++i) {
                aux[i] = m_vet[i];
            }
            delete[] m_vet;
        }
        m_vet = aux;
    }
}

void Vector::push_back(int val) {
    if(m_size == m_capacity) {  
        reserve(m_capacity == 0 ? 8 : 2 * m_capacity);
    }
    m_vet[m_size] = val;
    m_size++;            
}

int& Vector::at(unsigned int i) {
    if(i < m_size) {
        return m_vet[i];
    }
    else {
        throw std::out_of_range("erro no indice");
    }
}

const int& Vector::at(unsigned int i) const {
    if(i < m_size) {
        return m_vet[i];
    }
    else {
        throw std::out_of_range("erro no indice");
    }
}

Vector::~Vector() {
    delete[] m_vet;
}

unsigned int Vector::size() const {
    return m_size;
}

unsigned int Vector::capacity() const {
    return m_capacity;
}

bool Vector::empty() const {
    return m_size == 0;
}

int& Vector::operator[](unsigned int i) {
    return m_vet[i];
}
   
const int& Vector::operator[](unsigned int i) const {
    return m_vet[i];
}

void Vector::pop_back() {
    if(m_size > 0) {
        m_size--;
    }
}

int& Vector::front() {
    if (empty()) throw std::out_of_range("vetor vazio");
    return m_vet[0];
}

const int& Vector::front() const {
    if (empty()) throw std::out_of_range("vetor vazio");
    return m_vet[0];
}

int& Vector::back() {
    if (empty()) throw std::out_of_range("vetor vazio");
    return m_vet[m_size - 1];
}

const int& Vector::back() const {
    if (empty()) throw std::out_of_range("vetor vazio");
    return m_vet[m_size - 1];
}

void Vector::remove_all(int elem) {
    unsigned int k = 0;
    for (unsigned int i = 0; i < m_size; ++i) {
        if (m_vet[i] != elem) {
            m_vet[k] = m_vet[i];
            k++;
        }
    }
    m_size = k;
}

void Vector::insert_at(int elem, unsigned int index) {
    if (index > m_size) {
        throw std::out_of_range("indice fora do intervalo");
    }
    
    if (m_size == m_capacity) {
        reserve(m_capacity == 0 ? 8 : 2 * m_capacity);
    }
    
    for (unsigned int i = m_size; i > index; --i) {
        m_vet[i] = m_vet[i - 1];
    }
    
    m_vet[index] = elem;
    m_size++;
}

void Vector::remove_at(unsigned int index) {
    if (index >= m_size) {
        throw std::out_of_range("indice fora do intervalo");
    }
    
    for (unsigned int i = index; i < m_size - 1; ++i) {
        m_vet[i] = m_vet[i + 1];
    }
    
    m_size--;
}