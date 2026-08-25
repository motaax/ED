#include <iostream>
using namespace std;

//Algoritmo multiplicacao de matrizes -> O(n³)
void multiplica_matrizes(int *A[], int *B[], int *C[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = 0;
            for(int k = 0; k < n; k++) {
                C[i][j] = C[i][j] + A[i][j] * B[i][j];
            }
        }
    }
}