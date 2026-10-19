#include "Matrix.h"
#include "Vector.h"
#include <iomanip>

Matrix::Matrix() : rows(0), cols(0), data(nullptr) {}

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols]();
    }
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix::~Matrix() {
    if (data) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
}

int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }

void Matrix::input() {
    std::cout << "Введіть елементи матриці (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> data[i][j];
        }
    }
}

void Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(8) << data[i][j] << " ";
        }
        std::cout << "\n";
    }
}

Vector operator*(const Matrix& m, const Vector& v) {
    if (m.cols != v.size) {
        std::cerr << "Помилка: неможливо помножити матрицю на вектор (невідповідність розмірностей)!\n";
        return Vector();
    }
    Vector result(m.rows);
    for (int i = 0; i < m.rows; ++i) {
        double sum = 0;
        for (int j = 0; j < m.cols; ++j) {
            sum += m.data[i][j] * v.data[j];
        }
        result.data[i] = sum;
    }
    return result;
}

Matrix operator*(const Matrix& m1, const Matrix& m2) {
    if (m1.cols != m2.rows) {
        std::cerr << "Помилка: неможливо помножити матриці (кількість стовпців першої не дорівнює кількості рядків другої)!\n";
        return Matrix();
    }
    Matrix result(m1.rows, m2.cols);
    for (int i = 0; i < m1.rows; ++i) {
        for (int j = 0; j < m2.cols; ++j) {
            double sum = 0;
            for (int k = 0; k < m1.cols; ++k) {
                sum += m1.data[i][k] * m2.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

Matrix operator*(const Matrix& m, double scalar) {
    Matrix result(m.rows, m.cols);
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            result.data[i][j] = m.data[i][j] * scalar;
        }
    }
    return result;
}

Matrix operator*(double scalar, const Matrix& m) {
    return m * scalar;
}