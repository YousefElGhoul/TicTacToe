#include "../include/Navigation.hpp"
#include "../include/Display.hpp"
#include "../include/ASCIIArt.hpp"
#include <iostream>

extern char board[9];
extern int selector;
extern int counter;

void removeSelector() {
    for (int i = 0; i < 9; i++)
        if (board[i] == '^')
            board[i] = ' ';
}

void MoveRight(){
    selector += 1;
    selector = selector > 9 ? selector - 9 : selector;
    if (board[selector - 1] == 'X' || board[selector - 1] == 'O')
        MoveRight();
    else{
        removeSelector();
        board[selector - 1] = '^';
        Display::refresh(LOGO);
        Display::printBoard();
    }
}

void MoveLeft(){
    selector -= 1;
    selector = selector <= 0 ? selector + 9 : selector;
    if (board[selector - 1] == 'X' || board[selector - 1] == 'O')
        MoveLeft();
    else{
        removeSelector();
        board[selector - 1] = '^';
        Display::refresh(LOGO);
        Display::printBoard();
    }
}

void MoveUp(){
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
        removeSelector();
        board[selector - 1] = '^';
        Display::refresh(LOGO);
        Display::printBoard();
    }
}

void MoveDown(){
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
        removeSelector();
        board[selector - 1] = '^';
        Display::refresh(LOGO);
        Display::printBoard();
    }
}