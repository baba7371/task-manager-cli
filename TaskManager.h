#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include <stack>
#include "Task.h"

class TaskManager
{
private:
    vector<Task> tasks;
    stack<vector<Task>> undoStack;
    stack<vector<Task>> redoStack;
    int nextId;

public:
    TaskManager();

    void addTask(string title, int priority, string deadline);
    void listTasks();
    void deleteTask(int id);
    void updateTaskStatus(int id, string status);
    void searchTasks(string keyword);
    void filterTasks(string priority);
    void sortByPriority();
    void sortByDeadline();
    void load();
    void save();
    void saveState();
    void undo();
    void redo();
    int getPriorityValue(string p);
};

#endif