#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot){
    int size = vet.size();
    if (size == 0) return;

    // Normaliza o número de rotações
    nrot = nrot % size;

    vector<int> temp(size);

    // Calcula a nova posição
    for (int i = 0; i < size; i++) {
        int nova_posicao = (i + nrot) % size;
        temp[nova_posicao] = vet[i];
    }

    vet = temp;
}

void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
    
}