#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For the table
#include <limits>  // For input cleaning

using namespace std;

// --- DATA STRUCTURE ---
struct Contact {
    int id;
    string name;
    string phone;
    string email;
};

// Global Storage
vector<Contact> addressBook;
int nextId = 1; // Unique ID for every contact

// --- HELPER FUNCTIONS ---
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Case-insensitive search helper
bool stringContains(string mainStr, string searchStr) {
    // This is a simple substring check
    return mainStr.find(searchStr) != string::npos;
}

// --- CORE FEATURES ---

// 1. Add Contact
void addContact() {
    Contact newContact;
    newContact.id = nextId++;

    cout << "\n--- ADD NEW CONTACT ---" << endl;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newContact.name);

    cout << "Enter Phone Number: ";
    getline(cin, newContact.phone);

    cout << "Enter Email: ";
    getline(cin, newContact.email);

    addressBook.push_back(newContact);
    cout << ">> Success! Contact saved." << endl;
}

// 2. View All Contacts
void viewContacts() {
    cout << "\n===================================================================" << endl;
    cout << "                        ADDRESS BOOK (" << addressBook.size() << " contacts)" << endl;
    cout << "===================================================================" << endl;

    // Table Headers
    cout << left << setw(5) << "ID"
        << setw(25) << "Name"
        << setw(15) << "Phone"
        << setw(25) << "Email" << endl;
    cout << "-------------------------------------------------------------------" << endl;

    if (addressBook.empty()) {
        cout << "  (No contacts found)" << endl;
    }
    else {
        for (const auto& c : addressBook) {
            cout << left << setw(5) << c.id
                << setw(25) << c.name
                << setw(15) << c.phone
                << setw(25) << c.email << endl;
        }
    }
    cout << "===================================================================\n" << endl;
}

// 3. Search Contacts (Smart Search)
void searchContact() {
    if (addressBook.empty()) {
        cout << "\nAddress book is empty." << endl;
        return;
    }

    cout << "\n--- SEARCH CONTACT ---" << endl;
    cout << "Enter name to search (e.g., 'John'): ";
    string query;
    cin.ignore();
    getline(cin, query);

    cout << "\nSearch Results:" << endl;
    bool found = false;

    cout << left << setw(5) << "ID" << setw(25) << "Name" << setw(15) << "Phone" << endl;
    cout << "---------------------------------------------" << endl;

    for (const auto& c : addressBook) {
        // Find query inside the name
        if (stringContains(c.name, query)) {
            cout << left << setw(5) << c.id
                << setw(25) << c.name
                << setw(15) << c.phone << endl;
            found = true;
        }
    }

    if (!found) cout << "  No matching contacts found." << endl;
    cout << "---------------------------------------------\n" << endl;
}

// 4. Edit Contact
void editContact() {
    viewContacts(); // Show list first
    if (addressBook.empty()) return;

    cout << "Enter ID of contact to edit: ";
    int targetId;
    cin >> targetId;

    for (auto& c : addressBook) {
        if (c.id == targetId) {
            cout << "\nEditing '" << c.name << "'..." << endl;
            cout << "1. Edit Name\n2. Edit Phone\n3. Edit Email" << endl;
            cout << "Choice: ";
            int choice;
            cin >> choice;
            cin.ignore(); // Clear buffer for getline

            if (choice == 1) {
                cout << "New Name: ";
                getline(cin, c.name);
            }
            else if (choice == 2) {
                cout << "New Phone: ";
                getline(cin, c.phone);
            }
            else if (choice == 3) {
                cout << "New Email: ";
                getline(cin, c.email);
            }
            cout << ">> Contact updated successfully!" << endl;
            return;
        }
    }
    cout << "Error: ID not found." << endl;
}

// 5. Delete Contact
void deleteContact() {
    viewContacts();
    if (addressBook.empty()) return;

    cout << "Enter ID of contact to delete: ";
    int targetId;
    cin >> targetId;

    for (auto it = addressBook.begin(); it != addressBook.end(); ++it) {
        if (it->id == targetId) {
            cout << ">> Deleted contact: " << it->name << endl;
            addressBook.erase(it);
            return;
        }
    }
    cout << "Error: ID not found." << endl;
}

// --- MAIN MENU ---
int main() {
    int choice = 0;
    while (choice != 6) {
        cout << "\n=== ULTIMATE ADDRESS BOOK ===" << endl;
        cout << "1. Add New Contact" << endl;
        cout << "2. View All Contacts" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Edit Contact" << endl;
        cout << "5. Delete Contact" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input." << endl;
            clearInput();
            continue;
        }

        switch (choice) {
        case 1: addContact(); break;
        case 2: viewContacts(); break;
        case 3: searchContact(); break;
        case 4: editContact(); break;
        case 5: deleteContact(); break;
        case 6: cout << "Exiting..." << endl; break;
        default: cout << "Invalid option!" << endl;
        }
    }
    return 0;
}