#include "TaskManager.h"
#include "FileHandler.h"
#include<algorithm>
#include <iostream>
#include <iomanip>

TaskManager::TaskManager() {
    tasks = FileHandler::loadTasks();

    nextId = 1;
    for (auto &task : tasks) {
        if (task.id >= nextId) {
            nextId = task.id + 1;
        }
    }
}

void TaskManager::addTask(string title, int priority, string deadline) {
    saveState();
    tasks.push_back(Task(nextId++, title, priority, deadline));
    save();
}

void TaskManager::listTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    // Header
    cout << left << setw(5) << "ID"
         << setw(22) << "Title"
         << setw(12) << "Priority"
         << setw(15) << "Deadline"
         << setw(15) << "Status" << endl;

    cout << string(70, '-') << endl;

    // Rows
    for (auto &task : tasks) {
        string priorityStr = (task.priority == 1) ? "High" :
                             (task.priority == 2) ? "Medium" : "Low";

        cout << left << setw(5) << task.id
             << setw(22) << task.title
             << setw(12) << priorityStr
             << setw(15) << task.deadline
             << setw(15) << task.status << endl;
    }
}

void TaskManager::deleteTask(int id) {
    saveState();
    tasks.erase(remove_if(tasks.begin(), tasks.end(),
        [id](const Task &t) { return t.id == id; }), tasks.end());
    save();
}

void TaskManager::load() {
    tasks = FileHandler::loadTasks();
}

void TaskManager::save() {
    FileHandler::saveTasks(tasks);
}

int getPriorityValue(string p) {
    if (p == "high") return 1;
    if (p == "medium") return 2;
    return 3;
}

void TaskManager::updateTaskStatus(int id, string status) {
    saveState();
    for (auto &task : tasks) {
        if (task.id == id) {

            if (status == "pending") task.status = "Pending";
            else if (status == "inprogress") task.status = "In Progress";
            else if (status == "completed") task.status = "Completed";
            else {
                cout << "Invalid status!" << endl;
                return;
            }

            save();
            cout << "Task updated successfully!" << endl;
            return;
        }
    }

    cout << "Task not found!" << endl;
}

void TaskManager::searchTasks(string keyword) {
    bool found = false;

    for (auto &task : tasks) {
        if (task.title.find(keyword) != string::npos) {
            task.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No matching tasks found!" << endl;
    }
}

void TaskManager::filterTasks(string priority) {
    int p = (priority == "high") ? 1 :
            (priority == "medium") ? 2 : 3;

    bool found = false;

    for (auto &task : tasks) {
        if (task.priority == p) {
            task.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No tasks found for this priority!" << endl;
    }
}

void TaskManager::sortByPriority() {
    sort(tasks.begin(), tasks.end(), [](Task &a, Task &b) {
        return a.priority < b.priority;
    });

    cout << "Sorted by priority!" << endl;
}

void TaskManager::sortByDeadline() {
    sort(tasks.begin(), tasks.end(), [](Task &a, Task &b) {
        return a.deadline < b.deadline;
    });

    cout << "Sorted by deadline!" << endl;
}

void TaskManager::saveState() {
    undoStack.push(tasks);
}

void TaskManager::undo() {
    if (undoStack.empty()) {
        cout << "Nothing to undo!" << endl;
        return;
    }

    redoStack.push(tasks);
    tasks = undoStack.top();
    undoStack.pop();

    save();
    cout << "Undo successful!" << endl;
}

void TaskManager::redo() {
    if (redoStack.empty()) {
        cout << "Nothing to redo!" << endl;
        return;
    }

    undoStack.push(tasks);
    tasks = redoStack.top();
    redoStack.pop();

    save();
    cout << "Redo successful!" << endl;
}