#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <iostream>

class Display {
public:
    static void initDisplay();
    static void refresh(std::string str);
    static void printBoard();
    static void printScores();

private:
    static void clear();
    static void print(std::string str);
};

#endif