#ifndef UTILS_HPP
#define UTILS_HPP

#include "Display.hpp"
#include "Scores.hpp"
#include "TicTacToe.hpp"
#include "Menus.hpp"
#include "PlayerData.hpp"
#include <iostream>
#include <fstream>
#include <conio.h>

#define START                       0
#define GAME                        1
#define VS                          2
#define WIN                         3
#define LOSE                        4
#define DRAW                        5
#define NAME                        6
#define HIGH_SCORES                 7
#define RESTART                     8

#define KEY_UP                      72
#define KEY_DOWN                    80
#define KEY_LEFT                    75
#define KEY_RIGHT                   77
#define KEY_ENTER                   13
#define KEY_ESC                     27

#define GAME_STATE_DRAW             0
#define GAME_STATE_RESULT           1
#define GAME_STATE_ONGOING          -1

#define VS_STATE_HUM                1
#define VS_STATE_COM                0

#define HIGH_SCORE_FILE_ARRAY_SIZE  5
#define HIGH_SCORE_FILE_NAME        "high_scores.dat"
#define HIGH_SCORE_FILE_DEFAULT     "Yousef\nNicole\nOwen\nPenny\nMalika\n10\n9\n8\n7\n6\n"

extern char board[9];
extern char arrow;
extern int selector, vs_state, player, counter;
extern std::string lineInput;

extern PlayerData *player1;
extern PlayerData *player2;
extern PlayerData *empty;

extern PlayerData High_Scores[HIGH_SCORE_FILE_ARRAY_SIZE];

int isEven(int x);
std::string getCurrentPlayersName(int player);

void initProgram();
void exitProgram();

#endif