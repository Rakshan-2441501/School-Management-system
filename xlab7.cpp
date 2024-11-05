#include <iostream>
using namespace std;

class Employee {
private:
    int id;
    string name;
    float basicSalary;
    float allowances;
    float deductions;

    static float totalPayroll;

public:
    Employee(int empId, string empName, float empBasicSalary, float empAllowances, float empDeductions) {
        id = empId;
        name = empName;
        basicSalary = empBasicSalary;
        allowances = empAllowances;
        deductions = empDeductions;
        totalPayroll += calculateNetSalary(); 
    }
    Employee() {
        id = 0;
        name = "";
        basicSalary = 0.0;
        allowances = 0.0;
        deductions = 0.0;
    }
    void inputEmployeeDetails() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
        cout << "Enter Allowances: ";
        cin >> allowances;
        cout << "Enter Deductions: ";
        cin >> deductions;1q
        totalPayroll += calculateNetSalary(); 
    }
    float calculateNetSalary() const {
        return (basicSalary + allowances - deductions);
    }
    static float getTotalPayroll() {
        return totalPayroll;
    }
    void displayEmployeeDetails() const {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Allowances: " << allowances << endl;
        cout << "Deductions: " << deductions << endl;
        cout << "Net Salary: " << calculateNetSalary() << endl;
    }
};
float Employee::totalPayroll = 0;

int main() {
    int n;
    cout << "This program calculates the total payroll:" << endl;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee employees[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Employee " << i + 1 << ":" << endl;
        employees[i].inputEmployeeDetails();
    }

    for (int i = 0; i < n; i++) {
        cout << "\nEmployee " << i + 1 << " details:" << endl;
        employees[i].displayEmployeeDetails();
    }

    cout << "\nTotal payroll for all employees: " << Employee::getTotalPayroll() << endl;

    return 0;
}

