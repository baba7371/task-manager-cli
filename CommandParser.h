#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <string>
using namespace std;

class CommandParser {
public:
    static string extractTitle(const string& input);
    static string extractPriority(const string& input);
    static string extractDeadline(const string& input);
};

#endif