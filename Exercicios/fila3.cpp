#include <iostream>
#include <queue>

using namespace std;

queue <int> intercala(queue <int> &f1, queue <int> &f2) {
    int total = f1.size() + f2.size();
    
    queue <int> f_res;
    for(int i = 1; i <= total; i++) {
        if(!f1.empty()) {
            f_res.push(f1.front());
            f1.pop();
        }

        if(!f2.empty()) {
            f_res.push(f2.front());
            f2.pop();
        }
    }

    return f_res;
    
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