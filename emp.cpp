#include<iostream>
#include<string>
using namespace std;
class emp {
string* emp_nm;
string* emp_post;
int* emp_sal;
int* emp_age;
int* emp_id;
public:
emp(int n) 
{
emp_nm = new string[n];
emp_post = new string[n];
emp_sal = new int[n];
emp_age = new int[n];
emp_id = new int[n];
}
void get(int n) 
{
for(int j =0; j<n;j++) 
{
cout << "Enter the details of employee  " << (j+1) << "\n";
cout << "Enter the name: ";
cin >> emp_nm[j];
cout << "Enter the post: ";
cin >> emp_post[j];
cout << "Enter the employee ID: ";
cin >> emp_id[j];
if(emp_id[j]<0) {
cout << "Invalid Input, please enter a valid ID.\n";
exit(0);
}
cout << "Enter the age: ";
cin >> emp_age[j];
if(emp_age[j]<0) {
cout << "Invalid Input, please enter a valid age.\n";
exit(0);
}
cout << "Enter the salary: ";
cin >> emp_sal[j];
if(emp_sal[j] <= 0) {
cout << "Invalid Input, salary cannot be <= 0.\n";
exit(0);
}
}
}

    void details(int nn) {
        for(int j = 0; j < nn; j++) {
            cout << "______________________________________________\n";
            cout << "Employee Details  " << (j+1) << "\n";
            cout << "ID: " << emp_id[j] << "\n";
            cout << "Name: " << emp_nm[j] << "\n";
            cout << "Age: " << emp_age[j] << "\n";
            cout << "Post: " << emp_post[j] << "\n";
            emp_sal[j] = salary(emp_sal[j], emp_age[j]); 
            cout << "Salary: " << emp_sal[j] << "\n";
        }
    }

    int salary(int x, int y) {
        if(y > 22 && y <= 30)
            x += 2000;
        else if(y > 30 && y < 40)
            x += 4000;
        else if(y > 40 && y < 50)
            x += 7000;
        else
            x += 10000;
        return x;
    }
};

int main() {
    int size;
    cout << "Enter the number of employees: ";
    cin >> size;

    emp obj(size);
    obj.get(size);
    obj.details(size);

    return 0;
}

