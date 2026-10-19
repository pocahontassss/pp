#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 3;

class Matrix {
private:
    double m_data[SIZE][SIZE];

public:
    Matrix() {
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                m_data[i][j] = 0.0;
    }

    Matrix(const double values[SIZE][SIZE]) {
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                m_data[i][j] = values[i][j];
    }

    double get(int row, int col) const {
        return m_data[row][col];
    }

    void print() const {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j)
                cout << setw(8) << m_data[i][j];
            cout << '\n';
        }
    }
};

class Vector {
private:
    double m_data[SIZE];

public:
    Vector() {
        for (int i = 0; i < SIZE; ++i)
            m_data[i] = 0.0;
    }

    Vector(double x, double y, double z) {
        m_data[0] = x;
        m_data[1] = y;
        m_data[2] = z;
    }

    double get(int index) const {
        return m_data[index];
    }

    void print() const {
        cout << "( ";
        for (int i = 0; i < SIZE; ++i)
            cout << m_data[i] << (i + 1 < SIZE ? ", " : " ");
        cout << ")";
    }
};

Vector multiply(const Vector& v, const Matrix& m) {
    double result[SIZE] = {};

    for (int j = 0; j < SIZE; ++j)
        for (int i = 0; i < SIZE; ++i)
            result[j] += v.get(i) * m.get(i, j);

    return Vector(result[0], result[1], result[2]);
}

Vector multiply(const Matrix& m, const Vector& v) {
    double result[SIZE] = {};

    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            result[i] += m.get(i, j) * v.get(j);

    return Vector(result[0], result[1], result[2]);
}

int main() {
    const double values[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matrix matrix(values);
    Vector vector(1, 2, 3);

    cout << "Матриця:\n";
    matrix.print();

    cout << "\nВектор: ";
    vector.print();

    cout << "\n\nВектор * матриця = ";
    Vector result1 = multiply(vector, matrix);
    result1.print();

    cout << "\nМатриця * вектор = ";
    Vector result2 = multiply(matrix, vector);
    result2.print();

    cout << '\n';
    return 0;
}
