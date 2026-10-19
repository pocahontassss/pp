#include <iostream>
#include <cassert>
using namespace std;

class Stack {
private:
    int m_array[10];
    int m_length;

public:
    void reset() {
        m_length = 0;

        for (int i = 0; i < 10; i++) {
            m_array[i] = 0;
        }
    }

    bool push(int value) {
        if (m_length >= 10) {
            return false;
        }

        m_array[m_length] = value;
        m_length++;

        return true;
    }

    int pop() {
        assert(m_length > 0);

        m_length--;
        return m_array[m_length];
    }

    void print() {
        cout << "( ";

        for (int i = 0; i < m_length; i++) {
            cout << m_array[i] << " ";
        }

        cout << ")" << endl;
    }
};

int main() {
    Stack stack;

    stack.reset();

    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.push(9);

    stack.print();

    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;

    stack.print();

    return 0;
}
