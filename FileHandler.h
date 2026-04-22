#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include "Task.h"
using namespace std;

class FileHandler {
public:
    static void saveTasks(const vector<Task>& tasks);
    static vector<Task> loadTasks();
};

#endif