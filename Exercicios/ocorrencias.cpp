#include <iostream>
#include <list>

using namespace std;

void removerTodos(list <int> &l, int x) {
    //Percorre a lista usando um iterador
    for(auto it = l.begin(); it != l.end();) {
        if(*it == x) {
            it = l.erase(it);
        } else {
            it++;
        }
    }
}

int main() {
    list <int> l {3, 1, 3, 3, 5, 5, 4, 1, 5, 9, 2, 6, 1};
    int x = 5;

    removerTodos(l, x);

    for(int num : l) {
        cout << num << " ";
    }

    cout << "\n";

    return 0;
}