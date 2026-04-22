#include "CommandParser.h"
#include <sstream>

// Extract text inside quotes
string CommandParser::extractTitle(const string& input) {
    size_t start = input.find('"');
    size_t end = input.find('"', start + 1);

    if (start == string::npos || end == string::npos)
        return "";

    return input.substr(start + 1, end - start - 1);
}

// Extract priority (word after closing quote)
string CommandParser::extractPriority(const string& input) {
    size_t endQuote = input.find('"', input.find('"') + 1);
    string remaining = input.substr(endQuote + 1);

    stringstream ss(remaining);
    string priority;
    ss >> priority;

    return priority;
}

// Extract deadline (last word)
string CommandParser::extractDeadline(const string& input) {
    stringstream ss(input);
    string word, last;

    while (ss >> word) {
        last = word;
    }

    return last;
}