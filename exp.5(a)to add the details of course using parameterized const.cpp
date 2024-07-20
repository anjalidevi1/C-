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
    // Parameterized constructor
    Course(const string& name, int code, int credit, const string& instructorName, const string& desc)
        : courseName(name), courseCode(code), credits(credit), instructor(instructorName), description(desc) {
        cout << "Course object created with details." << endl;
    }

    // Destructor
    ~Course() {
        cout << "Course object destroyed." << endl;
    }

    // Member function to display course details
    void displayDetails() const {
        cout << "Course Name: " << courseName << endl;
        cout << "Course Code: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Description: " << description << endl;
    }

    // Member function to add or update course details
    void addDetails(const string& name, int code, int credit, const string& instructorName, const string& desc) {
        courseName = name;
        courseCode = code;
        credits = credit;
        instructor = instructorName;
        description = desc;
        cout << "Course details added/updated." << endl;
    }
};

int main() {
    // Create courses using the parameterized constructor
    Course c1("Mathematics", 101, 3, "Dr. Smith", "Introduction to Calculus");
    Course c2("Physics", 102, 4, "Prof. Johnson", "Classical Mechanics");
    Course c3("Computer Science", 103, 3, "Dr. Brown", "Data Structures and Algorithms");

    // Display course details
    cout << "\nDetails of c1:" << endl;
    c1.displayDetails();

    cout << "\nDetails of c2:" << endl;
    c2.displayDetails();

    cout << "\nDetails of c3:" << endl;
    c3.displayDetails();

    // Add or update details of c1
    c1.addDetails("Statistics", 104, 3, "Prof. Davis", "Probability and Statistics");

    // Display updated details of c1
    cout << "\nUpdated details of c1:" << endl;
    c1.displayDetails();

    // Objects will be automatically destroyed when they go out of scope

    return 0;
}
