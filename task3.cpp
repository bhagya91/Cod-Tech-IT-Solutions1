#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back({description, false});
        cout << "Task added successfully!" << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].description << " - " << (tasks[i].completed ? "Completed" : "Pending") << endl;
            }
        }
    }

    void markTaskCompleted(size_t taskNumber) {
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(size_t taskNumber) {
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task removed successfully." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;
    string taskDescription;
    size_t taskNumber;

    while (true) {
        cout << "\n===== ToDo List Manager =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the task: ";
                cin.ignore();
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                cout << "Enter the task number to mark as completed: ";
                cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber);
                break;
            case 4:
                cout << "Enter the task number to remove: ";
                cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
