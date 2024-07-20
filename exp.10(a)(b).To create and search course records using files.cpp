#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Course {
private:
    string Cname;
    int Coursecode;

public:
    Course(string n, int code) {
        Cname = n;
        Coursecode = code;
    }

    void writefun() {
        ofstream obj("d:/a/Course.txt", ios::app); // Open file in append mode with flag app
        if (obj.is_open()) {
            obj << Cname << " " << Coursecode << endl;
            obj.close();
            cout << "Course record has been stored." << endl;
        } else {
            cout << "Unable to open file!" << endl;
        }
    }

    void searchRecord(int code) {
        ifstream file("d:/a/Course.txt");
        if (file.is_open()) {
            string line;
            bool found = false;
            while (getline(file, line)) {
                string cname;
                int coursecode;
                stringstream ss(line);
                ss >> cname >> coursecode;
                if (coursecode == code) {
                    cout << "Course found: " << cname << " (Course Code. " << coursecode << ")" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Course with Course code " << code << " not found." << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file!" << endl;
        }
    }
};

int main() {
    for (int i = 0; i < 3; ++i) {
        string cname;
        int code;

        cout << "\nEnter details for Course " << i + 1 << ":" << endl;
        cout << "Enter course name: ";
        getline(cin >> ws, cname); // Using getline to read the entire line including spaces
        cout << "Enter course code: ";
        cin >> code;
        cin.ignore(); // Ignore newline character left in the buffer

        Course st(cname, code);
        st.writefun();
    }

    cout << "\nSearch Course" << endl;
    int code;
    cout << "Enter course code to search: ";
    cin >> code;

    Course st("", 0); // Temporary object to call search function
    st.searchRecord(code);

    return 0;
}
