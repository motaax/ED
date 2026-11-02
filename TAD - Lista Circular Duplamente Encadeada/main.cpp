//Felipe Mota Mendes Oliveira - 604804
#include <iostream>
#include <string>
#include "List.h"

using namespace std;

int main() {
    List myList;
    string cmd;

    cout << "--- TAD Lista Circular Duplamente Encadeada ---\n";

    while (true) {
        cout << "\n> ";
        if (!(cin >> cmd)) break;

        if (cmd == "exit") {
            cout << "Encerrando o programa...\n";
            break;
        } else if (cmd == "push_back") {
            int key;
            cin >> key;
            myList.push_back(key);
            cout << "Elemento " << key << " inserido com sucesso.\n";
        } else if (cmd == "pop_back") {
            try {
                int val = myList.pop_back();
                cout << "Elemento removido: " << val << "\n";
            } catch (const exception& e) {
                cout << e.what() << "\n";
            }
        } else if (cmd == "insertAfter") {
            int key, k;
            cin >> key >> k;
            try {
                myList.insertAfter(key, k);
                cout << "Elemento " << key << " inserido apos a posicao " << k << ".\n";
            } catch (const exception& e) {
                cout << e.what() << "\n";
            }
        } else if (cmd == "remove") {
            int key;
            cin >> key;
            myList.remove(key);
            cout << "Primeira ocorrencia de " << key << " removida (se existia).\n";
        } else if (cmd == "removeAll") {
            int key;
            cin >> key;
            myList.removeAll(key);
            cout << "Todas as ocorrencias de " << key << " removidas.\n";
        } else if (cmd == "print") {
            myList.print();
        } else if (cmd == "printReverse") {
            myList.printReverse();
        } else if (cmd == "empty") {
            cout << (myList.empty() ? "A lista esta VAZIA." : "A lista NAO esta vazia.") << "\n";
        } else if (cmd == "size") {
            cout << "Tamanho atual: " << myList.size() << "\n";
        } else if (cmd == "clear") {
            myList.clear();
            cout << "Lista limpa com sucesso.\n";
        } else if (cmd == "concat") {
            List otherList;
            cout << "Criando lista secundaria para concatenar [10, 20, 30]...\n";
            otherList.push_back(10);
            otherList.push_back(20);
            otherList.push_back(30);

            myList.concat(otherList);
            cout << "Concatenacao concluida. Tamanho da lista secundaria apos concat: " 
                      << otherList.size() << "\n";
        } else if (cmd == "testEquals") {
            List cloneList = myList;
            cout << "Copia criada com operator=. Comparando listas:\n";
            cout << "myList == cloneList ? " << (myList == cloneList ? "SIM" : "NAO") << "\n";
            
            cloneList.push_back(999);
            cout << "Adicionado 999 na copia. Comparando listas:\n";
            cout << "myList != cloneList ? " << (myList != cloneList ? "SIM" : "NAO") << "\n";
        } else {
            cout << "Comando desconhecido.\n";
        }
    }

    return 0;
}