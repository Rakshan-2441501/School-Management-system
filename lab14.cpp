#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person() {
    }

    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Admin {
public:
    int allocateLeaves(int totalLeaveDays, int leavesTaken) {
        int remainingLeaves = totalLeaveDays - leavesTaken;
        return remainingLeaves < 0 ? 0 : remainingLeaves;
}
    float calculateSalary(float baseSalary, int hoursAttended, int teachingHours) {
        if (hoursAttended < teachingHours) {
            float deduction = (teachingHours - hoursAttended) * (baseSalary / teachingHours);
            return baseSalary - deduction;
        }
        return baseSalary; 
    }

    float calculateOvertime(float baseSalary, int teachingHours) {
        if (teachingHours > 40) {
            float overtimeHours = teachingHours - 40;
            return (baseSalary / 40) * 1.5 * overtimeHours;
        }
        return 0;
    }
};

class Employee : public Person {
public:
    int employeeID;
    float baseSalary;
    int totalLeaveDays;
    int leavesTaken;
    int teachingHours;

    Employee() {}
    Employee(string n, int a, int id, float salary, int totalLeave, int hours) {
        name = n;
        age = a;
        employeeID = id;
        baseSalary = salary;
        totalLeaveDays = totalLeave;
        leavesTaken = 0; 
        teachingHours = hours;
    }
    void displayEmployee() const {
        displayPerson();
        cout << "Employee ID: " << employeeID << ", Base Salary: " << baseSalary 
             << ", Teaching Hours: " << teachingHours << endl;
    }
    void takeLeave(int days) {
        leavesTaken += days;
        cout << "Leaves taken: " << leavesTaken << " days\n";
    }
};
class Teacher : public Employee {
public:
    string subject;
    Teacher() {}
    Teacher(string n, int a, int id, float salary, int totalLeave, int hours, string sub) {
        name = n;
        age = a;
        employeeID = id;
        baseSalary = salary;
        totalLeaveDays = totalLeave;
        leavesTaken = 0; 
        teachingHours = hours;
        subject = sub;
    }

    void displayTeacher() const {
        displayEmployee();
        cout << "Subject: " << subject << endl;
    }
};
class Principal : public Employee, public Admin {
public:
    Principal() {}

    Principal(string n, int a, int id, float salary, int totalLeave, int hours) {
        name = n;
        age = a;
        employeeID = id;
        baseSalary = salary;
        totalLeaveDays = totalLeave;
        leavesTaken = 0; 
        teachingHours = hours;
    }

    void displayPrincipal() const {
        displayEmployee();
    }

    void manageSalaryAndLeaves(int hoursAttended) {
        int remainingLeaves = allocateLeaves(totalLeaveDays, leavesTaken);
        cout << "Remaining Leaves: " << remainingLeaves << endl;

        float netSalary = calculateSalary(baseSalary, hoursAttended, teachingHours);
        float overtime = calculateOvertime(baseSalary, teachingHours);
        cout << "Net Salary after deductions: " << netSalary + overtime << endl;

        if (overtime > 0) {
            cout << "Overtime pay: " << overtime << endl;
        }
    }
};

int main() {
    Admin admin;
    Teacher teacher;
    Principal principal;

    int choice;
    bool continueProgram = true;

    while (continueProgram) {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Add Teacher\n";
        cout << "2. Display Teacher Details\n";
        cout << "3. Manage Teacher's Salary and Leave\n";
        cout << "4. Add Principal\n";
        cout << "5. Display Principal Details\n";
        cout << "6. Manage Principal's Salary and Leave\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { 
                string name, subject;
                int age, id, totalLeave, teachingHours;

                cout << "\nEnter Teacher's Name: ";
                cin >> name;
                cout << "Enter Teacher's Age: ";
                cin >> age;
                cout << "Enter Teacher's ID: ";
                cin >> id;
                cout << "Enter Teacher's Base Salary: ";
                cin >> teacher.baseSalary; 
                cout << "Enter Total Leave Days: ";
                cin >> totalLeave;
                cout << "Enter Teaching Hours: ";
                cin >> teachingHours;
                cout << "Enter Teacher's Subject: ";
                cin >> subject;

                teacher = Teacher(name, age, id, teacher.baseSalary, totalLeave, teachingHours, subject);
                break;
            }
            case 2: 
                if (teacher.employeeID != 0) {
                    cout << "\n--- Teacher Details ---\n";
                    teacher.displayTeacher();
                } else {
                    cout << "No Teacher entered!\n";
                }
                break;
            case 3:
                if (teacher.employeeID != 0) {
                    cout << "\n--- Managing Teacher's Salary and Leave ---\n";
                    int hoursAttended;
                    cout << "Enter hours attended by the teacher: ";
                    cin >> hoursAttended;
                    principal.manageSalaryAndLeaves(hoursAttended);
                } else {
                    cout << "No Teacher entered!\n";
                }
                break;
            case 4: { 
                string name;
                int age, id, totalLeave, teachingHours;

                cout << "\nEnter Principal's Name: ";
                cin >> name;
                cout << "Enter Principal's Age: ";
                cin >> age;
                cout << "Enter Principal's ID: ";
                cin >> id;
                cout << "Enter Principal's Base Salary: ";
                cin >> principal.baseSalary; 
                cout << "Enter Total Leave Days: ";
                cin >> totalLeave;
                cout << "Enter Teaching Hours: ";
                cin >> teachingHours;

                principal = Principal(name, age, id, principal.baseSalary, totalLeave, teachingHours);
                break;
            }
            case 5: 
                if (principal.employeeID != 0) {
                    cout << "\n--- Principal Details ---\n";
                    principal.displayPrincipal();
                } else {
                    cout << "No Principal entered!\n";
                }
                break;
            case 6:
                if (principal.employeeID != 0) {
                    cout << "\n--- Managing Principal's Salary and Leave ---\n";
                    int hoursAttended;
                    cout << "Enter hours attended by the principal: ";
                    cin >> hoursAttended;
                    principal.manageSalaryAndLeaves(hoursAttended);
                } else {
                    cout << "No Principal entered!\n";
                }
                break;
            case 7:
                continueProgram = false;
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }

    return 0;
}

