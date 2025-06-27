#include "../include/Utils.hpp"

char board[9] = {};
char arrow;
int selector, vs_state = 1, player = 1, counter = 0;
std::string lineInput;

PlayerData *player1 = new PlayerData("", 0);
PlayerData *player2 = new PlayerData("", 0);
PlayerData *empty = new PlayerData("", 0);

PlayerData High_Scores[HIGH_SCORE_FILE_ARRAY_SIZE] = {*empty, *empty, *empty, *empty, *empty};

int isEven(int x){return x % 2 == 0 ? 2 : 1;}
std::string getCurrentPlayersName(int player){return isEven(player) == 1 ? player1->getName() : player2->getName();}

void initProgram(){
    Scores::checkFile();
    Scores::readHighScores();
    Display::initDisplay();
    TicTacToe::initGame();
    Menus::select(START);
}

void exitProgram(){
    Scores::saveHighScores();
    exit(0);
}