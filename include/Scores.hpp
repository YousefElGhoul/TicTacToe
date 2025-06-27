#ifndef SCORES_HPP
#define SCORES_HPP

#include "PlayerData.hpp"

class Scores {
public:
    static void checkFile();
    static void readHighScores();
    static void saveHighScores();
    static void refreshHighScores();

private:
    static void swapData(PlayerData* xp, PlayerData* yp);
    static void sortData();
    static void addScore(PlayerData pd);
};

#endif