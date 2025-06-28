#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "utils.hpp"
#include "ASCIIArt.hpp"
#include <iostream>
#include <vector>
#include <format>

#define MAX_DISPLAY_LINES               30

#define START_MENU                      0
#define START_MENU_START_SELECTED       1
#define START_MENU_EXIT_SELECTED        2
#define RESTART_MENU                    3
#define RESTART_MENU_RESTART_SELECTED   4
#define RESTART_MENU_EXIT_SELECTED      5

#define NAME_INPUT_1                    6
#define NAME_INPUT_2                    7


class Display {
public:
    static void initDisplay();
    static void refresh();
    static void showMenu(int menuState);
    static void showScores();
    static void showNameInput(int menuState);
    static void showBoard();

private:
    static void print(std::string str);
    static std::vector<std::string> arr;
    static void clear();
    static void addBoard();
    static void addScores();
    static void addLine(std::vector<std::string> &arr, const std::string &newLine);
    static void addLogo();
    static void addButton(std::string buttonText);
    static void addSelectedButton(std::string buttonText);
};

#endif