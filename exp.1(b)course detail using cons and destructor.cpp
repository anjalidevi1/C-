#include <iostream>
#include <string>

using namespace std;

class Course {
private:
    string courseName;
    int courseCode;
    int credits;
    string instructor;
    string description;

public:
    // Default constructor
    Course() : courseName(""), courseCode(0), credits(0), instructor(""), description("") {
        cout << "Course object created." << endl;
    }

    // Destructor
    ~Course() {
        cout << "Course object destroyed." << endl;
    }

    // Member function to input course details
    void inputDetails() {
        cout << "Enter course name: ";
        getline(cin, courseName);
        cout << "Enter Course Code: ";
        cin >> courseCode;
        cout << "Enter Credits: ";
        cin >> credits;
        cout << "Enter Instructor: ";
        cin.ignore(); // Ignore newline left in the buffer
        getline(cin, instructor);
        cout << "Enter Description: ";
        getline(cin, description);
    }

    // Member function to display course details
    void displayDetails() const {
        cout << "Course Name: " << courseName << endl;
        cout << "Course Code: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Description: " << description << endl;
    }
};

int main() {
    Course c1, c2, c3;

    cout << "Enter details for c1:" << endl;
    c1.inputDetails();
    cout << "\nDetails entered for c1:" << endl;
    c1.displayDetails();

    cout << "\nEnter details for c2:" << endl;
    c2.inputDetails();
    cout << "\nDetails entered for c2:" << endl;
    c2.displayDetails();

    cout << "\nEnter details for c3:" << endl;
    c3.inputDetails();
    cout << "\nDetails entered for c3:" << endl;
    c3.displayDetails();

    // Objects will be automatically destroyed when they go out of scope

    return 0;
}
