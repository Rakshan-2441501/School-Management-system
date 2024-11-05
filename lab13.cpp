#include <iostream>
using namespace std;
class Person {
public:
    string name;
    int age;
    string gender;

    Person() {}

    Person(string n, int a, string g) {
        name = n;
        age = a;
        gender = g;
    }

    void displayPerson() {
        cout << "Name: " << name << ", Age: " << age << ", Gender: " << gender << endl;
    }
};

class Student : public Person {
public:
    string studentID;
    int totalDays;
    int presentDays;

    Student() {}

    Student(string n, int a, string g, string id, int total, int present) : Person(n, a, g) {
        studentID = id;
        totalDays = total;
        presentDays = present;
    }

    float calculateAttendance() {
        return ((float)presentDays / totalDays) * 100;
    }

    void displayStudent() {
        displayPerson();
        cout << "Student ID: " << studentID << ", Attendance: " << calculateAttendance() << "%" << endl;
    }
};

class Parent : public Person {
public:
    string phoneNumber;

    Parent() {}

    Parent(string n, int a, string g, string phone) : Person(n, a, g) {
        phoneNumber = phone;
    }

    void sendNotification() {
        cout << "Notification sent to parent (" << name << ") at phone number: " << phoneNumber << endl;
    }
};

class Teacher : public Person {
public:
    string subject;
    Teacher() {}

    Teacher(string n, int a, string g, string s) : Person(n, a, g) {
        subject = s;
    }

    void checkAttendance(Student student, Parent parent) {
        cout << "\nChecking attendance for student: " << student.name << endl;
        student.displayStudent();
        if (student.calculateAttendance() < 75) {
            cout << "Attendance is below 75%. Sending notification to parent..." << endl;
            parent.sendNotification();
        } else {
            cout << "Attendance is satisfactory.\n";
        }
    }
};
string inputGender() {
    string gender;
    while (true) {
        cout << "Gender (m/f): ";
        cin >> gender;
        if (gender == "m" || gender == "f") {
            break;
        } else {
            cout << "Invalid gender. Please enter 'm' for male or 'f' for female." << endl;
        }
    }
    return gender;
}
string inputPhoneNumber() {
    string phone;
    while (true) {
        cout << "Phone Number: ";
        cin >> phone;
        if (phone.length() == 10 && phone.find_first_not_of("0123456789") == string::npos) {
            break;
        } else {
            cout << "Invalid phone number. Please enter a 10-digit number." << endl;
        }
    }
    return phone;
}

int main() {
	cout << "This program finds the attendance percentage of the student and do the required things if the attendance is less" << endl;
    Teacher teacher("John Doe", 40, "Male", "Mathematics");

    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student students[numStudents];
    Parent parents[numStudents];

    for (int i = 0; i < numStudents; i++) {
        string studentName, studentGender, studentID, parentName, parentGender, parentPhone;
        int studentAge, totalDays, presentDays, parentAge;

        cout << "\nEnter details for Student " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> studentName;

        while (true) {
            cout << "Age: ";
            cin >> studentAge;
            if (studentAge > 0) break;
            cout << "Invalid age. Please enter a positive number." << endl;
        }

        studentGender = inputGender();

        cout << "Student ID: ";
        cin >> studentID;

        while (true) {
            cout << "Total Days: ";
            cin >> totalDays;
            if (totalDays > 0) break;
            cout << "Invalid number of total days. Please enter a positive number." << endl;
        }

        while (true) {
            cout << "Present Days: ";
            cin >> presentDays;
            if (presentDays >= 0 && presentDays <= totalDays) break;
            cout << "Invalid number of present days. It must be between 0 and " << totalDays << "." << endl;
        }

        students[i] = Student(studentName, studentAge, studentGender, studentID, totalDays, presentDays);

        cout << "\nEnter details for Parent of " << studentName << ":\n";
        cout << "Name: ";
        cin >> parentName;

        while (true) {
            cout << "Age: ";
            cin >> parentAge;
            if (parentAge > 0) break;
            cout << "Invalid age. Please enter a positive number." << endl;
        }

        parentGender = inputGender();
        parentPhone = inputPhoneNumber();
        parents[i] = Parent(parentName, parentAge, parentGender, parentPhone);
    }
    for (int i = 0; i < numStudents; i++) {
        teacher.checkAttendance(students[i], parents[i]);
    }

    return 0;
}

