#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int empID;
    float salary;

public:
    Employee() {
        name = "Unknown";
        empID = 0;
        salary = 0.0;
        cout << "Default constructor called.\n";
    }
    Employee(string n, int id, float s) {
        name = n;
        empID = id;
        salary = s;
        cout << "Parameterized constructor called.\n";
    }
    Employee(const Employee &e) {
        name = e.name;
        empID = e.empID;
        salary = e.salary;
        cout << "Copy constructor called.\n";
    }
    void displayDetails() const {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << empID << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Employee emp1;
    emp1.displayDetails();

    Employee emp2("John Doe", 101, 5000.0);
    emp2.displayDetails();

    Employee emp3 = emp2;  
    cout << "\nDisplaying copied employee details (emp3):\n";
    emp3.displayDetails();

    return 0;
}

