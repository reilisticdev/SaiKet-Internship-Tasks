#include <iostream>
#include <fstream>  // REQUIRED for File I/O
#include <string>
#include <vector>
#include <limits> // For input clearing

using namespace std;

// --- Helper Functions ---
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// --- FILE OPERATIONS ---

// 1. Write Mode (Create New File)
void createDocument() {
    string filename;
    cout << "\n[CREATE NEW DOCUMENT]" << endl;
    cout << "Enter filename (e.g., mynote.txt): ";
    cin >> filename;

    // Add .txt if missing
    if (filename.find(".txt") == string::npos) filename += ".txt";

    ofstream outFile(filename); // 'ofstream' is for WRITING to files

    if (!outFile) {
        cout << "Error: Could not create file!" << endl;
        return;
    }

    cout << "\n--- EDITOR MODE (Type ':SAVE' to finish) ---" << endl;

    string line;
    cin.ignore(); // Clear buffer to catch the first line
    while (true) {
        getline(cin, line);
        if (line == ":SAVE") break; // Exit condition
        outFile << line << endl;    // Write line to file on hard drive
    }

    outFile.close(); // ALWAYS close files to save changes!
    cout << ">> Success! File saved as '" << filename << "'\n" << endl;
}

// 2. Read Mode (Open File)
void openDocument() {
    string filename;
    cout << "\n[OPEN DOCUMENT]" << endl;
    cout << "Enter filename to open: ";
    cin >> filename;

    // Add .txt if missing
    if (filename.find(".txt") == string::npos) filename += ".txt";

    ifstream inFile(filename); // 'ifstream' is for READING files

    if (!inFile) {
        cout << "Error: File not found! (Check your spelling)" << endl;
        return;
    }

    cout << "\n--- READING FILE: " << filename << " ---" << endl;
    cout << "----------------------------------------" << endl;

    string line;
    while (getline(inFile, line)) { // Read line by line until end
        cout << line << endl;
    }

    cout << "----------------------------------------" << endl;
    inFile.close();
    cout << ">> End of file.\n" << endl;
}

// --- MAIN MENU ---

int main() {
    int choice = 0;
    while (choice != 3) {
        cout << "===========================" << endl;
        cout << "   SAIKET TEXT EDITOR v1" << endl;
        cout << "===========================" << endl;
        cout << "1. Create New Document" << endl;
        cout << "2. Open Existing Document" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input." << endl;
            clearInput();
            continue;
        }

        switch (choice) {
        case 1: createDocument(); break;
        case 2: openDocument(); break;
        case 3: cout << "Exiting..." << endl; break;
        default: cout << "Invalid option!" << endl;
        }
    }
    return 0;
}