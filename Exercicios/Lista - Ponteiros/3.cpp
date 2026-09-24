#include <iostream>

using namespace std;

void mm(int A[], int n, int *min, int *max) {
    if(n <= 0) return;

    // Inicializa min e max como primeiro elemento do vetor
    *min = A[0];
    *max = A[0];

    for(int i = 0; i < n; i++) {
        if(A[i] < *min) {
            *min = A[i];
        }

        if(A[i] > *max) {
            *max = A[i];
        }
    }

}

int main() {
    int A[] = {12, 5, 8, 42, 1, 19, -3, 27};
    int n = sizeof(A) / sizeof(A[0]);
    int menor, maior;

    mm(A, n, &menor, &maior);

    cout << "Menor elemento: " << menor << "\n";
    cout << "Maior elemento: " << maior << "\n";

    return 0;
}