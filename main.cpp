#include <iostream>
#include <sstream>
#include "TaskManager.h"
#include "CommandParser.h"

using namespace std;

// Show help menu
void showHelp()
{
    cout << "\nAvailable Commands:\n";
    cout << "--------------------------------------\n";
    cout << "add \"Task Name\" priority deadline\n";
    cout << "   Example: add \"DSA Practice\" high 2026-04-30\n\n";

    cout << "add (interactive mode)\n\n";

    cout << "list\n";
    cout << "delete <id>\n";

    cout << "update <id> <status>\n";
    cout << "update (interactive mode)\n";

    cout << "search \"keyword\"\n";
    cout << "filter <priority>\n";

    cout << "sort priority | sort deadline\n\n";

    cout << "undo | redo\n";
    cout << "exit\n";
    cout << "--------------------------------------\n";
}

int main()
{
    TaskManager tm;
    string input;

    cout << "Task Manager CLI \n";
    cout << "Type 'help' to see available commands\n";

    while (true)
    {
        cout << "\n> ";
        getline(cin, input);

        if (input.empty())
            continue;

        // -------- ADD --------
        if (input == "add")
        {
            string title, priorityStr, deadline;

            cout << "Enter title: ";
            getline(cin, title);

            cout << "Enter priority (high/medium/low): ";
            cin >> priorityStr;

            cout << "Enter deadline (YYYY-MM-DD): ";
            cin >> deadline;
            cin.ignore();

            int priority = (priorityStr == "high") ? 1 : (priorityStr == "medium") ? 2
                                                                                   : 3;

            tm.addTask(title, priority, deadline);
        }
        else if (input.find("add ") == 0)
        {
            string title = CommandParser::extractTitle(input);
            string priorityStr = CommandParser::extractPriority(input);
            string deadline = CommandParser::extractDeadline(input);

            if (title.empty())
            {
                cout << "Invalid format! Use: add \"Task Name\" priority deadline\n";
                continue;
            }

            int priority = (priorityStr == "high") ? 1 : (priorityStr == "medium") ? 2
                                                                                   : 3;

            tm.addTask(title, priority, deadline);
        }

        // -------- LIST --------
        else if (input == "list")
        {
            tm.listTasks();
        }

        // -------- DELETE --------
        else if (input.find("delete ") == 0)
        {
            try
            {
                int id = stoi(input.substr(7));
                tm.deleteTask(id);
            }
            catch (...)
            {
                cout << "Invalid ID!\n";
            }
        }

        // -------- UPDATE --------
        else if (input == "update")
        {
            int id;
            string status;

            cout << "Enter task ID: ";
            cin >> id;

            cout << "Enter status (pending/inprogress/completed): ";
            cin >> status;
            cin.ignore();

            tm.updateTaskStatus(id, status);
        }
        else if (input.find("update ") == 0)
        {
            string command, status;
            int id;

            stringstream ss(input);
            ss >> command >> id >> status;

            tm.updateTaskStatus(id, status);
        }

        // -------- SEARCH --------
        else if (input.find("search ") == 0)
        {
            string keyword = CommandParser::extractTitle(input);
            tm.searchTasks(keyword);
        }

        // -------- FILTER --------
        else if (input.find("filter ") == 0)
        {
            string command, priority;
            stringstream ss(input);
            ss >> command >> priority;

            tm.filterTasks(priority);
        }

        // -------- SORT --------
        else if (input.find("sort ") == 0)
        {
            string command, type;
            stringstream ss(input);
            ss >> command >> type;

            if (type == "priority")
            {
                tm.sortByPriority();
            }
            else if (type == "deadline")
            {
                tm.sortByDeadline();
            }
            else
            {
                cout << "Invalid sort type!\n";
            }
        }

        // -------- UNDO / REDO --------
        else if (input == "undo")
        {
            tm.undo();
        }
        else if (input == "redo")
        {
            tm.redo();
        }

        // -------- HELP --------
        else if (input == "help")
        {
            showHelp();
        }

        // -------- EXIT --------
        else if (input == "exit")
        {
            cout << "Exiting Task Manager. Goodbye!\n";
            break;
        }

        // -------- INVALID --------
        else
        {
            cout << "Invalid command! Type 'help' to see available commands.\n";
        }
    }

    return 0;
}