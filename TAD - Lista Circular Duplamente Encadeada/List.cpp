//Felipe Mota Mendes Oliveira - 604804
#include "List.h"

// Construtor: Inicializa o nó setninela apontando para si mesmo
List::List() {
    head = new Node();
    head->next = head;
    head->prev = head;
    count = 0;
}

// Destrutor: Esvazia os elementos utilitários e remove o nó sentinela
List::~List() {
    clear();
    delete head;
}

// Construtor de Cópia: Realiza a cópia de outra lista
List::List(const List& lst) {
    head = new Node();
    head->next = head;
    head->prev = head;
    count = 0;

    Node* curr = lst.head->next;
    while (curr != lst.head) {
        push_back(curr->key);
        curr = curr->next;
    }
}

// Insere um elemento no final da lista
void List::push_back(int key) {
    Node* last = head->prev;
    Node* newNode = new Node(key, last, head);
    
    last->next = newNode;
    head->prev = newNode;
    count++;
}

// Remove o último elemento e retorna seu valor
int List::pop_back() {
    if (empty()) {
        throw std::underflow_error("Erro: A lista esta vazia.");
    }

    Node* last = head->prev;
    int val = last->key;

    last->prev->next = head;
    head->prev = last->prev;

    delete last;
    count--;

    return val;
}

// Insere key após o k-ésimo nó da lista
void List::insertAfter(int key, int k) {
    if (k < 0 || k > count) {
        throw std::out_of_range("Erro: Posicao k invalida.");
    }

    Node* curr = head;
    for (int i = 0; i < k; ++i) {
        curr = curr->next;
    }

    Node* newNode = new Node(key, curr, curr->next);
    curr->next->prev = newNode;
    curr->next = newNode;
    count++;
}

// Remove a primeira ocorrência do elemento key
void List::remove(int key) {
    Node* curr = head->next;

    while (curr != head) {
        if (curr->key == key) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            count--;
            return;
        }
        curr = curr->next;
    }
}

// Remove todas as ocorrências do elemento key
void List::removeAll(int key) {
    Node* curr = head->next;

    while (curr != head) {
        Node* nextNode = curr->next;
        if (curr->key == key) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            count--;
        }
        curr = nextNode;
    }
}

// Imprime os elementos na ordem do primeiro ao último
void List::print() const {
    std::cout << "[ ";
    Node* curr = head->next;
    while (curr != head) {
        std::cout << curr->key << " ";
        curr = curr->next;
    }
    std::cout << "]\n";
}

// Imprime os elementos na ordem inversa
void List::printReverse() const {
    std::cout << "[ ";
    Node* curr = head->prev;
    while (curr != head) {
        std::cout << curr->key << " ";
        curr = curr->prev;
    }
    std::cout << "]\n";
}

// Retorna true se a lista estiver vazia
bool List::empty() const {
    return head->next == head;
}

// Retorna a quantidade de nós úteis na lista
int List::size() const {
    return count;
}

// Libera a memória de todos os elementos, deixando apenas o nó sentinela
void List::clear() {
    Node* curr = head->next;
    while (curr != head) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head->next = head;
    head->prev = head;
    count = 0;
}

// Concatena lst ao final da lista atual e reseta lst para ficar vazia
void List::concat(List& lst) {
    if (lst.empty()) return;

    Node* myLast = head->prev;
    Node* lstFirst = lst.head->next;
    Node* lstLast = lst.head->prev;

    // Conecta o fim da lista atual com o início de lst
    myLast->next = lstFirst;
    lstFirst->prev = myLast;

    // Conecta o fim de lst de volta ao nó cabeça atual
    lstLast->next = head;
    head->prev = lstLast;

    // Reseta o nó cabeça da lista repassada
    lst.head->next = lst.head;
    lst.head->prev = lst.head;

    count += lst.count;
    lst.count = 0;
}

// Operador de atribuição
List& List::operator=(const List& lst) {
    if (this != &lst) {
        clear();
        Node* curr = lst.head->next;
        while (curr != lst.head) {
            push_back(curr->key);
            curr = curr->next;
        }
    }
    return *this;
}

// Verifica se duas listas são idênticas em tamanho e conteúdo
bool List::operator==(const List& lst) const {
    if (this->count != lst.count) return false;

    Node* curr1 = this->head->next;
    Node* curr2 = lst.head->next;

    while (curr1 != this->head) {
        if (curr1->key != curr2->key) return false;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return true;
}

// Verifica se duas listas são diferentes
bool List::operator!=(const List& lst) const {
    return !(*this == lst);
}