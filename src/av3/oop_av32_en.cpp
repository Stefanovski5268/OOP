#include <iostream>
#include <string.h>
using namespace std;

enum position {
    employee, manager, owner
};

class Person {
private:
    char name[100];
    int salary;
    position pos;
public:
    // Constructors
    Person() {
    }

    Person(char *name, int salary, position pos) {
        strcpy(this->name, name);
        this->salary = salary;
        this->pos = pos;
    }
    // Destruktor
    ~Person() {
    }

    void setName(char const *name) {
        strcpy(this->name, name);
    }
    void setSalary(int const salary) {
        this->salary = salary;
    }
    void setPosition(position p) {
        pos = p;
    }
    char *getName() const {
        return name;
    }
    int getSalary() const {
        return salary;
    }
    position getPosition() const {
        return pos;
    }
};

void sort(Person a[], int n) {
    int i, j;
    Person p;
    for (i = 0; i < n - 1; i++)
        for (j = i; j < n; j++)
            if (a[i].getSalary() < a[j].getSalary()) {
                p = a[j];
                a[j] = a[i];
                a[i] = p;
            }
}

int main() {
    Person employees[100];
    float salary;
    int n, pos;
    char name[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name;
        cin >> salary;
        cin >> pos;
        employees[i].setName(name);
        employees[i].setSalary(salary);
        employees[i].setPosition((position) pos);
    }
    sort(employees, n);
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << employees[i].getName() << "\t"
             << employees[i].getSalary() << "\t"
             << employees[i].getPosition() << endl;
    }
    return 0;
}
