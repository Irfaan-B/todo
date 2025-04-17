#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    int id;
    string name;
    bool completed;
};

vector<Task> tasks;
int nextId = 1;

void createTask(const string& name);
void listTasks();
void updateTask(int id, const string& newName);
void deleteTask(int id);
void completeTask(int id);

int main() {
    return 0;
}

void createTask(const string& name) {
    tasks.push_back({nextId++, name, false});
    cout << "Task added!\n";
}

void listTasks() {
    cout << "Current tasks:\n";
    for (const auto& task : tasks){
        cout << task.id << ". " << task.name << (task.completed ? " [Done]" : "") << endl;
    }
}

void updateTask(int id, const string& newName) {
    for (auto& task : tasks) {
        if (task.id == id) {
            task.name = newName;
            cout << "Task updated.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

void deleteTask(int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            cout << "Tasks deleted!\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

void completeTask(int id){
    for (auto& task : tasks) {
        if (task.id == id) {
            task.completed = true;
            cout << "Task completed!\n";
            return;
        }
    }
    cout << "Task not found\n";
}