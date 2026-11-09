#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n;
    
    queue <string> f1;
    f1.push("1");
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        string out = f1.front();
        cout << out << "\n";
        f1.pop();
        f1.push(out + "0");
        f1.push(out + "1");
    }

    return 0;
}