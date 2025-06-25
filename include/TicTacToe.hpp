#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#define GAME_STATE_DRAW 0
#define GAME_STATE_RESULT 1
#define GAME_STATE_ONGOING -1

class TicTacToe {
public:
    static void initGame();
    static int checkWin();
};

#endif