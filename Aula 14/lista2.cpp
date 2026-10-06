#include <forward_list>
#include <iostream>

using namespace std;

int main() {
    forward_list <int> l1;
    forward_list <double> l2 {1.4, 1.6, 7.8};

    for(auto it = l2.begin(); it != l2.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}