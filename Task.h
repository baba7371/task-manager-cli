#ifndef TASK_H
#define TASK_H

#include <string>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

class Task {
public:
    int id;
    string title;
    int priority;
    string deadline;
    string status;

    Task();
    Task(int id, string title, int priority, string deadline);

    json toJson() const;
    static Task fromJson(json j);

    void display();
};

#endif