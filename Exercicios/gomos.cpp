#include <iostream>
using namespace std;

int main() {
    int q;
    char d;

    cin >> q >> d;

    int x[q], y[q];

    for (int i = 0; i < q; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = q - 1; i > 0; i--) {
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }

    if (d == 'L') {
        x[0]--;
    }
    else if (d == 'R') {
        x[0]++;
    }
    else if (d == 'U') {
        y[0]--;
    }
    else if (d == 'D') {
        y[0]++;
    }

    for (int i = 0; i < q; i++) {
        cout << x[i] << " " << y[i] << "\n";
    }

    return 0;
}