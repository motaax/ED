#include "Matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Construtor
Matrix::Matrix(int m, int n) {
    rows = m;
    columns = n;
    array = new int[m * n];
}

// Destrutor
Matrix::~Matrix() {
    delete[] array;
}

int Matrix::get_rows() {
    return rows;
}

int Matrix::get_columns() {
    return columns;
}

// Retorna o valor de [i][j]
int Matrix::get_value(int i, int j) {
    return array[i * columns + j];
}

// Atribui um novo valor para [i][j]
void Matrix::set_value(int i, int j, int newValue) {
    array[i * columns + j] = newValue;
}

void Matrix::print() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << setw(5) << get_value(i, j);
        }
        cout << endl; 
    }
}

// Soma a matriz 'a' e a matriz 'b', guardando o resultado em 'c'
void matrix_sum(Matrix& a, Matrix& b, Matrix& c) {
    for (int i = 0; i < a.get_rows(); ++i) {
        for (int j = 0; j < a.get_columns(); ++j) {
            int soma = a.get_value(i, j) + b.get_value(i, j);
            c.set_value(i, j, soma);
        }
    }
}

// Multiplica a matriz 'a' pela matriz 'b', guardando o resultado em 'c'
void matrix_multiply(Matrix& a, Matrix& b, Matrix& c) {
    for (int i = 0; i < a.get_rows(); ++i) {
        for (int j = 0; j < b.get_columns(); ++j) {
            int soma = 0;
            for (int k = 0; k < a.get_columns(); ++k) {
                soma += a.get_value(i, k) * b.get_value(k, j);
            }
            c.set_value(i, j, soma);
        }
    }
}