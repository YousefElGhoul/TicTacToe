#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <string>

class Display {
public:
    static void initDisplay();
    static void refresh(const std::string& str);
    static void printBoard();
    static void printScores();

private:
    static void clear();
    static void print(const std::string& str);
};

#endif