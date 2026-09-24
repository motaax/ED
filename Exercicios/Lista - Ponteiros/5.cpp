#include <iostream>

using namespace std;

char *strcpy(char *destino, char *origem) {
    char *ptr = destino; 

    while ((*destino++ = *origem++) != '\0') {
    
    }

    return ptr; 
}

int main() {
    char origem[] = "Olá, mundo!";
    char destino[50]; 

    strcpy(destino, origem);

    cout << "String origem: " << origem << "\n";
    cout << "String destino: " << destino << "\n";

    return 0;
}