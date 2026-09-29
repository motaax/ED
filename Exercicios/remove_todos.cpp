#include <iostream>
#include <vector>

using namespace std;

void remove_todos(vector<int> &v, int x) {
    for (int i = 0; i < (int) v.size(); i++) {
        if (v[i] == x) {
            v.erase(v.begin() + i);
            i--;
        }
    }
}

void imprime_vetor(vector <int> &v) {
    for(int &c : v) {
        cout << c << "\n";
    }
}

int main() {
    vector <int> v {3, 3, 4, 3, 5, 3, 3, 6};

    int x = 3;

    remove_todos(v, x);
    imprime_vetor(v);

    return 0;
}