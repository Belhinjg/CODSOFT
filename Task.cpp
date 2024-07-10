#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }
};

// Function prototypes
void displayMenu();
void addTask(vector<Task> &tasks);
void viewTasks(const vector<Task> &tasks);
void markTaskCompleted(vector<Task> &tasks);
void removeTask(vector<Task> &tasks);

int main() {
    vector<Task> tasks; // Vector to store tasks

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\n===== To-Do List Manager =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void addTask(vector<Task> &tasks) {
    string description;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, description);
    tasks.push_back(Task(description));
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available. Your to-do list is empty." << endl;
    } else {
        cout << "\n===== Tasks in To-Do List =====" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
                cout << "[Completed] ";
            } else {
                cout << "[Pending] ";
            }
            cout << tasks[i].description << endl;
        }
    }
}

void markTaskCompleted(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to mark as completed." << endl;
        return;
    }

    viewTasks(tasks); // Display current tasks
    int index;
    cout << "Enter the task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > static_cast<int>(tasks.size())) {
        cout << "Invalid task number. Please enter a valid task number." << endl;
    } else {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    }
}

void removeTask(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to remove." << endl;
        return;
    }

    viewTasks(tasks); // Display current tasks
    int index;
    cout << "Enter the task number to remove: ";
    cin >> index;

    if (index < 1 || index > static_cast<int>(tasks.size())) {
        cout << "Invalid task number. Please enter a valid task number." << endl;
    } else {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully!" << endl;
    }
}
