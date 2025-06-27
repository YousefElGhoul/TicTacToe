#include "../include/Navigation.hpp"
#include "../include/Utils.hpp"
#include "../include/Display.hpp"

void Navigation::MoveUp(){
    if(counter == 3){
        counter = 0;
        MoveRight();
    }
    selector -= 3;
    selector = selector <= 0 ? selector + 9 : selector;
    if (board[selector - 1] == 'X' || board[selector - 1] == 'O'){
        counter++;
        MoveUp();
    }
    else{
        Navigation::removeSelector();
        board[selector - 1] = '^';
        Display::refresh(LOGO);
        Display::printBoard();
    }
}
void Navigation::MoveDown(){
    if(counter == 3){
        counter = 0;
        MoveLeft();
    }
    selector += 3;
    selector = selector > 9 ? selector - 9 : selector;
    if (board[selector - 1] == 'X' || board[selector - 1] == 'O'){
        counter++;
        MoveDown();
    }
    else{
        Navigation::removeSelector();
        board[selector - 1] = '^';
        Display::refresh(LOGO);
        Display::printBoard();
    }
}
void Navigation::MoveLeft(){
    selector -= 1;
    selector = selector <= 0 ? selector + 9 : selector;
    if (board[selector - 1] == 'X' || board[selector - 1] == 'O')
        MoveLeft();
    else{
        Navigation::removeSelector();
        board[selector - 1] = '^';
        Display::refresh(LOGO);
        Display::printBoard();
    }
}
void Navigation::MoveRight(){
    selector += 1;
    selector = selector > 9 ? selector - 9 : selector;
    if (board[selector - 1] == 'X' || board[selector - 1] == 'O')
        MoveRight();
    else{
        Navigation::removeSelector();
        board[selector - 1] = '^';
        Display::refresh(LOGO);
        Display::printBoard();
    }
}
void Navigation::removeSelector() {
    for (int i = 0; i < 9; i++)
        if (board[i] == '^')
            board[i] = ' ';
}