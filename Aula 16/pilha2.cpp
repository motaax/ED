#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    //Cria a primeira pilha
    stack <char> s1;

    for(int i = 0; i < (int) str.size(); i++) {
        if(!s1.empty() && s1.top() == str[i]) {
            s1.pop();
        } else {
            s1.push(str[i]);
        }
    }

    //Cria a segunda pilha
    stack <char> s2;
    
    while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }

    while(!s2.empty()) {
        cout << s2.top();
        s2.pop();
    }

    cout << "\n";

    return 0;
}