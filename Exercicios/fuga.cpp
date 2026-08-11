#include <iostream>
using namespace std;

int main() {
    int h, p, f, d;
    cin >> h >> p >> f >> d;

    for (int i = 0; i < 16; i++) {
        f = f + d;

        if (f == 16) f = 0;

        if (f == -1) f = 15;

        if (f == p) {
            cout << "N\n";
            break;
        }

        if (f == h) {
            cout << "S\n";
            break;
        }
    }

    return 0;
}