#include <iostream>
#include <vector>
#include <string>
#include "Matrix.h"

using namespace std;

int main() {
    vector <Matrix*> matrices;
    string command;

    while (cin >> command) {
        
        if (command == "creatematrix") { 
            int rows, columns;
            cin >> rows >> columns;
            Matrix* matrix = new Matrix(rows, columns);

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    int value;
                    cin >> value;
                    matrix->set_value(i, j, value);
                }
            }
            matrices.push_back(matrix);
        }
        else if (command == "nlinhas") {
            int k;
            cin >> k;
            cout << "linhas: " << matrices[k]->get_rows() << endl;
        }
        else if (command == "ncolunas") {
            int k;
            cin >> k;
            cout << "colunas: " << matrices[k]->get_columns() << endl;
        }
        else if (command == "getvalor") {
            int i, j, k;
            cin >> i >> j >> k;
            cout << matrices[k]->get_value(i, j) << endl;
        }
        
        else if (command == "printmatrix") {
            int k;
            cin >> k;
            matrices[k]->print();
        }
        else if (command == "sum") {
            int p, q;
            cin >> p >> q;

            Matrix& a = *matrices[p];
            Matrix& b = *matrices[q];
            Matrix* c = new Matrix(a.get_rows(), a.get_columns());

            if (a.get_rows() != b.get_rows() || a.get_columns() != b.get_columns()) {
                cout << "nao foi possivel somar" << endl;
            } else {
                matrix_sum(a, b, *c);
                c->print();
            }
            matrices.push_back(c);
        }
        else if (command == "multiply") {
            int p, q;
            cin >> p >> q;

            Matrix& a = *matrices[p];
            Matrix& b = *matrices[q];
            Matrix* c = new Matrix(a.get_rows(), b.get_columns());

            if (a.get_columns() != b.get_rows()) {
                cout << "nao foi possivel multiplicar" << endl;
            } else {
                matrix_multiply(a, b, *c);
                c->print();
            }
            matrices.push_back(c);
        }
        else if (command == "exit") {
            for (Matrix* matriz : matrices) {
                delete matriz;
                cout << "matriz liberada" << endl;
            }
            return 0;
        }
    }
    return 0;
}