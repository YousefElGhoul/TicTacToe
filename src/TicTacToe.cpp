#include "../include/Utils.hpp"

void TicTacToe::initGame(){
    clearBoard();
}
int TicTacToe::checkWin(){
    if (board[0] == board[1] && board[1] == board[2] && board[2] == 'X')
        return GAME_STATE_RESULT;
    else if (board[0] == board[1] && board[1] == board[2] && board[2] == 'O')
        return GAME_STATE_RESULT;
    else if (board[3] == board[4] && board[4] == board[5] && board[5] == 'X')
        return GAME_STATE_RESULT;
    else if (board[3] == board[4] && board[4] == board[5] && board[5] == 'O')
        return GAME_STATE_RESULT;
    else if (board[6] == board[7] && board[7] == board[8] && board[8] == 'X')
        return GAME_STATE_RESULT;
    else if (board[6] == board[7] && board[7] == board[8] && board[8] == 'O')
        return GAME_STATE_RESULT;
    else if (board[0] == board[3] && board[3] == board[6] && board[6] == 'X')
        return GAME_STATE_RESULT;
    else if (board[0] == board[3] && board[3] == board[6] && board[6] == 'O')
        return GAME_STATE_RESULT;
    else if (board[1] == board[4] && board[4] == board[7] && board[7] == 'X')
        return GAME_STATE_RESULT;
    else if (board[1] == board[4] && board[4] == board[7] && board[7] == 'O')
        return GAME_STATE_RESULT;
    else if (board[2] == board[5] && board[5] == board[8] && board[8] == 'X')
        return GAME_STATE_RESULT;
    else if (board[2] == board[5] && board[5] == board[8] && board[8] == 'O')
        return GAME_STATE_RESULT;
    else if (board[0] == board[4] && board[4] == board[8] && board[8] == 'X')
        return GAME_STATE_RESULT;
    else if (board[0] == board[4] && board[4] == board[8] && board[8] == 'O')
        return GAME_STATE_RESULT;
    else if (board[2] == board[4] && board[4] == board[6] && board[6] == 'X')
        return GAME_STATE_RESULT;
    else if (board[2] == board[4] && board[4] == board[6] && board[6] == 'O')
        return GAME_STATE_RESULT;
    else if (board[0] != ' ' && board[1] != ' ' && board[2] != ' ' && board[3] != ' ' && board[4] != ' ' && board[5] != ' ' && board[6] != ' ' && board[7] != ' ' && board[8] != ' ')
        return GAME_STATE_DRAW;
    else
        return GAME_STATE_ONGOING;
}
void TicTacToe::clearBoard() {
    for (int i = 0; i < 9; i++)
        board[i] = ' ';
}

// int TicTacToe::checkWin() {
//     char win_patterns[8][3] = {
//         {0,1,2},{3,4,5},{6,7,8},
//         {0,3,6},{1,4,7},{2,5,8},
//         {0,4,8},{2,4,6}
//     };
//     for (auto& pattern : win_patterns) {
//         if (board[pattern[0]] == board[pattern[1]] && board[pattern[1]] == board[pattern[2]] && board[pattern[0]] != ' ') {
//             return GAME_STATE_RESULT;
//         }
//     }
//     for (int i = 0; i < 9; i++) if (board[i] == ' ') return GAME_STATE_ONGOING;
//     return GAME_STATE_DRAW;
// }