#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

void DisplayMenu() {
    cout << "\n=====================================\n";
    cout << "         Corner Grocer Menu\n";
    cout << "=====================================\n";
    cout << "1. Search item frequency\n";
    cout << "2. Print all frequencies\n";
    cout << "3. Print histogram\n";
    cout << "4. Exit\n";
    cout << "=====================================\n";
    cout << "Enter your choice: ";
}

int main() {
    GroceryTracker tracker("C:\\Users\\Administrator\\source\\repos\\CS210\\CornerGrocer\\CornerGrocer\\x64\\Debug\\CS210_Project_Three_Input_File.txt", "frequency.dat");

    tracker.LoadDataFromFile();
    tracker.CreateBackupFile();

    int choice = 0;

    do {
        DisplayMenu();

        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number from 1 to 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1: {
            string item;
            cout << "Enter item name: ";
            cin >> item;

            cout << item << " was purchased "
                << tracker.GetItemFrequency(item)
                << " time(s)." << endl;
            break;
        }
        case 2:
            tracker.PrintAllFrequencies();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Please choose 1 to 4 only." << endl;
        }

    } while (choice != 4);

    return 0;
}