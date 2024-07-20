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
    // Parameterized constructor
    Student(const string& studentName, int studentRollNumber, int studentSemester, const string& studentBranch, const string& studentEmail, const string& studentAddress)
        : name(studentName), rollNumber(studentRollNumber), semester(studentSemester), branch(studentBranch), email(studentEmail), address(studentAddress) {
        cout << "Student object created with details." << endl;
    }

    // Destructor
    ~Student() {
        cout << "Student object destroyed." << endl;
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

    // Member function to search for student details by name
    void searchDetails(const string& query) const {
        if (name == query) {
            cout << "Student found. Details:" << endl;
            displayDetails();
        } else {
            cout << "Student not found." << endl;
        }
    }
};

int main() {
    // Create students using the parameterized constructor
    Student s1("Alice", 101, 3, "Computer Science", "alice@example.com", "123 Street, City");
    Student s2("Bob", 102, 4, "Electrical Engineering", "bob@example.com", "456 Avenue, City");
    Student s3("Charlie", 103, 2, "Mechanical Engineering", "charlie@example.com", "789 Boulevard, City");

    // Display student details
    cout << "\nDetails of s1:" << endl;
    s1.displayDetails();

    cout << "\nDetails of s2:" << endl;
    s2.displayDetails();

    cout << "\nDetails of s3:" << endl;
    s3.displayDetails();

    // Search for a student
    string query = "Bob";
    cout << "\nSearching for student with name '" << query << "':" << endl;
    s2.searchDetails(query);

    query = "David";
    cout << "\nSearching for student with name '" << query << "':" << endl;
    s2.searchDetails(query);

    // Objects will be automatically destroyed when they go out of scope

    return 0;
}
