#include <iostream>
#include <string>

using namespace std;

void inverter_string(string &s, int ini, int fim) {
    //Caso base
    if(ini >= fim) return;

    swap(s[ini], s[fim]);

    inverter_string(s, ini + 1, fim - 1);
}

int main() {
    string s;
    
    getline(cin, s);

    inverter_string(s, 0, s.length() - 1);

    cout << s << "\n";

    return 0;
}