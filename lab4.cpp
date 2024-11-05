#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float mrks[5];
    friend void compareMarks(Student s1, Student s2);

public:
    Student(string n, int roll, float mrk[] ) {
        name = n;
        rollNumber = roll;
        for(int i=0;i<5;i++)
        mrks[i]=mrk[i];
    }
    void displayDetails() {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
    }
    float totalMarks() {
    	float total;
    	total=0;
    	for(int i=0;i<5;i++)
    	total+=mrks[i];
        return total;
    }
};
void compareMarks(Student s1, Student s2) {
    float total1 = s1.totalMarks();
    float total2 = s2.totalMarks();

    s1.displayDetails();
    cout << "Total Marks: " << total1 << endl;

    s2.displayDetails();
    cout << "Total Marks: " << total2 << endl;

    if (total1 > total2) {
        cout << s1.name << " has higher total marks.\n";
    } else if (total2 > total1) {
        cout << s2.name << " has higher total marks.\n";
    } else {
        cout << "Both students have equal total marks.\n";
    }
}

int main() {
	float st[5];
	string nm;
	int ro;
	cout << "Enter the name of student 1" << endl;
	cin >> nm;
	cout << "Enter the roll no:" << endl;
	cin >> ro;
	cout << "Enter the marks :" << endl;
	for(int i=0;i<5;i++)
	cin >> st[i];
    Student student1(nm,ro,st);
    cout << "Enter the name of student 2" << endl;
	cin >> nm;
	cout << "Enter the roll no:" << endl;
	cin >> ro;
	cout << "Enter the marks :" << endl;
	for(int i=0;i<5;i++)
	cin >> st[i];
    Student student2(nm,ro,st);
    compareMarks(student1, student2);
    return 0;
}

