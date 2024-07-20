#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;

public:
    Student(string n, int roll) {
        name = n;
        rollNumber = roll;
    }

    void writefun() {
        ofstream file("d:/n/student.txt", ios::app); // Open file in append mode with flag app
        if (file.is_open()) {
            file << name << " " << rollNumber << endl;
            file.close();
            cout << "Student record has been stored." << endl;
        } else {
            cout << "Unable to open file!" << endl;
        }
    }

    void searchRecord(int roll) {
        ifstream file("d:/n/student.txt");
        if (file.is_open()) {
            string line;
            bool found = false;
            while (getline(file, line)) {
                string name;
                int rollNumber;
                stringstream ss(line);
                ss >> name >> rollNumber;
                if (rollNumber == roll) {
                    cout << "Student found: " << name << " (Roll No. " << rollNumber << ")" << endl;

                    // Editing the record
                    ofstream ob("d:/n/student.txt");
                    name = "Sumit";
                    rollNumber = 101;
                    ob << name << "  " << rollNumber;
                    cout << "Record Updated" << endl;

                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student with roll number " << roll << " not found." << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file!" << endl;
        }
    }

    void deleteRecord(int roll) {
        ifstream file("d:/n/student.txt");
        ofstream temp("d:/n/temp.txt");
        if (file.is_open() && temp.is_open()) {
            string line;
            bool found = false;
            while (getline(file, line)) {
                string name;
                int rollNumber;
                stringstream ss(line);
                ss >> name >> rollNumber;
                if (rollNumber == roll) {
                    found = true;
                } else {
                    temp << line << endl;
                }
            }
            file.close();
            temp.close();

            if (found) {
                remove("d:/n/student.txt");
                rename("d:/n/temp.txt", "e:/n/student.txt");
                cout << "Record deleted successfully." << endl;
            } else {
                remove("d:/n/temp.txt");
                cout << "Student with roll number " << roll << " not found." << endl;
            }
        } else {
            cout << "Unable to open file!" << endl;
        }
    }
};

int main() {
    for (int i = 0; i < 3; ++i) {
        string name;
        int roll;

        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> roll;
        cin.ignore(); // ignore the newline character left in the buffer

        Student st(name, roll);
        st.writefun();
    }

    cout << "\nSearch and Delete Student Record" << endl;
    int roll;
    cout << "Enter roll number to search and delete: ";
    cin >> roll;

    Student st("", 0); // Temporary object to call search and delete functions
    st.searchRecord(roll);
    st.deleteRecord(roll);

    return 0;
}
