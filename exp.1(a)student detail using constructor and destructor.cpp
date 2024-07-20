#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    int semester;
    string branch;
    string email;
    string address;

public:
    // Default constructor
    Student() : name(""), rollNumber(0), semester(0), branch(""), email(""), address("") {
        cout << "Student object created." << endl;
    }

    // Destructor
    ~Student() {
        cout << "Student object destroyed." << endl;
    }

    // Member function to input student details
    void inputDetails() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Semester: ";
        cin >> semester;
        cout << "Enter Branch: ";
        cin.ignore(); // Ignore newline left in the buffer
        getline(cin, branch);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Address: ";
        getline(cin, address);
    }

    // Member function to display student details
    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Semester: " << semester << endl;
        cout << "Branch: " << branch << endl;
        cout << "Email: " << email << endl;
        cout << "Address: " << address << endl;
    }
};

int main() {
    Student s1, s2, s3;

    cout << "Enter details for s1:" << endl;
    s1.inputDetails();
    cout << "\nDetails entered for s1:" << endl;
    s1.displayDetails();

    cout << "\nEnter details for s2:" << endl;
    s2.inputDetails();
    cout << "\nDetails entered for s2:" << endl;
    s2.displayDetails();

    cout << "\nEnter details for s3:" << endl;
    s3.inputDetails();
    cout << "\nDetails entered for s3:" << endl;
    s3.displayDetails();

    // Objects will be automatically destroyed when they go out of scope

    return 0;
}
