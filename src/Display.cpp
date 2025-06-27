#include"../include/Display.hpp"
#include "../include/Utils.hpp"
#include "../include/Scores.hpp"

void Display::initDisplay(){
    system("color a");
    clear();
}
void Display::refresh(std::string str){
    clear();
    print(str);
}
void Display::printBoard(){
    std::cout << player1->getName() << " (X) Score [" << player1->getScore() << "]  -  " << player2->getName() << " (O) Score [" << player2->getScore() << "]" << std::endl << std::endl
            << "\t\t\t\t\t\tTurn: " << getCurrentPlayersName(player) << std::endl << std::endl
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
void Display::printScores(){
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
void Display::clear(){system("CLS");}
void Display::print(std::string str){std::cout << str;}