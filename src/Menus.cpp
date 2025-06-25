#include "../include/Menus.hpp"
#include "../include/Display.hpp"
#include "../include/Navigation.hpp"
#include "../include/TicTacToe.hpp"
#include "../include/Scores.hpp"
#include "../include/PlayerData.hpp"
#include "../include/utils.hpp"
#include "../include/ASCIIArt.hpp"
#include <iostream>
#include <conio.h>
#include <cstdlib>

#define START 0
#define GAME 1
#define VS 2
#define WIN 3
#define LOSE 4
#define DRAW 5
#define NAME 6
#define HIGH_SCORES 7
#define RESTART 8

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27

#define VS_STATE_HUM 1
#define VS_STATE_COM 0

void select(int menu){
    switch (menu){
    case START:
        Display::refresh(START_MENU);
        arrow = getch();
        do{
            switch (arrow){
            case KEY_ESC:
                exitProgram();
            default:
                arrow = getch();
                switch (arrow){
                case KEY_UP:
                    Display::refresh(START_MENU_START_SELECTED);
                    selector = 'S';
                    break;
                case KEY_DOWN:
                    Display::refresh(START_MENU_EXIT_SELECTED);
                    selector = 'E';
                    break;
                case KEY_ESC:
                    exitProgram();
                default:
                    break;
                }
                break;
            }
        }while (arrow != KEY_ENTER);
        switch (selector){
        case 'S':
            Menus::select(VS);
            break;
        case 'E':
            exitProgram();
        default:
            break;
        }
        break;
    case VS:
        std::cout << "\nTo be Implemented\n";
        Menus::select(NAME);
        break;
    case NAME:
        Display::refresh(LOGO);
        if(vs_state == VS_STATE_COM){
            std::cout << "Player 1: \n";
            std::getline(std::cin, lineInput);
            player1->setName(lineInput);
            if(player1->isEmpty())
                player1->setName("Player 1");
        }
        else{
            std::cout << "Player 1: \n";
            std::getline(std::cin, lineInput);
            player1->setName(lineInput);
            if(player1->isEmpty())
                player1->setName("Player 1");
            std::cout << "\nPlayer 2: \n";
            std::getline(std::cin, lineInput);
            player2->setName(lineInput);
            if(player2->isEmpty())
                player2->setName("Player 2");
        }
        Menus::select(GAME);
        break;
    case GAME:
        selector = 0;
        Display::refresh(LOGO);
        Display::printBoard();
        arrow = getch();
        do{
            switch (arrow){
            case KEY_ESC:
                exitProgram();
            default:
                arrow = getch();
                switch (arrow){
                case KEY_UP:
                    Navigation::MoveUp();
                    break;
                case KEY_DOWN:
                    Navigation::MoveDown();
                    break;
                case KEY_LEFT:
                    Navigation::MoveLeft();
                    break;
                case KEY_RIGHT:
                    Navigation::MoveRight();
                    break;
                case KEY_ESC:
                    exitProgram();
                default:
                    break;
                }
                break;
            }
        }while (arrow != KEY_ENTER);
        switch (isEven(player)){
        case 1:
            board[selector - 1] = 'X';
            break;
        case 2:
            board[selector - 1] = 'O';
        default:
            break;
        }
        Display::refresh(LOGO);
        Display::printBoard();
        switch (TicTacToe::checkWin()){
        case GAME_STATE_ONGOING:
            player++;
            Menus::select(GAME);
            break;
        case GAME_STATE_RESULT:
            Menus::select(WIN);
            break;
        case GAME_STATE_DRAW:
            Menus::select(DRAW);
        default:
            break;
        }
        break;
    case WIN:
        std::cout << "\t\t\t\t\t\t" << getName(player) << " Wins!\n";
        switch (isEven(player)){
        case 1:
            player1->incScore();
            break;
        case 2:
            player2->incScore();
        default:
            break;
        }
        system("pause");
        Menus::select(RESTART);
        break;
    case DRAW:
        std::cout << "\t\t\t\t\t\tGame is a Draw!\n";
        system("pause");
        Menus::select(RESTART);
        break;
    case RESTART:
        Display::refresh(RESTART_MENU);
        arrow = getch();
        do{
            switch (arrow){
            case KEY_ESC:
                exitProgram();
            default:
                arrow = getch();
                switch (arrow){
                case KEY_UP:
                    Display::refresh(RESTART_MENU_RESTART_SELECTED);
                    selector = 'R';
                    break;
                case KEY_DOWN:
                    Display::refresh(RESTART_MENU_EXIT_SELECTED);
                    selector = 'E';
                    break;
                case KEY_ESC:
                    exitProgram();
                default:
                    break;
                }
                break;
            }
        }while (arrow != KEY_ENTER);
        switch (selector){
        case 'R':
            TicTacToe::initGame();
            Menus::select(GAME);
            break;
        case 'E':
            Menus::select(HIGH_SCORES);
        default:
            break;
        }
        break;
    case HIGH_SCORES:
        Display::refresh(LOGO);
        Display::printScores();
        exitProgram();
        break;
    default:
        std::cout << "\nMissing Screen\n";
        break;
    }
}