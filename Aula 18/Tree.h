#ifndef TREE_H
#define TREE_H

struct Node {
    Node(int k, Node *l, Node *r){};
};

class Tree {
private:
    Node *m_root; //Ponteiro para a raiz da árvore
public:
    //Construtor default: Cria uma árvore vazia
    Tree() {
        m_root = nullptr;
    }
}

#endif