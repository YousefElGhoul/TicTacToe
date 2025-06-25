#include "../include/Display.hpp"
#include "../include/Scores.hpp"
#include "../include/TicTacToe.hpp"
#include "../include/Menus.hpp"
#include "../include/utils.hpp"

void initProgram() {
    Scores::checkFile();
    Scores::readHighScores();
    Display::initDisplay();
    TicTacToe::initGame();
    Menus::select(0); // START
}

void exitProgram() {
    Scores::saveHighScores();
    exit(0);
}

int main() {
    initProgram();
    system("pause");
    exitProgram();
}
