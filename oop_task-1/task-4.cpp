#include <iostream>
using namespace std;

class Numbers {
private:
    double m_a;
    double m_b;
    double m_c;

public:
    void setValues(double a, double b, double c) {
        m_a = a;
        m_b = b;
        m_c = c;
    }

    void print() {
        cout << "<" << m_a << ", "
             << m_b << ", " << m_c << ">" << endl;
    }

    bool isEqual(const Numbers& other) const {
        return m_a == other.m_a &&
               m_b == other.m_b &&
               m_c == other.m_c;
    }
};

int main() {
    Numbers point1;
    point1.setValues(3.0, 4.0, 5.0);

    Numbers point2;
    point2.setValues(3.0, 4.0, 5.0);

    if (point1.isEqual(point2))
        cout << "point1 and point2 are equal\n";
    else
        cout << "point1 and point2 are not equal\n";

    Numbers point3;
    point3.setValues(7.0, 8.0, 9.0);

    if (point1.isEqual(point3))
        cout << "point1 and point3 are equal\n";
    else
        cout << "point1 and point3 are not equal\n";

    return 0;
}
