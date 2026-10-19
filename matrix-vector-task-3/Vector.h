#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Matrix;

class Vector {
private:
    int size;
    double* data;

public:
    Vector();
    Vector(int s);
    Vector(const Vector& other);
    ~Vector();

    int getSize() const;
    double getData(int index) const;
    void setData(int index, double val);

    void input();
    void print() const;

    // Дружні функції для множення
    friend Vector operator*(const Vector& v, const Matrix& m);
    friend double operator*(const Vector& v1, const Vector& v2);
    friend Vector operator*(const Vector& v, double scalar);
    friend Vector operator*(double scalar, const Vector& v);
};

#endif