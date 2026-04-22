#include "Task.h"
#include <iostream>

// JSON library
#include "json.hpp"
using json = nlohmann::json;

Task::Task() {}

Task::Task(int id, string title, int priority, string deadline) {
    this->id = id;
    this->title = title;
    this->priority = priority;
    this->deadline = deadline;
    this->status = "Pending";
}

// 🔥 Convert Task → JSON
json Task::toJson() const {
    return {
        {"id", id},
        {"title", title},
        {"priority", priority},
        {"deadline", deadline},
        {"status", status}
    };
}

// 🔥 Convert JSON → Task
Task Task::fromJson(json j) {
    Task t;
    t.id = j["id"];
    t.title = j["title"];
    t.priority = j["priority"];
    t.deadline = j["deadline"];
    t.status = j["status"];
    return t;
}

static string getPriorityString(int p) {
    if (p == 1) return "High";
    if (p == 2) return "Medium";
    return "Low";
}
// 🎨 Display (you can later add colors here)
void Task::display() {
    cout << "[" << id << "] " << title 
         << " | Priority: " << getPriorityString(priority) 
         << " | Deadline: " << deadline
         << " | Status: " << status << endl;
}