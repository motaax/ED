#include <iostream>
#include <queue>

using namespace std;

queue <int> intercala(queue <int> &f1, queue <int> &f2) {

    
}

int main() {
    queue <int> a, b, res;

    for(int i = 1; i <= 7; i++) {
        a.push(i);
    }

    for(int j = 21; j <= 23; j++) {
        b.push(j);
    }

    res = intercala(a, b);

    while(!res.empty()) {
        cout << res.front() << " ";
        res.pop();
    }

    cout << "\n";

    return 0;
}