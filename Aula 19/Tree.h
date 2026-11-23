#ifndef TREE_H
#define TREE_H
#include <iostream>

// Define um nó da árvore binária
struct Node {
    int key;
    Node *left;
    Node *right;

    // construtor do nó
    Node(int k, Node *l, Node *r) {
        key = k;
        left = l;
        right = r;
    }
};

class Tree {
private:
    Node *m_root; // ponteiro par a raiz da árvore
public:
    // Construtor default: Cria uma árvore vazia 
    Tree() {
        m_root = nullptr;
    }
    // Construtor 2: recebe como entrada um valor e mais 
    // duas outras árvores, e cria uma terceira árvore com o
    // que foi recebido 
    Tree(int valor, Tree& t1, Tree& t2) {
        m_root = new Node(valor, nullptr, nullptr); 
        m_root->left = t1.m_root;
        t1.m_root = nullptr;
        m_root->right = t2.m_root;
        t2.m_root = nullptr; 
    }
    // Versão pública da função size.
    int size() {
        return size_recursiva(m_root);
    }
    bool contains(int valor) {
        return contains_rec(valor, m_root);
    }
private:
    // Função recursiva que calcula quantos nós têm 
    // na subárvore cuja raiz é passada como parâmetro
    int size_recursiva(Node *node) {
        if(node == nullptr) { // Caso base: vazia
            return 0;
        } else { // Caso geral: não é vazia
            return 1 + size_recursiva(node->left) + size_recursiva(node->right);
        }
    }
    // Função privada recursiva que recebe como entrada um valor 
    // e a raiz de uma árvore e retorna true se e somente 
    // se o valor está na árvore.
    bool contains_rec(int v, Node *node) {
        if(node == nullptr) { // Caso base: árvore vazia
            return false;
        } else { // Caso geral: não é vazia
            return (node->key == v) || 
                   contains_rec(v, node->left) || 
                   contains_rec(v, node->right);
        }
    }

    //Função recursiva que recebe a raiz de uma subárvore e libera todos os nós dessa subárvore
    void clear(Node *node) {
        
    }
};


#endif