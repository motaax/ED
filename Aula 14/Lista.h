#ifndef Lista
#define Lista

//Representa um nó da lista
struct Node {
    int key;
    Node *next;
};

//Implementa a lista encadeada
class Lista_Encadeada {
private:
    Node *m_head; //Ponteiro para o nó sentinela
    int m_size; //Tamanho da lista
public:
    //Construtor default: cria uma lista vazia
    Lista_Encadeada() {
        m_size = 0;
        m_head = new Node;
        m_head->next = nullptr; 
    }
    
    //Insere um valor no inicio da lista
    void push_front(int value) {
        Node *aux = new Node;
        aux->key = value;
        aux->next = m_head->next;
        m_head->next = aux;
        m_size++;
    }

    //Imprime o valor dos elementos na tela
    void print() {
        Node *aux = m_head->next;
        while(aux != nullptr) {
            std::cout << aux->key << " ";
            aux = aux->next;
        }

        std::cout << "\n";
    }

    //Apaga o primeiro elemento da lista
    void pop_front() {
        if(m_size > 0) {
            Node *aux = m_head->next;
            m_head->next = aux->next;
            delete aux;
            m_size--;
        }
    }

    //Retorna o tamanho da lista
    int size() {
        return m_size;
    }

    //Retorna se a lista está vazia
    bool empty() {
        return m_size == 0;
    }

    //Destrutor: libera todos os nós
    ~Lista_Encadeada() {
        while(m_size > 0) {
            pop_front();
        }

        delete m_head;
    }

};

#endif 