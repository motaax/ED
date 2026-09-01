#include <iostream>
using namespace std;

int main() {
    int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr = vet;

    cout << *ptr << "\n"; //1
    cout << *(ptr + 2) << "\n"; //3
    cout << ptr[2] << "\n"; //3

    return 0;
}