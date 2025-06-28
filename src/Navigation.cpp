#include "../include/Navigation.hpp"
#include "../include/utils.hpp"
#include "../include/Display.hpp"

void GameNavigation::MoveUp(){
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
        GameNavigation::removeSelector();
        board[selector - 1] = '^';
    }
}
void GameNavigation::MoveDown(){
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
        GameNavigation::removeSelector();
        board[selector - 1] = '^';
    }
}
void GameNavigation::MoveLeft(){
    selector -= 1;
    selector = selector <= 0 ? selector + 9 : selector;
    if (board[selector - 1] == 'X' || board[selector - 1] == 'O')
        MoveLeft();
    else{
        GameNavigation::removeSelector();
        board[selector - 1] = '^';
    }
}
void GameNavigation::MoveRight(){
    selector += 1;
    selector = selector > 9 ? selector - 9 : selector;
    if (board[selector - 1] == 'X' || board[selector - 1] == 'O')
        MoveRight();
    else{
        GameNavigation::removeSelector();
        board[selector - 1] = '^';
    }
}
void GameNavigation::removeSelector() {
    for (int i = 0; i < 9; i++)
        if (board[i] == '^')
            board[i] = ' ';
}

void GameNavigation::Nav() {
    arrow = getch();
    do {
        switch (arrow) {
        case KEY_ESC:
            exitProgram();
        default:
            arrow = getch();
            switch (arrow) {
            case KEY_UP:
                GameNavigation::MoveUp();
                Display::showBoard();
                break;
            case KEY_DOWN:
                GameNavigation::MoveDown();
                Display::showBoard();
                break;
            case KEY_LEFT:
                GameNavigation::MoveLeft();
                Display::showBoard();
                break;
            case KEY_RIGHT:
                GameNavigation::MoveRight();
                Display::showBoard();
                break;
            case KEY_ESC:
                exitProgram();
            default:
                break;
            }
            break;
        }
    } while (arrow != KEY_ENTER);
}

void MenuNavigation::Nav(int button1, int button2) {
    arrow = getch();
    do {
        switch (arrow) {
        case KEY_ESC:
            exitProgram();
        default:
            arrow = getch();
            switch (arrow) {
            case KEY_UP:
                Display::showMenu(button1);
                selector = '1';
                break;
            case KEY_DOWN:
                Display::showMenu(button2);
                selector = '2';
                break;
            case KEY_ESC:
                exitProgram();
            default:
                break;
            }
            break;
        }
    } while (arrow != KEY_ENTER);
}