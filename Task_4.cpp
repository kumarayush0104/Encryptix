
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayTasks(const vector<Task>& tasks) {
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            cout << " (completed)";
        }
        cout << endl;
    }
}

void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter task description: ";
    getline(cin, description);
    tasks.push_back({description, false});
}

void completeTask(vector<Task>& tasks) {
    int taskNumber;
    cout << "Enter the number of the task to mark as completed: ";
    cin >> taskNumber;
    tasks[taskNumber - 1].completed = true;
}

void removeTask(vector<Task>& tasks) {
    int taskNumber;
    cout << "Enter the number of the task to remove: ";
    cin >> taskNumber;
    tasks.erase(tasks.begin() + taskNumber - 1);
}

void saveTasksToFile(const vector<Task>& tasks, const string& filename) {
    ofstream outFile(filename);
    for (const Task& task : tasks) {
        outFile << task.description << endl;
        outFile << task.completed << endl;
    }
    outFile.close();
}

int main() {
    vector<Task> tasks;
    string filename = "tasks.txt";
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    int option;
    while (true) {
        cout << name+"'s To-Do List !" << endl;
        cout << "1. Display To-Do List" << endl;
        cout << "2. Add New To-Do Item" << endl;
        cout << "3. Mark To-Do Item Completed" << endl;
        cout << "4. Remove To-Do Item" << endl;
        cout << "5. Save To-Do List" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;
      cout<<"\n \n";
        cin.ignore();

        switch (option) {
            case 1:
                displayTasks(tasks);
                break;
            case 2:
                addTask(tasks);
                break;
            case 3:
                completeTask(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                saveTasksToFile(tasks, filename);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
