#include <iostream>
using namespace std;

void dobrar(int &x) {
    x = x * 2;
}

int main() {
    int x = 9;

    dobrar(x);
    cout << x << "\n";

    return 0;
}