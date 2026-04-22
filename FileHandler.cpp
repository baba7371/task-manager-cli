#include "FileHandler.h"
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

void FileHandler::saveTasks(const vector<Task> &tasks)
{
    json j;

    for (const auto &task : tasks)
    {
        j.push_back(task.toJson());
    }

    ofstream file("tasks.json");
    file << j.dump(4); // formatted JSON
}

vector<Task> FileHandler::loadTasks()
{
    vector<Task> tasks;
    ofstream createFile("tasks.json", ios::app);
    createFile.close();
    ifstream file("tasks.json");

    // 🛑 If file doesn't exist or is empty → return empty list
    if (!file || file.peek() == EOF)
    {
        return tasks;
    }

    json j;
    file >> j;

    for (auto &item : j)
    {
        tasks.push_back(Task::fromJson(item));
    }

    return tasks;
}