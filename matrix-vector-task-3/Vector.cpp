#include "Vector.h"
#include "Matrix.h"
#include <iomanip>

Vector::Vector() : size(0), data(nullptr) {}

Vector::Vector(int s) : size(s) {
    data = new double[size]();
}

Vector::Vector(const Vector& other) : size(other.size) {
    data = new double[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

Vector::~Vector() {
    delete[] data;
}

int Vector::getSize() const { return size; }
double Vector::getData(int index) const { return data[index]; }
void Vector::setData(int index, double val) { data[index] = val; }

void Vector::input() {
    std::cout << "Введіть елементи вектора (" << size << " шт.): ";
    for (int i = 0; i < size; ++i) {
        std::cin >> data[i];
    }
}

void Vector::print() const {
    std::cout << "[ ";
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(6) << data[i] << " ";
    }
    std::cout << "]\n";
}

Vector operator*(const Vector& v, const Matrix& m) {
    if (v.size != m.rows) {
        std::cerr << "Помилка: неможливо помножити вектор на матрицю (невідповідність розмірностей)!\n";
        return Vector();
    }
    Vector result(m.cols);
    for (int j = 0; j < m.cols; ++j) {
        double sum = 0;
        for (int i = 0; i < v.size; ++i) {
            sum += v.data[i] * m.data[i][j];
        }
        result.data[j] = sum;
    }
    return result;
}

double operator*(const Vector& v1, const Vector& v2) {
    if (v1.size != v2.size) {
        std::cerr << "Помилка: вектори мають різну розмірність для скалярного множення!\n";
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < v1.size; ++i) {
        sum += v1.data[i] * v2.data[i];
    }
    return sum;
}

Vector operator*(const Vector& v, double scalar) {
    Vector result(v.size);
    for (int i = 0; i < v.size; ++i) {
        result.data[i] = v.data[i] * scalar;
    }
    return result;
}

Vector operator*(double scalar, const Vector& v) {
    return v * scalar;
}