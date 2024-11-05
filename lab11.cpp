#include <iostream>

using namespace std;

class Student {
private:
    string name;
    int grade;
    int age;
    int marks[5];  
public:
    Student() {
        name = ""; 
        grade = 0; 
        age = 0;
        for (int i = 0; i < 5; i++) {
            marks[i] = 0;  
        }
    }

    void input() {
        cout << "Enter student's name: ";
        cin >> name;

        cout << "Enter student's grade: ";
        cin >> grade;

        cout << "Enter student's age: ";
        cin >> age;

        cout << "Enter student's marks for 5 subjects:\n";
        cout << "Math: "; cin >> marks[0];
        cout << "Computer: "; cin >> marks[1];
        cout << "Physics: "; cin >> marks[2];
        cout << "Chemistry: "; cin >> marks[3];
        cout << "English: "; cin >> marks[4];
    }

    int* getSubjectMarks(const string& subject) {
        if (subject == "Math" || subject == "math") return &marks[0];
        if (subject == "Computer" || subject == "computer") return &marks[1];
        if (subject == "Physics" || subject == "physics") return &marks[2];
        if (subject == "Chemistry" || subject == "chemistry") return &marks[3];
        if (subject == "English" || subject == "English") return &marks[4];
        return 0; 
    }

    int totalMarks() const {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += marks[i];
        }
        return sum;
    }

    void display() const {
        cout << "Name: " << name
             << ", Grade: " << grade
             << ", Age: " << age
             << ", Total Marks: " << totalMarks() << endl;
    }

    void displayRank(int rank) const {
        cout << "Rank " << rank << ": " << name << " (Total Marks: " << totalMarks() << ")" << endl;
    }

    int getTotalMarks() const {
        return totalMarks();
    }

    // Subscript operator to access marks by index
    int& operator[](int index) {
        if (index >= 0 && index < 5) {
            return marks[index];
        } else {
            cout << "Invalid index ." << endl;
            return marks[0];  
        }
    }
};

int main() {
    Student students[100];  
    int n = 0; 
    int choice;
    cout << "This program allows teachers to add, modify and sort the student marks" << endl;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Modify Marks of a Student\n";
        cout << "4. Sort Students by Total Marks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (n < 100) {
                    students[n].input();
                    n++;
                } else {
                    cout << "Maximum number of students reached!" << endl;
                }
                break;
            case 2:
                if (n == 0) {
                    cout << "No students to display." << endl;
                } else {
                    cout << "\nStudent details:\n";
                    for (int i = 0; i < n; i++) {
                        cout << "Student " << i + 1 << ": " << endl;
                        students[i].display();
                    }
                }
                break;
            case 3:
                if (n == 0) {
                    cout << "No students to modify." << endl;
                } else {
                    int studentIndex;
                    cout << "Enter the index of the student to modify marks (1 to " << n << "): ";
                    cin >> studentIndex;
                    if (studentIndex >= 1 && studentIndex <= n) {
                        int subjectIndex;
                        int newMark;
                        cout << "Enter the subject index to modify (0: Math, 1: Computer, 2: Physics, 3: Chemistry, 4: English): ";
                        cin >> subjectIndex;

                        if (subjectIndex >= 0 && subjectIndex < 5) {
                            cout << "Enter new mark: ";
                            cin >> newMark;
                            students[studentIndex - 1][subjectIndex] = newMark;  // Using subscript operator
                        } else {
                            cout << "Invalid subject index!" << endl;
                        }
                    } else {
                        cout << "Invalid student index!" << endl;
                    }
                }
                break;
            case 4:
                if (n == 0) {
                    cout << "No students to sort." << endl;
                } else {
                    for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (students[j].getTotalMarks() < students[j + 1].getTotalMarks()) {
            Student temp = students[j];  
            students[j] = students[j + 1];
            students[j + 1] = temp;
        }
    }
}
                    cout << "\nStudents sorted by total marks.\n";
                }
                break;
            case 5:
                cout << "Thank you for using this platform. Have a nice day.\n";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

