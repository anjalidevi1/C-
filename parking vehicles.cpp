#include <iostream>
using namespace std;
int main() {
    int choice;
    char again;

    do {

        cout << "Menu:\n";
        cout << "1. Car park\n";
        cout << "2. Bike park\n";
        cout << "3. Park rikshaw\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {
            case 1:
                cout << "Car park\n";
                break;
            case 2:
                cout << "Bike park\n";
                break;
            case 3:
                cout << "Park rikshaw\n";
                break;
            case 4:
               cout << "Exiting...\n";
                break;
            default:
               cout << "Invalid choice, please try again.\n";
        }


        if (choice != 4) {
            cout << "Do you want to perform another action? (y/n): ";
            cin >> again;
        } else {
            again = 'n';
        }

    } while (again == 'y' || again == 'Y');

    cout << "Goodbye!\n";

    return 0;
}
