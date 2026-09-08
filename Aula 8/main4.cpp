#include <iostream>
using namespace std;

struct Pessoa {
    string nome;
    int idade;
};

int main() {
    int n;
    cin >> n;
    cin.ignore();

    Pessoa *grupo = new Pessoa[n];

    for(int i = 0; i < n; i++) {
        getline(cin, grupo[i].nome);
        cin >> grupo[i].idade;
        cin.ignore();
    }
    
    cout << "Os dados que foram digitados: \n";
    for(int i = 0; i < n; i++) {
        cout << grupo[i].nome << ", " << grupo[i].idade << "\n";
    }

    delete [] grupo;

    return 0;
}