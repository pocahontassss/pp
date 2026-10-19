#include <iostream>
using namespace std;

class Numbers {
private:
    int m_a;
    int m_b;

public:
    Numbers(int a = 0, int b = 0) {
        m_a = a;
        m_b = b;
    }

    void set(int a, int b) {
        m_a = a;
        m_b = b;
    }

    void print() {
        cout << "Numbers (" << m_a << ", " << m_b << ")" << endl;
    }
};

int main() {
    Numbers n1;
    n1.set(3, 3);

    Numbers n2{4, 4};

    n1.print();
    n2.print();

    return 0;
}
