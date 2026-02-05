#include <iostream>
#include <vector>
#include <string>
#include <limits> // For clearing input buffer

using namespace std;

// 1. Define the structure of a Task
struct Task {
    string description;
    bool isCompleted;
};

// 2. Global List of Tasks
vector<Task> taskList;

// 3. Helper Function to handle input glitches
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// --- FEATURE FUNCTIONS ---

void addTask() {
    cout << "\n--- Add New Task ---" << endl;
    cout << "Enter task description: ";

    Task newTask;
    cin.ignore(); // Clear buffer before getline
    getline(cin, newTask.description);
    newTask.isCompleted = false;

    taskList.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void viewTasks() {
    cout << "\n--- Your To-Do List ---" << endl;
    if (taskList.empty()) {
        cout << "List is empty." << endl;
        return;
    }

    for (int i = 0; i < taskList.size(); i++) {
        string status = taskList[i].isCompleted ? "[DONE]" : "[PENDING]";
        cout << i + 1 << ". " << status << " " << taskList[i].description << endl;
    }
}

void markCompleted() {
    viewTasks();
    if (taskList.empty()) return;

    cout << "\nEnter task number to mark as done: ";
    int index;
    cin >> index;

    if (cin.fail() || index < 1 || index > taskList.size()) {
        cout << "Invalid task number!" << endl;
        clearInput();
    }
    else {
        taskList[index - 1].isCompleted = true;
        cout << "Great job! Task marked as completed." << endl;
    }
}

void removeTask() {
    viewTasks();
    if (taskList.empty()) return;

    cout << "\nEnter task number to remove: ";
    int index;
    cin >> index;

    if (cin.fail() || index < 1 || index > taskList.size()) {
        cout << "Invalid task number!" << endl;
        clearInput();
    }
    else {
        cout << "Removed task: " << taskList[index - 1].description << endl;
        taskList.erase(taskList.begin() + (index - 1));
    }
}

// --- MAIN MENU ---

int main() {
    int choice = 0;

    while (choice != 5) {
        cout << "\n=========================" << endl;
        cout << "   TO-DO LIST MANAGER" << endl;
        cout << "=========================" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Please enter a number." << endl;
            clearInput();
            continue;
        }

        switch (choice) {
        case 1: addTask(); break;
        case 2: viewTasks(); break;
        case 3: markCompleted(); break;
        case 4: removeTask(); break;
        case 5: cout << "Exiting... Have a productive day!" << endl; break;
        default: cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}