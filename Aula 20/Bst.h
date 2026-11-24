#ifndef BST_H
#define BST_H
#include <iostream>

using namespace std;

class BST {
private:
    struct Node {
        int key;
        Node *left;
        Node *right;

        // Construtor do Node
        Node(int k, Node *l = nullptr, Node *r = nullptr) {
            key = k;
            left = l;
            right = r;
        }
    };

    Node *m_root;

public:
    // Construtor default
    BST() {
        m_root = nullptr;
    }

    // Destrutor
    ~BST() {
        clear(m_root);
    }

    void insert(int key) {
        m_root = insert_rec(m_root, key);
    }

    bool search(int key) {
        return search_rec(m_root, key) != nullptr;
    }

    void pre_ordem() {
        pre_ordem(m_root);
    }

private:
    Node *insert_rec(Node *node, int key) {
        if (node == nullptr) {
            return new Node(key, nullptr, nullptr);
        } 
        
        if (key == node->key) {
            return node;
        } 
        
        if (key < node->key) {
            node->left = insert_rec(node->left, key);
        } else {
            node->right = insert_rec(node->right, key);
        }

        return node;
    }

    Node *search_rec(Node *node, int key) {
        if (node == nullptr || node->key == key) {
            return node;
        }
        if (key < node->key) {
            return search_rec(node->left, key);
        }
        return search_rec(node->right, key);
    }

    void pre_ordem(Node *node) {
        if(node != nullptr) {
            cout << node->key << " ";
            pre_ordem(node->left);
            pre_ordem(node->right);
        }
    }

    void clear(Node *node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};

#endif