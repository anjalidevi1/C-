#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// Student class with name and roll number
class Student {
private:
    std::string name;
    int rollNumber;

public:
    // Constructor
    Student(std::string n, int rn) : name(n), rollNumber(rn) {}

    // Getters
    std::string getName() const { return name; }
    int getRollNumber() const { return rollNumber; }

    // Setters
    void setName(const std::string& n) { name = n; }
    void setRollNumber(int rn) { rollNumber = rn; }
};

// Course class with a vector of students
class Course {
private:
    std::vector<Student> students;

public:
    // Add a student to the course
    void addStudent(Student s) { students.push_back(s); }

    // Function to search for a student by name or roll number
    Student search(const std::string& query) const {
        for (const auto& student : students) {
            if (student.getName() == query || std::to_string(student.getRollNumber()) == query) {
                return student;
            }
        }
        throw std::runtime_error("Student not found!");
    }

    // Function to update student information
    void updateStudent(const Student& oldStudent, const std::string& newName, int newRollNumber) {
        for (auto& student : students) {
            if (student.getName() == oldStudent.getName() && student.getRollNumber() == oldStudent.getRollNumber()) {
                student.setName(newName);
                student.setRollNumber(newRollNumber);
                return;
            }
        }
        throw std::runtime_error("Student not found!");
    }
};

// Function to input student data from user
Student inputStudent() {
    std::string name;
    int rollNumber;
    std::cout << "Enter student name: ";
    std::cin >> name;
    std::cout << "Enter student roll number: ";
    std::cin >> rollNumber;
    return Student(name, rollNumber);
}

int main() {
    Course course;
    bool exitProgram = false;

    while (!exitProgram) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Search Student by Name or Roll Number" << std::endl;
        std::cout << "3. Update Student Information" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Student newStudent = inputStudent();
                course.addStudent(newStudent);
                std::cout << "Student added successfully!" << std::endl;
                break;
            }
            case 2: {
                std::string query;
                std::cout << "Enter the name or roll number of the student you want to search: ";
                std::cin >> query;
                try {
                    Student foundStudent = course.search(query);
                    std::cout << "Found student by ";
                    if (isdigit(query[0])) {
                        std::cout << "roll number: ";
                    } else {
                        std::cout << "name: ";
                    }
                    std::cout << foundStudent.getName() << ", Roll Number: " << foundStudent.getRollNumber() << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 3: {
                try {
                    std::string oldName, newName;
                    int oldRollNumber, newRollNumber;
                    std::cout << "Enter the name of the student you want to update: ";
                    std::cin >> oldName;
                    std::cout << "Enter the old roll number of the student: ";
                    std::cin >> oldRollNumber;
                    Student oldStudent = course.search(oldName);
                    std::cout << "Enter the new name for the student: ";
                    std::cin >> newName;
                    std::cout << "Enter the new roll number for the student: ";
                    std::cin >> newRollNumber;
                    course.updateStudent(oldStudent, newName, newRollNumber);
                    std::cout << "Student information updated successfully!" << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                exitProgram = true;
                std::cout << "Exiting program..." << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice! Please enter a number between 1 and 4." << std::endl;
        }
    }

    return 0;
}
