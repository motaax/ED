#include <iostream>
using namespace std;

//Funcao recursiva
bool palindromo(string str, int ini, int fim) {
    //Caso base
    if(ini > fim) return true;
    
    if(ini == fim) return true;
        
    if(str[ini] != str[fim]) return false;

    return palindromo(str, ini + 1, fim - 1);
}

int main() {
    string str = "pedro";
    cout << boolalpha << palindromo(str, 0, str.length() - 1) << "\n";

    return 0;
}