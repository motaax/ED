#include <iostream>
using namespace std;

int main() {
    int n, v[50], casais = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        if (v[i] != 0) {
            for (int j = i + 1; j < n; j++) {
                if (v[i] == -v[j]) {
                    casais++;
                    v[i] = 0;
                    v[j] = 0;
                    break;
                }
            }
        }
    }

    cout << casais << "\n";

    return 0;
}