#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int* grades; 
    int numGrades;

public:
    Student(string name, int numGrades) {
        this->name = name;
        this->numGrades = numGrades;
        grades = new int[numGrades];  
        cout << "Constructor: Memory allocated for " << numGrades << " grades for student " << name << endl;
    }

    ~Student() {
        delete[] grades; 
        cout << "Destructor: Memory deallocated for student " << name << endl;
    }
    
    void inputGrades() {
        cout << "Enter grades for " << name << ": " << endl;
        for (int i = 0; i < numGrades; ++i) {
            cout << "Grade " << i + 1 << ": ";
            cin >> grades[i];
        }
    }

    int totalMarks() const {
        int total = 0;
        for (int i = 0; i < numGrades; ++i) {
            total += grades[i];
        }
        return total;
    }

    void displayGrades() const {
        cout << "Grades for " << name << ": ";
        for (int i = 0; i < numGrades; ++i) {
            cout << grades[i] << " ";
        }
        cout << " | Total: " << totalMarks() << endl;
    }

    string getName() const {
        return name;
    }
};

void bubbleSortStudents(Student** students, int numStudents) {
    for (int i = 0; i < numStudents - 1; ++i) {
        for (int j = 0; j < numStudents - i - 1; ++j) {
            if (students[j]->totalMarks() < students[j + 1]->totalMarks()) {
                Student* temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student** students = new Student*[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        string name;
        int numGrades;
        cout << "\nEnter the name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter the number of grades for " << name << ": ";
        cin >> numGrades;

        students[i] = new Student(name, numGrades);
        students[i]->inputGrades();
    }

    bubbleSortStudents(students, numStudents);

    cout << "\nDisplaying all students' grades and rankings:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "Rank " << i + 1 << ": " << students[i]->getName() << " | ";
        students[i]->displayGrades();
    }
    for (int i = 0; i < numStudents; ++i) {
        delete students[i];  
    }
    delete[] students;

    cout << "All memory has been deallocated.\n";
    return 0;
}

