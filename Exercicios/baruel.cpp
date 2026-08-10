#include <iostream>
using namespace std;

int main() {
    int total[50], figuras[100];

    int qntd;
    cin >> qntd;

    for (int i = 0; i < qntd; i++) {
        total[i] = i + 1;
    }

    int qntd_figuras;
    cin >> qntd_figuras;

    for (int i = 0; i < qntd_figuras; i++) {
        cin >> figuras[i];
    }

    int repetidas = 0;

    for (int i = 1; i < qntd_figuras; i++) {
        if (figuras[i] == figuras[i - 1]) {
            if (repetidas > 0) {
                cout << " ";
            }

            cout << figuras[i];
            repetidas++;
        }
    }

    if (repetidas == 0) {
        cout << "N";
    }

    cout << "\n";

    int faltando = 0;

    for (int i = 0; i < qntd; i++) {
        int encontrou = 0;

        for (int j = 0; j < qntd_figuras; j++) {
            if (total[i] == figuras[j]) {
                encontrou = 1;
                break;
            }
        }

        if (encontrou == 0) {
            if (faltando > 0) {
                cout << " ";
            }

            cout << total[i];
            faltando++;
        }
    }

    if (faltando == 0) {
        cout << "N";
    }

    cout << "\n";

    return 0;
}