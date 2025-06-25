#include "../include/Display.hpp"
#include "../include/Scores.hpp"
#include "../include/utils.hpp"
#include "../include/PlayerData.hpp"
#include "../include/ASCIIArt.hpp"
#include <iostream>
#include <cstdlib>

extern char board[9];
extern int player;
extern PlayerData High_Scores[5];

void clear(){system("CLS");}
void print(std::string str){std::cout << str;}

void initDisplay(){
    system("color a");
    clear();
}

void refresh(std::string str){
    clear();
    print(str);
}

void printBoard(){
    std::cout << player1->getName() << " (X) Score [" << player1->getScore() << "]  -  " << player2->getName() << " (O) Score [" << player2->getScore() << "]" << std::endl << std::endl
            << "\t\t\t\t\t\tTurn: " << getName(player) << std::endl << std::endl
            << "\t\t\t\t\t\t     |     |     " << std::endl
            << "\t\t\t\t\t\t  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << std::endl
            << "\t\t\t\t\t\t_____|_____|_____" << std::endl
            << "\t\t\t\t\t\t     |     |     " << std::endl
            << "\t\t\t\t\t\t  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << std::endl
            << "\t\t\t\t\t\t_____|_____|_____" << std::endl
            << "\t\t\t\t\t\t     |     |     " << std::endl
            << "\t\t\t\t\t\t  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << std::endl
            << "\t\t\t\t\t\t     |     |     " << std::endl << std::endl;
}

void printScores(){
    Scores::refreshHighScores();
    refresh(LOGO);
    for (int i = 0; i < HIGH_SCORE_FILE_ARRAY_SIZE; i++){
        std::cout << "\t\t\t" << "                |" /*<< "\t\t\t" << "                |"*/ << std::endl 
                << "\t\t\t" << "    " <<  High_Scores[i].getName() << "\t|       " << High_Scores[i].getScore() /*<< "\t\t"  << "    " <<  High_Scores[i].getName() << "\t|       " << High_Scores[i].getScore() */<<  std::endl;
        if(i != HIGH_SCORE_FILE_ARRAY_SIZE - 1)
            std::cout << "\t\t\t" << "________________|________________" /*<< "\t" << "________________|________________"*/ <<  std::endl;
        else std::cout << "\t\t\t" << "                |" /*<< "\t\t\t" << "                |"*/ <<  std::endl;
    }
    system("pause");
}