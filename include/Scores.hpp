#ifndef SCORES_HPP
#define SCORES_HPP
#include "PlayerData.hpp"

#define HIGH_SCORE_FILE_ARRAY_SIZE 5

class Scores {
public:
    static void checkFile();
    static void readHighScores();
    static void saveHighScores();
    static void refreshHighScores();
};

extern PlayerData High_Scores[5];

#endif