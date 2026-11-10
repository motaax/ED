#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue <char> fila;
    char c;
    
    //Cria a fila de 'A' até 'P'
    for(c = 'A'; c <= 'P'; c++) {
        fila.push(c);
    }

    for(int i = 0; i < 15; i++) {
        //Retira os dois primeiros times
        char primeiro = fila.front();
        fila.pop();
        char segundo = fila.front();
        fila.pop();
        
        int gols_primeiro, gols_segundo;
        cin >> gols_primeiro >> gols_segundo;

        //Insere o vencedor de volta
        if(gols_primeiro > gols_segundo) {
            fila.push(primeiro);
        } else {
            fila.push(segundo);
        }
    }

    //O último é o campeão
    cout << fila.front() << "\n";

    return 0;
}