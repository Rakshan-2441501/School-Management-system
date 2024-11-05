#include <iostream>
using namespace std;

void updateGradeByValue(int grade) {
    grade = 90;  
    cout << "Updated grade: " << grade << endl;
}

void updateGradeByReference(int &grade) {
    grade = 90;  
    cout << "Updated grade: " << grade << endl;
}
string& updateName(string &name) {
    name = "Updated Name"; 
    return name;  
}
int main() {
    int studentGrade = 75;
    cout << "Pass by value =>\n" << endl;
    cout << "Original grade: " << studentGrade << endl;
    updateGradeByValue(studentGrade);
    cout << "Original grade: " << studentGrade << endl;
    
    cout << "\nPass by reference =>" << endl;
    cout << "\nOriginal grade: " << studentGrade << endl;
    updateGradeByReference(studentGrade); 
    cout << "Original grade: " << studentGrade << endl;
    
    cout << "\nReturn by reference =>" << endl;
    string studentName = "Prasanth";
    cout << "\nOriginal name: " << studentName << endl;
    string &newName = updateName(studentName);  
    cout << "Original name: " << studentName << endl;
    cout << "New name: " << newName << endl;

    return 0;
}

