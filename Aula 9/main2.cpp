#include <iostream>
#include <vector>
#include "Point.h"
using namespace std;

int main() {
    vector <Point> vet(5);

    for(int i = 0; i < (int) vet.size(); i++) {
        cout << vet[i].getX() << ", " << vet[i].getY() << "\n";
    }

    return 0;
}