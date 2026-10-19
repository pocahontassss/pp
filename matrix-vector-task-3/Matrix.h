#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Vector;

class Matrix {
private:
    int rows;
    int cols;
    double** data;

public:
    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix& other);
    ~Matrix();

    int getRows() const;
    int getCols() const;

    void input();
    void print() const;

    friend Vector operator*(const Vector& v, const Matrix& m);
    friend Vector operator*(const Matrix& m, const Vector& v);
    friend Matrix operator*(const Matrix& m1, const Matrix& m2);
    friend Matrix operator*(const Matrix& m, double scalar);
    friend Matrix operator*(double scalar, const Matrix& m);
};

#endif