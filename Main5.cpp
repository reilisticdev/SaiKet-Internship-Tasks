#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // REQUIRED for the beautiful table
#include <limits>

using namespace std;

// --- DATA STRUCTURE ---
struct Item {
    int id;
    string name;
    int quantity;
    double price;
};

// Global Storage
vector<Item> inventory;
int nextId = 101; // Auto-incrementing IDs starting at 101

// --- HELPER FUNCTIONS ---
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// --- CORE FEATURES ---

// 1. Add Item
void addItem() {
    Item newItem;
    newItem.id = nextId++;

    cout << "\n--- ADD NEW ITEM ---" << endl;
    cout << "Enter Item Name (e.g., Gaming Mouse): ";
    cin.ignore();
    getline(cin, newItem.name);

    cout << "Enter Quantity: ";
    cin >> newItem.quantity;

    cout << "Enter Price per Unit: $";
    cin >> newItem.price;

    // Validation
    if (cin.fail() || newItem.quantity < 0 || newItem.price < 0) {
        cout << "Error: Invalid number! Item not added." << endl;
        clearInput();
        return;
    }

    inventory.push_back(newItem);
    cout << ">> Success! Item '" << newItem.name << "' added with ID: " << newItem.id << endl;
}

// 2. View Inventory (The "Amazing" Table)
void viewInventory() {
    cout << "\n=======================================================" << endl;
    cout << "                  CURRENT INVENTORY                    " << endl;
    cout << "=======================================================" << endl;

    // Table Headers
    cout << left << setw(8) << "ID"
        << setw(20) << "Name"
        << setw(10) << "Qty"
        << setw(10) << "Price($)"
        << setw(10) << "Total($)" << endl;
    cout << "-------------------------------------------------------" << endl;

    if (inventory.empty()) {
        cout << "  (Inventory is empty)" << endl;
    }
    else {
        double grandTotal = 0;
        for (const auto& item : inventory) {
            double totalValue = item.quantity * item.price;
            grandTotal += totalValue;

            cout << left << setw(8) << item.id
                << setw(20) << item.name
                << setw(10) << item.quantity
                << fixed << setprecision(2) << setw(10) << item.price
                << setw(10) << totalValue << endl;
        }
        cout << "-------------------------------------------------------" << endl;
        cout << right << setw(48) << "STOCK VALUE: $" << grandTotal << endl;
    }
    cout << "=======================================================\n" << endl;
}

// 3. Update Item
void updateItem() {
    viewInventory();
    if (inventory.empty()) return;

    cout << "Enter ID of item to update: ";
    int targetId;
    cin >> targetId;

    bool found = false;
    for (auto& item : inventory) {
        if (item.id == targetId) {
            found = true;
            cout << "\nUpdating '" << item.name << "'..." << endl;
            cout << "1. Update Quantity" << endl;
            cout << "2. Update Price" << endl;
            cout << "Choice: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                cout << "Enter new Quantity: ";
                cin >> item.quantity;
            }
            else if (choice == 2) {
                cout << "Enter new Price: $";
                cin >> item.price;
            }
            else {
                cout << "Invalid choice." << endl;
            }
            cout << ">> Item updated successfully!" << endl;
            break;
        }
    }

    if (!found) cout << "Error: ID not found!" << endl;
}

// 4. Remove Item
void removeItem() {
    viewInventory();
    if (inventory.empty()) return;

    cout << "Enter ID of item to remove: ";
    int targetId;
    cin >> targetId;

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == targetId) {
            cout << ">> Removed item: " << it->name << endl;
            inventory.erase(it);
            return;
        }
    }
    cout << "Error: ID not found!" << endl;
}

// --- MAIN MENU ---
int main() {
    int choice = 0;
    while (choice != 5) {
        cout << "\n=== SAIKET INVENTORY SYSTEM ===" << endl;
        cout << "1. Add New Item" << endl;
        cout << "2. View Inventory Report" << endl;
        cout << "3. Update Item Details" << endl;
        cout << "4. Remove Item" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Please enter a number." << endl;
            clearInput();
            continue;
        }

        switch (choice) {
        case 1: addItem(); break;
        case 2: viewInventory(); break;
        case 3: updateItem(); break;
        case 4: removeItem(); break;
        case 5: cout << "Exiting system..." << endl; break;
        default: cout << "Invalid option!" << endl;
        }
    }
    return 0;
}