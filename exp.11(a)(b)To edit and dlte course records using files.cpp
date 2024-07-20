#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Course {
private:
    string Cname;
    int Ccode;

public:
    Course(string n, int code) {
        Cname = n;
        Ccode = code;
    }

    void writefun() {
        ofstream file("d:/n/Course.txt", ios::app); // Open file in append mode with flag app
        if (file.is_open()) {
            file << Cname << " " << Ccode << endl;
            file.close();
            cout << "Course record has been stored: " << Cname << " (Course Code. " << Ccode << ")" << endl;
        } else {
            cout << "Unable to open file!" << endl;
        }
    }

    void searchRecord(int code) {
        ifstream file("d:/n/Course.txt");
        if (file.is_open()) {
            string line;
            bool found = false;
            while (getline(file, line)) {
                string cname;
                int ccode;
                stringstream ss(line);
                ss >> cname >> ccode;
                if (ccode == code) {
                    cout << "Course found: " << cname << " (Course Code. " << ccode << ")" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Course with course code " << code << " not found." << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file!" << endl;
        }
    }

    void deleteRecord(int code) {
        ifstream file("d:/n/Course.txt");
        ofstream temp("d:/n/temp.txt");
        if (file.is_open() && temp.is_open()) {
            string line;
            bool found = false;
            while (getline(file, line)) {
                string cname;
                int ccode;
                stringstream ss(line);
                ss >> cname >> ccode;
                if (ccode == code) {
                    found = true;
                    cout << "Deleted Course: " << cname << " (Course Code. " << ccode << ")" << endl;
                } else {
                    temp << line << endl;
                }
            }
            file.close();
            temp.close();

            if (found) {
                remove("d:/n/Course.txt");
                rename("d:/n/temp.txt", "d:/n/Course.txt");
                cout << "Record deleted successfully." << endl;
            } else {
                remove("d:/n/temp.txt");
                cout << "Course with course code " << code << " not found." << endl;
            }
        } else {
            cout << "Unable to open file!" << endl;
        }
    }
};

int main() {
    Course courses[] = {
        Course("AI", 401),
        Course("CS", 402),
        Course("COA", 403)
    };

    for (int i = 0; i < 3; ++i) {
        courses[i].writefun();
    }

    cout << "\nSearch and Update Course" << endl;
    int code;
    cout << "Enter course code to search: ";
    cin >> code;

    Course st("", 0); // Temporary object to call search function
    st.searchRecord(code);
    st.deleteRecord(code);

    return 0;
}
