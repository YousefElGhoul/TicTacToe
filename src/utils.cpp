#include "../include/utils.hpp"
#include "../include/PlayerData.hpp"

extern PlayerData *player1 = new PlayerData("", 0);
extern PlayerData *player2 = new PlayerData("", 0);
extern PlayerData *empty = new PlayerData("", 0);

extern char board[9] = {};
extern int selector, vs_state = 1, player = 1, counter = 0;
extern std::string lineInput;

int isEven(int x) { return x % 2 == 0 ? 2 : 1; }

std::string getName(int player) { return isEven(player) == 1 ? player1->getName() : player2->getName();}
