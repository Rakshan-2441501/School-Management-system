#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}

    virtual void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    virtual ~Person() {}
};

class Student : public Person {
    int studentID;
public:
    Student(string n, int a, int id) : Person(n, a), studentID(id) {}

    void displayInfo() const override {
        cout << "Student Name: " << name << ", Age: " << age << ", Student ID: " << studentID << endl;
    }
};

class Teacher : public Person {
    string subject;
public:
    Teacher(string n, int a, string s) : Person(n, a), subject(s) {}

    void displayInfo() const override {
        cout << "Teacher Name: " << name << ", Age: " << age << ", Subject: " << subject << endl;
    }
};

void showMenu() {
    cout << "\nSchool Management System Menu:\n";
    cout << "1. Add Student\n";
    cout << "2. Add Teacher\n";
    cout << "3. Display All\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    const int MAX = 100;
    Person* people[MAX];
    int count = 0;
    int choice;
    bool running = true;

    while (running) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int age, id;
                cout << "Enter Student's Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Student ID: ";
                cin >> id;
                people[count++] = new Student(name, age, id);
                cout << "Student added successfully!\n";
                break;
            }
            case 2: {
                string name, subject;
                int age;
                cout << "Enter Teacher's Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Subject: ";
                cin.ignore();
                getline(cin, subject);
                people[count++] = new Teacher(name, age, subject);
                cout << "Teacher added successfully!\n";
                break;
            }
            case 3: {
                if (count == 0) {
                    cout << "No records to display.\n";
                } else {
                    for (int i = 0; i < count; i++) {
                        people[i]->displayInfo();
                    }
                }
                break;
            }
            case 4: {
                running = false;
                break;
            }
            default:
                cout << "Invalid choice, please try again.\n";
        }

        if (running) {
            char cont;
            cout << "Do you want to continue? (y/n): ";
            cin >> cont;
            if (cont == 'n' || cont == 'N') {
                running = false;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        delete people[i];
    }

    cout << "Exiting the system. Goodbye!\n";
    return 0;
}

