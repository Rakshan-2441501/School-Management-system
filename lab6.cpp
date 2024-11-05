#include <iostream>
using namespace std;

class TransportStaff {
private:
    string name;
    int staffID;
    float salary;
    string vehicleType;

public:
    TransportStaff() {
        name = "----";
        staffID = 0;
        salary = 0.0;
        vehicleType = "----";
    }
    TransportStaff(string n, int id) {
        name = n;
        staffID = id;
        salary = 0.0;  
        vehicleType = "----";
    }
    TransportStaff(string n, int id, float s) {
        name = n;
        staffID = id;
        salary = s;
        vehicleType = "----";
    }
    TransportStaff(string n, int id, float s, string v) {
        name = n;
        staffID = id;
        salary = s;
        vehicleType = v;
    }
    void displayDetails(){
        cout << "\nStaff Name: " << name << endl;
        cout << "Staff ID: " << staffID << endl;
        cout << "Salary: " << salary << endl;
        cout << "Vehicle Type: " << vehicleType << endl;
    }
};

int main() {
    TransportStaff staff1;
    staff1.displayDetails();
    
    TransportStaff staff2("Surya", 101);
    staff2.displayDetails();

    TransportStaff staff3("Simon", 102, 30000.0);
    staff3.displayDetails();

    TransportStaff staff4("Prasanth", 103, 31000.0, "19ABC");
    staff4.displayDetails();

    return 0;
}

