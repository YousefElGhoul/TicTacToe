#include "../include/Utils.hpp"

void TicTacToe::initGame(){
    clearBoard();
}

int TicTacToe::checkWin() {
    char win_patterns[8][3] = { { 0 ,1 , 2 }, { 3 ,4 ,5 }, { 6 ,7 ,8 }, { 0 ,3 ,6 }, { 1 ,4 ,7 }, { 2 ,5 ,8 }, { 0 ,4 ,8 }, { 2 ,4 ,6 } };
    for (auto& pattern : win_patterns) {
        if (board[pattern[0]] == board[pattern[1]] && board[pattern[1]] == board[pattern[2]] && board[pattern[0]] != ' ') {
            return GAME_STATE_RESULT;
        }
    }
    for (int i = 0; i < 9; i++) if (board[i] == ' ') return GAME_STATE_ONGOING;
    return GAME_STATE_DRAW;
}

void TicTacToe::clearBoard() {
    for (int i = 0; i < 9; i++)
        board[i] = ' ';
}