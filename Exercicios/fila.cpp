#include <iostream>
#include <queue>

using namespace std;

int main() {
    char c;
    queue <int> f1;

    while(cin >> c) {
        switch(c) {
            case 'E': { 
                int x;
                cin >> x;
                f1.push(x);
                break;
            }
            case 'D':
                if(f1.empty()) {
                    cout << "vazia \n";
                } else {
                    cout << f1.front() << "\n";
                    f1.pop();
                }
                break;
            case 'T':
                cout << f1.size() << "\n";
                break;
            default:
                cout << "comando invalido \n";
        }
    }

    return 0;
}