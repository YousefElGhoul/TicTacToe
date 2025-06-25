#include "../include/utils.hpp"
#include "../include/Scores.hpp"
#include <fstream>
#include <string>

#define HIGH_SCORE_FILE_ARRAY_SIZE 5
#define HIGH_SCORE_FILE_NAME "high_scores.dat"
#define HIGH_SCORE_FILE_DEFAULT "Yousef\nNicole\nOwen\nPenny\nMalika\n10\n9\n8\n7\n6\n"

PlayerData High_Scores[5] = {*empty, *empty, *empty, *empty, *empty};

extern std::string lineInput;

void swapData(PlayerData* xp, PlayerData* yp){
    PlayerData temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortData(){
    for (int i = 0; i < HIGH_SCORE_FILE_ARRAY_SIZE - 1; i++)
        for (int j = 0; j < HIGH_SCORE_FILE_ARRAY_SIZE - i - 1; j++)
            if(High_Scores[j].getScore() < High_Scores[j+1].getScore())
                swapData(&High_Scores[j], &High_Scores[j+1]);
}


void checkFile(){
    std::fstream file;
    file.open(HIGH_SCORE_FILE_NAME);
    if(!file){
        file.open(HIGH_SCORE_FILE_NAME, std::ios::out);
        if(file.is_open()){
            file << HIGH_SCORE_FILE_DEFAULT;
            file.close();
        }
    }
    file.close();
}

void readHighScores(){
    std::fstream file;
    file.open(HIGH_SCORE_FILE_NAME, std::ios::in);
    if(file.is_open()){
        for (int i = 0; i < HIGH_SCORE_FILE_ARRAY_SIZE; i++){
            getline(file, lineInput);
            High_Scores[i].setName(lineInput);
        }
        for (int i = 0; i < HIGH_SCORE_FILE_ARRAY_SIZE; i++){
            getline(file, lineInput);
            High_Scores[i].setScore(stoi(lineInput));
        }
        file.close();
        sortData();
    }
}

void saveHighScores(){
    std::fstream file;
    file.open(HIGH_SCORE_FILE_NAME, std::ios::out);
    if(file.is_open()){
        for (int i = 0; i < HIGH_SCORE_FILE_ARRAY_SIZE; i++)
            file << High_Scores[i].getName() << "\n";
        for (int i = 0; i < HIGH_SCORE_FILE_ARRAY_SIZE; i++)
            file << High_Scores[i].getScore() << "\n";
        file.close();
    }
}

void addScore(PlayerData pd){
    if(pd.getScore() > High_Scores[HIGH_SCORE_FILE_ARRAY_SIZE - 1].getScore()){
        High_Scores[HIGH_SCORE_FILE_ARRAY_SIZE - 1] = pd;
        sortData();
    }
}

void refreshHighScores(){
    addScore(*player1);
    addScore(*player2);
    saveHighScores();
}
