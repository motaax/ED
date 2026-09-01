#include <iostream>
using namespace std;

struct Ponto {
    float x;
    float y;
};

void troca(Ponto *p1, Ponto *p2) {
    float aux;

    aux = p1->x;
    p1->x = p2->x;
    p2->x = aux;

    aux = p1->y;
    p1->x = p2->y;
    p2->y = aux;

}

int main () {
    Ponto a = {1.5, 5.3};
    Ponto b = {3.5, 7.5};

    cout << "a: {" << a.x << "," << a.y << "}\n";
    cout << "b: {" << b.x << "," << b.y << "}\n";

    troca(&a, &b);

    cout << "a: {" << a.x << "," << a.y << "}\n";
    cout << "b: {" << b.x << "," << b.y << "}\n";
    
    return 0;

}