#include <iostream>
#include <stdexcept>
#include "Vector.h"

using namespace std;

void imprime_vetor(const Vector& v) { 
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    Vector myVet; 

    myVet.push_back(33);

    for(int i = 1; i <= 10; i++) {
        myVet.push_back(2);
    }

    myVet.push_back(77);

    imprime_vetor(myVet);

    myVet.removeAll(2);

    imprime_vetor(myVet);

    return 0;
}