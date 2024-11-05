#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int grade;
    int age;

public:
    Student() {
        name = "";
        grade = 0;
        age = 0;
    }

    Student(string name, int grade, int age) {
        this->name = name;
        this->grade = grade;
        this->age = age;
    }

    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter grade: ";
        cin >> grade;
        cout << "Enter age: ";
        cin >> age;
    }

    void display() const {
        cout << "Name: " << name << ", Grade: " << grade << ", Age: " << age << endl;
    }

    Student operator++() {
        ++grade;
        return *this;
    }

    Student operator--() {
        --grade;
        return *this;
    }

    Student operator-() const {
        return Student(name, -grade, age);
    }

    Student operator+(const Student& other) {
        return Student(name + " & " + other.name, grade, age + other.age);
    }

    bool operator==(const Student& other) const {
        return this->grade == other.grade;
    }

   void printDetails() const {
    cout << "Name: " << name << ", Grade: " << grade << ", Age: " << age;
}
};

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Display a student's details\n";
    cout << "2. Increment a student's grade\n";
    cout << "3. Decrement a student's grade\n";
    cout << "4. Negate a student's grade\n";
    cout << "5. Combine two students\n";
    cout << "6. Compare two students\n";
    cout << "7. Exit\n";
    cout << "Choose an option: ";
}

int main() {
	cout << "This program demonstrates the use of operator overloading: " << endl;
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    if (n < 1) {
        cout << "You need to input at least one student." << endl;
        return 1;
    }

    Student students[100];
    
    // Input details for each student
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i].input();
    }

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            // Display a student's details
            int id = 0;
            cout << "Enter the student index to display: ";
            cin >> id;
            if (id >= 1 && id <= n) {
                students[id - 1].display();
            } else {
                cout << "There is no such student" << endl;
            }
            break;
        }
        case 2: {
            // Increment a student's grade
            int index;
            cout << "Enter the index of the student to increment (1 to " << n << "): ";
            cin >> index;
            if (index >= 1 && index <= n) {
                ++students[index - 1];
                cout << "Incremented grade of student " << index << ".\n";
                students[index - 1].display();
            } else {
                cout << "There is no such student.\n";
            }
            break;
        }

        case 3: {
            // Decrement a student's grade
            int index;
            cout << "Enter the index of the student to decrement (1 to " << n << "): ";
            cin >> index;
            if (index >= 1 && index <= n) {
                --students[index - 1];
                cout << "Decremented grade of student " << index << ".\n";
                students[index - 1].display();
            } else {
                cout << "There is no such student.\n";
            }
            break;
        }

        case 4: {
            // Negate a student's grade
            int index;
            cout << "Enter the index of the student to negate grade (1 to " << n << "): ";
            cin >> index;
            if (index >= 1 && index <= n) {
                Student negated = -students[index - 1];
                cout << "Negated grade of student " << index << ":\n";
                negated.display();
            } else {
                cout << "There is no such student.\n";
            }
            break;
        }

        case 5: {
            // Combine two students (blocked if only one student)
            if (n < 2) {
                cout << "Only one student has been updated, you can't combine students." << endl;
            } else {
                int index1, index2;
                cout << "Enter the index of the first student (1 to " << n << "): ";
                cin >> index1;
                cout << "Enter the index of the second student (1 to " << n << "): ";
                cin >> index2;
                if (index1 >= 1 && index1 <= n && index2 >= 1 && index2 <= n) {
                    Student combined = students[index1 - 1] + students[index2 - 1];
                    cout << "Combined students:\n";
                    combined.display();
                } else {
                    cout << "There is no such student.\n";
                }
            }
            break;
        }

        case 6: {
            // Compare two students (blocked if only one student)
            if (n < 2) {
                cout << "Only one student has been updated, you can't compare students." << endl;
            } else {
                int index1, index2;
                cout << "Enter the index of the first student (1 to " << n << "): ";
                cin >> index1;
                cout << "Enter the index of the second student (1 to " << n << "): ";
                cin >> index2;
                if (index1 >= 1 && index1 <= n && index2 >= 1 && index2 <= n) {
                    if (students[index1 - 1] == students[index2 - 1]) {
                        cout << "The students have the same grade.\n";
                    } else {
                        cout << "The students have different grades.\n";
                    }
                } else {
                    cout << "There is no such student.\n";
                }
            }
            break;
        }

        case 7:
            cout << "Thank you, have a nice day!" << endl;
            break;

        default:
            cout << "Invalid choice, please try again.\n";
        }

    } while (choice != 7);

    return 0;
}

