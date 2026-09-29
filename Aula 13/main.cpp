#include <iostream>
#include <vector>

using namespace std;

class Bolinha {
public:
    string cor = "branca";

    Bolinha(){};
    Bolinha(string &c) {
        cor = c;
    }

};

int main() {
    vector <float> v1; // Cria um vetor vazio
    vector <int> v2 (7); // 0 0 0 0 0 0 0
    vector <int> v3 (7, 100); // 100 100 100 100 100 100 100
    vector <Bolinha> v4(5); // Cria um vector Bolinha com 5 bolinhas brancas
    
    for(int &c : v3) {
        cout << c << " ";
        cout << "\n";
    }

    for(Bolinha &b : v4) {
        cout << b.cor << " ";
        cout << "\n";vector <int> v5(v3);
    }

    vector <int> v5(v3); // Cria um novo vetor v5 copiando todos de elementos de v3

    return 0;
}