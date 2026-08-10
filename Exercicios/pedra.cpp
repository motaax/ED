#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a, b;
    int melhor_a = 0, melhor_b = 0;
    int ganhador = 0;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        if (a < 10 || b < 10)
            continue;

        if (melhor_a == 0) {
            melhor_a = a;
            melhor_b = b;
            ganhador = i;
            continue;
        }

        if (abs(a - b) < abs(melhor_a - melhor_b)) {
            melhor_a = a;
            melhor_b = b;
            ganhador = i;
        }
    }

    if (melhor_a == 0)
        cout << "sem ganhador\n";
    else
        cout << ganhador << "\n";

    return 0;
}