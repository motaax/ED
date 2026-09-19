#ifndef MATRIX
#define MATRIX

class Matrix {
private:
    int rows;     
    int columns;  
    int *array;   

public:    
    Matrix(int m, int n);
    ~Matrix();
    int get_rows();
    int get_columns();
    int get_value(int i, int j);
    void set_value(int i, int j, int newValue);
    void print();
};

void matrix_sum(Matrix& a, Matrix& b, Matrix& c);
void matrix_multiply(Matrix& a, Matrix& b, Matrix& c);

#endif