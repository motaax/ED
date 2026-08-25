#include <iostream>
using namespace std;

//Algoritmo busca sequencial -> O(n)
int busca(int v[], int n, int x) {
    int i;
    for(i = 0; i < n; i++) {
        if(v[i] == 0) return i;
    }

    return -1;
}