#include <iostream>
using namespace std;

int main() {
    int *p = nullptr; // o ponteiro p nao aponta para nenhum lugar

    if(p == nullptr) {
        cout << "p esta vazio" << "\n";
    }

    return 0;
}