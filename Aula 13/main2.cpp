#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> vetor {1, 2, 3, 4, 5, 6};

    auto it = vetor.begin();
    // Mesma coisa que: vector <int>::iterator it = vetor.begin();

    cout << *it << "\n";
    it++;
    cout << *it << "\n";

    return 0;
}