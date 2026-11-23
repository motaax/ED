#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
    Tree empty = Tree(); 
    Tree t2(2, empty, empty); 
    Tree t1(1, empty, empty); 
    Tree t9(9, empty, empty); 
    Tree t4(4, t2, t1); 
    Tree t7(7, empty, t9); 
    Tree t5(5, t4, t7);  

    cout << "Quantos nós? " << t5.size() << endl;
    cout << "Contém o 10? " << boolalpha << t5.contains(10) << endl;
}