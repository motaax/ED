#include <iostream>
using namespace std;

//Algoritmo soma de matrizes -> O(n²)
void soma_matrizes(int *A[], int *B[], int *C[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}