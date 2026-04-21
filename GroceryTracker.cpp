#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

GroceryTracker::GroceryTracker(const string& inputFile, const string& backupFile) {
    inputFileName = inputFile;
    backupFileName = backupFile;
}

void GroceryTracker::LoadDataFromFile() {
    ifstream inFile(inputFileName);
    string item;

    if (!inFile.is_open()) {
        cout << "Error: Could not open input file." << endl;
        return;
    }

    while (inFile >> item) {
        itemFrequency[item]++;
    }

    inFile.close();
}

void GroceryTracker::CreateBackupFile() const {
    ofstream outFile(backupFileName);

    if (!outFile.is_open()) {
        cout << "Error: Could not create backup file." << endl;
        return;
    }

    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << endl;
    }

    outFile.close();
}

int GroceryTracker::GetItemFrequency(const string& item) const {
    auto it = itemFrequency.find(item);

    if (it != itemFrequency.end()) {
        return it->second;
    }

    return 0;
}

void GroceryTracker::PrintAllFrequencies() const {
    cout << "\nAll Item Frequencies\n";
    cout << "-------------------------\n";

    for (const auto& pair : itemFrequency) {
        cout << left << setw(15) << pair.first << pair.second << endl;
    }
}

void GroceryTracker::PrintHistogram() const {
    cout << "\nHistogram\n";
    cout << "-------------------------\n";

    for (const auto& pair : itemFrequency) {
        cout << left << setw(15) << pair.first;

        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }

        cout << endl;
    }
}