#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

class TicTacToe {
public:
    static void initGame();
    static int checkWin();

private:
    static void clearBoard();
};

#endif