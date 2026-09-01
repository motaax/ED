#include <iostream>
using namespace std;

struct Ponto {
    double x;
    double y;
};

int main () {
    Ponto p;
    p.x = 1.0;
    p.y = 2.0;

    Ponto *ptr = &p;

    //Operador seta
    cout << ptr -> x << ", " << ptr -> y << "\n";

    ptr -> x = 10.0;
    ptr -> y = 20.0;

    cout << p.x << ", " << p.y << "\n";
    
    return 0;

}