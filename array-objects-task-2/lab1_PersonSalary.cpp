#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Person {
private:
    string m_name;
    double m_salary;
    double m_bonus;
    double m_rate;
    int m_position;

    double determineRate() const {
        switch (m_position) {
            case 1: return 12000.0;
            case 2: return 14000.0;
            case 3: return 16000.0;
            case 4: return 18000.0;
            case 5: return 22000.0;
            case 6: return 30000.0;
            default: return 0.0;
        }
    }

public:
    Person()
        : m_name("Не вказано"), m_salary(0.0), m_bonus(0.0),
          m_rate(0.0), m_position(1) {
        m_rate = determineRate();
        calculateSalary();
    }

    Person(const string& name, int position)
        : m_name(name), m_salary(0.0), m_bonus(0.0),
          m_rate(0.0), m_position(position) {
        m_rate = determineRate();
        calculateSalary();
    }

    ~Person() = default;

    void calculateSalary() {
        m_salary = m_rate;
    }

    void calculateBonus(double averageSalary) {
        m_bonus = (m_salary < averageSalary)
                    ? m_salary * 0.10
                    : m_salary * 0.05;
    }

    double getSalary() const {
        return m_salary;
    }

    double getBonus() const {
        return m_bonus;
    }

    double getTotalPay() const {
        return m_salary + m_bonus;
    }

    void print() const {
        static const string positions[] = {
            "", "Спеціаліст", "Спеціаліст II категорії",
            "Спеціаліст I категорії", "Спеціаліст вищої категорії",
            "Начальник відділу", "Директор"
        };

        cout << left << setw(24) << m_name
             << setw(30) << positions[m_position >= 1 && m_position <= 6
                                        ? m_position : 0]
             << right << setw(12) << fixed << setprecision(2) << m_rate
             << setw(12) << m_bonus
             << setw(14) << getTotalPay() << '\n';
    }
};

int main() {
    const int COUNT = 4;

    Person employees[COUNT] = {
        Person("Іваненко І.І.", 1),
        Person("Петренко П.П.", 3),
        Person("Коваленко О.О.", 5),
        Person("Шевченко А.А.", 6)
    };

    double totalSalary = 0.0;
    for (int i = 0; i < COUNT; ++i) {
        totalSalary += employees[i].getSalary();
    }
    const double averageSalary = totalSalary / COUNT;

    Person* ptr = employees;
    for (int i = 0; i < COUNT; ++i) {
        (ptr + i)->calculateBonus(averageSalary);
    }

    cout << "Середня заробітна плата: "
         << fixed << setprecision(2) << averageSalary << "\n\n";

    cout << left << setw(24) << "Працівник"
         << setw(30) << "Посада"
         << right << setw(12) << "Ставка"
         << setw(12) << "Премія"
         << setw(14) << "До виплати" << '\n';
    cout << string(92, '-') << '\n';

    for (int i = 0; i < COUNT; ++i) {
        (ptr + i)->print();
    }

    cout << "\nПеревірка доступу через вказівник:\n";
    Person* firstEmployee = &employees[0];
    firstEmployee->print();

    return 0;
}

// Контрольні питання до лабораторної №1:
// 1. Вказівник на об'єкт оголошується як Person* ptr;.
// 2. Вказівник - змінна, що зберігає адресу іншого об'єкта/змінної.
// 3. До елемента масиву об'єктів можна звернутися через employees[i].
// 4. Через вказівник доступ до відкритих членів виконується оператором ->.
// 5. Масив об'єктів можна ініціалізувати конструкторами або створити масив
//    об'єктів за замовчуванням і присвоїти їм значення пізніше.
// 6. Двовимірний масив об'єктів: Person people[2][3];.
// 7. Прототип конструктора, наприклад: Person(const string& name, int position);
// 8. Масив із чотирьох об'єктів: Person people[4];.

