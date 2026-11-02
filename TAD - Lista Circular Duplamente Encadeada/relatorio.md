# Relatório do Trabalho

**Aluno:** Felipe Mota Mendes Oliveira  
**Matrícula:** 604804

## 1. Descrição do Trabalho e Arquitetura

### Principais Características da Estrutura:
* **Nó Sentinela:** Alocado na instanciação do objeto `List`, o nó cabeça facilita o controle das extremidades da lista. Ele não armazena dados válidos da aplicação e simplifica inserções e remoções.
* **Circularidade:** O ponteiro `next` do último nó aponta para o nó cabeça, e o ponteiro `prev` do primeiro nó aponta para o nó cabeça. Em uma lista vazia, o nó cabeça aponta para si mesmo.
* **Encadeamento Duplo:** Cada nó contém ponteiros para o nó posterior (`next`) e anterior (`prev`), permitindo travessias bidirecionais eficientes.

## 2. Organização dos Arquivos Fonte

| Arquivo | Descrição |
| :--- | :--- |
| `Node.h` | Declaração da estrutura `Node` contendo o campo de dado (`key`) e os ponteiros `prev` e `next`. |
| `List.h` | Declaração da classe `List` (inclui `Node.h`), contendo atributos privados e os protótipos de todos os métodos solicitados. |
| `List.cpp` | Implementação detalhada das operações da classe `List`, incluindo alocação/desalocação de memória e controle de ponteiros. |
| `main.cpp` | Interface interativa via terminal (CLI) que permite ao usuário executar e testar todas as operações do TAD `List`. |

## 3. Descrição dos Comandos da Interface Terminal (`main.cpp`)

| Comando | Sintaxe | Operação / Descrição |
| :--- | :--- | :--- |
| `push_back` | `push_back <key>` | Insere o valor `key` no final da lista (`push_back`). |
| `pop_back` | `pop_back` | Remove e exibe o elemento do final da lista (`pop_back`). Lança exceção se estiver vazia. |
| `insertAfter` | `insertAfter <key> <k>` | Insere o valor `key` imediatamente após o $k$-ésimo nó da lista (`insertAfter`). Considera $k=0$ como inserção no início. |
| `remove` | `remove <key>` | Busca e remove a **primeira ocorrência** do valor `key` (`remove`). |
| `removeAll` | `removeAll <key>` | Busca e remove **todas as ocorrências** do valor `key` (`removeAll`). |
| `print` | `print` | Exibe todos os elementos da lista na ordem direta (`print`). |
| `printReverse` | `printReverse` | Exibe todos os elementos da lista na ordem inversa (`printReverse`). |
| `empty` | `empty` | Informa se a lista está vazia (`empty`). |
| `size` | `size` | Retorna o número de elementos da lista (`size`). |
| `clear` | `clear` | Remove todos os nós da lista, mantendo apenas o nó cabeça (`clear`). |
| `concat` | `concat` | Concatena uma lista secundária de teste à lista atual (`concat`). A lista secundária fica vazia após a operação. |
| `testEquals` | `testEquals` | Testa os operadores de atribuição (`operator=`) e comparação (`operator==` e `operator!=`). |
| `help` | `help` | Exibe a lista de comandos disponíveis. |
| `exit` | `exit` | Encerra a execução do programa. |

## 4. Instruções de Compilação e Execução

### Compilação
Para compilar todos os arquivos usando `g++`:

```bash
g++ -Wall -std=c++11 List.cpp main.cpp -o programa_lista
```

### Execução
Para executar a interface interativa:

```bash
./programa_lista
```

## 5. Exemplo de Sessão de Uso

```text
--- TAD Lista Circular Duplamente Encadeada ---

> push_back 10
Elemento 10 inserido com sucesso.

> push_back 20
Elemento 20 inserido com sucesso.

> push_back 10
Elemento 10 inserido com sucesso.

> print
[ 10 20 10 ]

> insertAfter 15 1
Elemento 15 inserido apos a posicao 1.

> print
[ 10 15 20 10 ]

> remove 10
Primeira ocorrencia de 10 removida (se existia).

> print
[ 15 20 10 ]

> removeAll 10
Todas as ocorrencias de 10 removidas.

> print
[ 15 20 ]

> exit
Encerrando o programa...
```