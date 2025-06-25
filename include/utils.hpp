#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>
#include "PlayerData.hpp"

int isEven(int x);
std::string getName(int player);

extern char board[9];
extern int selector, vs_state, player, counter;
extern std::string lineInput;

extern PlayerData *player1;
extern PlayerData *player2;
extern PlayerData *empty;

extern std::string lineInput;

#endif