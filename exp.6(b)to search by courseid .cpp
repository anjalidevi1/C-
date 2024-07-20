#include <iostream>
#include <string>
#include <vector>

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

    // Member function to get course code
    int getCourseCode() const {
        return courseCode;
    }

    // Member function to search for a course by course ID
    static void searchByCourseId(const vector<Course>& courses, int courseId) {
        for (const auto& course : courses) {
            if (course.getCourseCode() == courseId) {
                course.displayDetails();
                return;
            }
        }
        cout << "Course with ID " << courseId << " not found." << endl;
    }
};

int main() {
    // Create courses using the parameterized constructor
    Course c1("Mathematics", 101, 3, "Dr. Smith", "Introduction to Calculus");
    Course c2("Physics", 102, 4, "Prof. Johnson", "Classical Mechanics");
    Course c3("Computer Science", 103, 3, "Dr. Brown", "Data Structures and Algorithms");

    // Store courses in a vector
    vector<Course> courses = {c1, c2, c3};

    // Display course details
    cout << "\nDetails of all courses:" << endl;
    for (const auto& course : courses) {
        course.displayDetails();
        cout << endl;
    }

    // Search for a course by course ID
    int searchId;
    cout << "\nEnter course ID to search: ";
    cin >> searchId;
    Course::searchByCourseId(courses, searchId);

    // Objects will be automatically destroyed when they go out of scope

    return 0;
}
