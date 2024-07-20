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
        ofstream obj("d:/a/student.txt", ios::app); // Open file in append mode with flag app
        if (obj.is_open()) {
            obj << name << " " << rollNumber << endl;
            obj.close();
            cout << "Student record has been stored." << endl;
        } else {
            cout << "Unable to open file!" << endl;
        }
    }

    void searchRecord(int roll) {
        ifstream file("d:/a/student.txt");
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

    cout << "\nSearch Student" << endl;
    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;

    Student st("", 0); // Temporary object to call search function
    st.searchRecord(roll);

    return 0;
}
