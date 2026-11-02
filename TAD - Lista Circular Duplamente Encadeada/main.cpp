//Felipe Mota Mendes Oliveira - 604804
#include <iostream>
#include <string>
#include "List.h"

int main() {
    List myList;
    std::string cmd;

    std::cout << "--- TAD Lista Circular Duplamente Encadeada ---\n";
    std::cout << "Digite 'help' para ver a lista de comandos disponiveis.\n";

    while (true) {
        std::cout << "\n> ";
        if (!(std::cin >> cmd)) break;

        if (cmd == "exit") {
            std::cout << "Encerrando o programa...\n";
            break;
        } else if (cmd == "push_back") {
            int key;
            std::cin >> key;
            myList.push_back(key);
            std::cout << "Elemento " << key << " inserido com sucesso.\n";
        } else if (cmd == "pop_back") {
            try {
                int val = myList.pop_back();
                std::cout << "Elemento removido: " << val << "\n";
            } catch (const std::exception& e) {
                std::cout << e.what() << "\n";
            }
        } else if (cmd == "insertAfter") {
            int key, k;
            std::cin >> key >> k;
            try {
                myList.insertAfter(key, k);
                std::cout << "Elemento " << key << " inserido apos a posicao " << k << ".\n";
            } catch (const std::exception& e) {
                std::cout << e.what() << "\n";
            }
        } else if (cmd == "remove") {
            int key;
            std::cin >> key;
            myList.remove(key);
            std::cout << "Primeira ocorrencia de " << key << " removida (se existia).\n";
        } else if (cmd == "removeAll") {
            int key;
            std::cin >> key;
            myList.removeAll(key);
            std::cout << "Todas as ocorrencias de " << key << " removidas.\n";
        } else if (cmd == "print") {
            myList.print();
        } else if (cmd == "printReverse") {
            myList.printReverse();
        } else if (cmd == "empty") {
            std::cout << (myList.empty() ? "A lista esta VAZIA." : "A lista NAO esta vazia.") << "\n";
        } else if (cmd == "size") {
            std::cout << "Tamanho atual: " << myList.size() << "\n";
        } else if (cmd == "clear") {
            myList.clear();
            std::cout << "Lista limpa com sucesso.\n";
        } else if (cmd == "concat") {
            List otherList;
            std::cout << "Criando lista secundaria para concatenar [10, 20, 30]...\n";
            otherList.push_back(10);
            otherList.push_back(20);
            otherList.push_back(30);

            myList.concat(otherList);
            std::cout << "Concatenacao concluida. Tamanho da lista secundaria apos concat: " 
                      << otherList.size() << "\n";
        } else if (cmd == "testEquals") {
            List cloneList = myList;
            std::cout << "Copia criada com operator=. Comparando listas:\n";
            std::cout << "myList == cloneList ? " << (myList == cloneList ? "SIM" : "NAO") << "\n";
            
            cloneList.push_back(999);
            std::cout << "Adicionado 999 na copia. Comparando listas:\n";
            std::cout << "myList != cloneList ? " << (myList != cloneList ? "SIM" : "NAO") << "\n";
        } else if (cmd == "help") {
            showHelp();
        } else {
            std::cout << "Comando desconhecido. Digite 'help' para instrucoes.\n";
        }
    }

    return 0;
}