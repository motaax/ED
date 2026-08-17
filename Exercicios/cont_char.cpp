#include <iostream>
#include <string>
using namespace std;

int contaCaracteres(string str, int n, char c) {
    //Caso base
    if (n == 0)
        return 0;

    if (str[n - 1] == c)
        return 1 + contaCaracteres(str, n - 1, c);

    return contaCaracteres(str, n - 1, c);
}

int main() {
    string str;
    char c;

    cin >> ws;
    getline(cin, str);

    cin >> c;

    cout << contaCaracteres(str, str.length(), c) << "\n";

    return 0;
}