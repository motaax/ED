#include "Bst.h"

using namespace std;

int main() {
    BST tree;

    for(int i = 1; i < 10; i++) {
        tree.insert(i);
    }

    tree.pre_ordem();
    cout << "\n";

    return 0;
}