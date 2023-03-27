#include <iostream>
#include <fstream>
#include <conio.h>

#define LOGO "\t\t\t      _____  _  ____      _____  ____  ____      _____  ____  _____\n\t\t\t     /__ __\\/ \\/   _\\    /__ __\\/  _ \\/   _\\    /__ __\\/  _ \\/  __/\n\t\t\t       / \\  | ||  /  _____ / \\  | / \\||  /  _____ / \\  | / \\||  \\  \n\t\t\t       | |  | ||  \\__\\____\\| |  | |-|||  \\__\\____\\| |  | \\_/||  /_ \n\t\t\t       \\_/  \\_/\\____/      \\_/  \\_/ \\|\\____/      \\_/  \\____/\\____\\\n\n"

#define START 0
#define START_MENU "\t\t\t      _____  _  ____      _____  ____  ____      _____  ____  _____\n\t\t\t     /__ __\\/ \\/   _\\    /__ __\\/  _ \\/   _\\    /__ __\\/  _ \\/  __/\n\t\t\t       / \\  | ||  /  _____ / \\  | / \\||  /  _____ / \\  | / \\||  \\  \n\t\t\t       | |  | ||  \\__\\____\\| |  | |-|||  \\__\\____\\| |  | \\_/||  /_ \n\t\t\t       \\_/  \\_/\\____/      \\_/  \\_/ \\|\\____/      \\_/  \\____/\\____\\\n\n  ________________________\n |                        |\n |         START          |\n |________________________|\n  ________________________\n |                        |\n |         EXIT           |\n |________________________|\n"
#define START_MENU_START_SELECTED "\t\t\t      _____  _  ____      _____  ____  ____      _____  ____  _____\n\t\t\t     /__ __\\/ \\/   _\\    /__ __\\/  _ \\/   _\\    /__ __\\/  _ \\/  __/\n\t\t\t       / \\  | ||  /  _____ / \\  | / \\||  /  _____ / \\  | / \\||  \\  \n\t\t\t       | |  | ||  \\__\\____\\| |  | |-|||  \\__\\____\\| |  | \\_/||  /_ \n\t\t\t       \\_/  \\_/\\____/      \\_/  \\_/ \\|\\____/      \\_/  \\____/\\____\\\n\n \t ________________________\n \t|                        |\n \t|         START          |\n \t|________________________|\n  ________________________\n |                        |\n |         EXIT           |\n |________________________|\n"
#define START_MENU_EXIT_SELECTED "\t\t\t      _____  _  ____      _____  ____  ____      _____  ____  _____\n\t\t\t     /__ __\\/ \\/   _\\    /__ __\\/  _ \\/   _\\    /__ __\\/  _ \\/  __/\n\t\t\t       / \\  | ||  /  _____ / \\  | / \\||  /  _____ / \\  | / \\||  \\  \n\t\t\t       | |  | ||  \\__\\____\\| |  | |-|||  \\__\\____\\| |  | \\_/||  /_ \n\t\t\t       \\_/  \\_/\\____/      \\_/  \\_/ \\|\\____/      \\_/  \\____/\\____\\\n\n  ________________________\n |                        |\n |         START          |\n |________________________|\n \t ________________________\n \t|                        |\n \t|         EXIT           |\n \t|________________________|\n"
#define GAME 1
#define VS 2
// #define VS_MENU                  To be Implemented
#define WIN 3
#define LOSE 4
#define DRAW 5
#define NAME 6
#define HIGH_SCORES 7
#define RESTART 8
#define RESTART_MENU "\t\t\t      _____  _  ____      _____  ____  ____      _____  ____  _____\n\t\t\t     /__ __\\/ \\/   _\\    /__ __\\/  _ \\/   _\\    /__ __\\/  _ \\/  __/\n\t\t\t       / \\  | ||  /  _____ / \\  | / \\||  /  _____ / \\  | / \\||  \\  \n\t\t\t       | |  | ||  \\__\\____\\| |  | |-|||  \\__\\____\\| |  | \\_/||  /_ \n\t\t\t       \\_/  \\_/\\____/      \\_/  \\_/ \\|\\____/      \\_/  \\____/\\____\\\n\n  ________________________\n |                        |\n |        RESTART         |\n |________________________|\n  ________________________\n |                        |\n |         EXIT           |\n |________________________|\n"
#define RESTART_MENU_RESTART_SELECTED "\t\t\t      _____  _  ____      _____  ____  ____      _____  ____  _____\n\t\t\t     /__ __\\/ \\/   _\\    /__ __\\/  _ \\/   _\\    /__ __\\/  _ \\/  __/\n\t\t\t       / \\  | ||  /  _____ / \\  | / \\||  /  _____ / \\  | / \\||  \\  \n\t\t\t       | |  | ||  \\__\\____\\| |  | |-|||  \\__\\____\\| |  | \\_/||  /_ \n\t\t\t       \\_/  \\_/\\____/      \\_/  \\_/ \\|\\____/      \\_/  \\____/\\____\\\n\n \t ________________________\n \t|                        |\n \t|        RESTART         |\n \t|________________________|\n  ________________________\n |                        |\n |         EXIT           |\n |________________________|\n"
#define RESTART_MENU_EXIT_SELECTED "\t\t\t      _____  _  ____      _____  ____  ____      _____  ____  _____\n\t\t\t     /__ __\\/ \\/   _\\    /__ __\\/  _ \\/   _\\    /__ __\\/  _ \\/  __/\n\t\t\t       / \\  | ||  /  _____ / \\  | / \\||  /  _____ / \\  | / \\||  \\  \n\t\t\t       | |  | ||  \\__\\____\\| |  | |-|||  \\__\\____\\| |  | \\_/||  /_ \n\t\t\t       \\_/  \\_/\\____/      \\_/  \\_/ \\|\\____/      \\_/  \\____/\\____\\\n\n  ________________________\n |                        |\n |        RESTART         |\n |________________________|\n \t ________________________\n \t|                        |\n \t|         EXIT           |\n \t|________________________|\n"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27

#define GAME_STATE_DRAW 0
#define GAME_STATE_RESULT 1
#define GAME_STATE_ONGOING -1

#define VS_STATE_HUM 1
#define VS_STATE_COM 0

#define HIGH_SCORE_FILE_ARRAY_SIZE 5
#define HIGH_SCORE_FILE_NAME "high_scores.dat"
#define HIGH_SCORE_FILE_DEFAULT "Yousef\nNicole\nOwen\nPenny\nMalika\n10\n9\n8\n7\n6\n"

char board[9] = {};
char arrow;
int selector, vs_state = 1, player = 1, counter = 0;
std::string lineInput;

class PlayerData{
    public:
        PlayerData(std::string str, int num): name(str), score(num){};


        void setName(std::string str){name = str;}
        void setScore(int num){score = num;}
        std::string getName(){return name;}
        int getScore(){return score;}

        bool isEmpty(){return name.empty();}
        void incScore(){score++;}
    private:
        std::string name;
        int score;
};

PlayerData *player1 = new PlayerData("", 0);
PlayerData *player2 = new PlayerData("", 0);
PlayerData *empty = new PlayerData("", 0);

int isEven(int x){return x % 2 == 0 ? 2 : 1;}
std::string getName(int player){return isEven(player) == 1 ? player1->getName() : player2->getName();}

PlayerData High_Scores[HIGH_SCORE_FILE_ARRAY_SIZE] = {*empty, *empty, *empty, *empty, *empty};

class Scores{
    public:
        static void checkFile(){
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
        static void readHighScores(){
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
        static void saveHighScores(){
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
        static void refreshHighScores(){
            addScore(*player1);
            addScore(*player2);
            saveHighScores();
        }
    private:
        static void swapData(PlayerData* xp, PlayerData* yp){
            PlayerData temp = *xp;
            *xp = *yp;
            *yp = temp;
        }
        static void sortData(){
            for (int i = 0; i < HIGH_SCORE_FILE_ARRAY_SIZE - 1; i++)
                for (int j = 0; j < HIGH_SCORE_FILE_ARRAY_SIZE - i - 1; j++)
                    if(High_Scores[j].getScore() < High_Scores[j+1].getScore())
                        swapData(&High_Scores[j], &High_Scores[j+1]);
        }
        static void addScore(PlayerData pd){
            if(pd.getScore() > High_Scores[HIGH_SCORE_FILE_ARRAY_SIZE - 1].getScore()){
                High_Scores[HIGH_SCORE_FILE_ARRAY_SIZE - 1] = pd;
                sortData();
            }
        }
};

class Display{
    public:
        static void initDisplay(){
            system("color a");
            clear();
        }
        static void refresh(std::string str){
            clear();
            print(str);
        }
        static void printBoard(){
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
        static void printScores(){
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
    private:
        static void clear(){system("CLS");}
        static void print(std::string str){std::cout << str;}
};

class Navigation{
    public:
        static void MoveUp(){
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
                Navigation::removeSelector();
                board[selector - 1] = '^';
                Display::refresh(LOGO);
                Display::printBoard();
            }
        }
        static void MoveDown(){
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
                Navigation::removeSelector();
                board[selector - 1] = '^';
                Display::refresh(LOGO);
                Display::printBoard();
            }
        }
        static void MoveLeft(){
            selector -= 1;
            selector = selector <= 0 ? selector + 9 : selector;
            if (board[selector - 1] == 'X' || board[selector - 1] == 'O')
                MoveLeft();
            else{
                Navigation::removeSelector();
                board[selector - 1] = '^';
                Display::refresh(LOGO);
                Display::printBoard();
            }
        }
        static void MoveRight(){
            selector += 1;
            selector = selector > 9 ? selector - 9 : selector;
            if (board[selector - 1] == 'X' || board[selector - 1] == 'O')
                MoveRight();
            else{
                Navigation::removeSelector();
                board[selector - 1] = '^';
                Display::refresh(LOGO);
                Display::printBoard();
            }
        }
        static void removeSelector() {
            for (int i = 0; i < 9; i++)
                if (board[i] == '^')
                    board[i] = ' ';
        }
};

class TicTacToe{
    public:
        static void initGame(){
            clearBoard();
        }
        static int checkWin(){
            if (board[0] == board[1] && board[1] == board[2] && board[2] == 'X')
                return GAME_STATE_RESULT;
            else if (board[0] == board[1] && board[1] == board[2] && board[2] == 'O')
                return GAME_STATE_RESULT;
            else if (board[3] == board[4] && board[4] == board[5] && board[5] == 'X')
                return GAME_STATE_RESULT;
            else if (board[3] == board[4] && board[4] == board[5] && board[5] == 'O')
                return GAME_STATE_RESULT;
            else if (board[6] == board[7] && board[7] == board[8] && board[8] == 'X')
                return GAME_STATE_RESULT;
            else if (board[6] == board[7] && board[7] == board[8] && board[8] == 'O')
                return GAME_STATE_RESULT;
            else if (board[0] == board[3] && board[3] == board[6] && board[6] == 'X')
                return GAME_STATE_RESULT;
            else if (board[0] == board[3] && board[3] == board[6] && board[6] == 'O')
                return GAME_STATE_RESULT;
            else if (board[1] == board[4] && board[4] == board[7] && board[7] == 'X')
                return GAME_STATE_RESULT;
            else if (board[1] == board[4] && board[4] == board[7] && board[7] == 'O')
                return GAME_STATE_RESULT;
            else if (board[2] == board[5] && board[5] == board[8] && board[8] == 'X')
                return GAME_STATE_RESULT;
            else if (board[2] == board[5] && board[5] == board[8] && board[8] == 'O')
                return GAME_STATE_RESULT;
            else if (board[0] == board[4] && board[4] == board[8] && board[8] == 'X')
                return GAME_STATE_RESULT;
            else if (board[0] == board[4] && board[4] == board[8] && board[8] == 'O')
                return GAME_STATE_RESULT;
            else if (board[2] == board[4] && board[4] == board[6] && board[6] == 'X')
                return GAME_STATE_RESULT;
            else if (board[2] == board[4] && board[4] == board[6] && board[6] == 'O')
                return GAME_STATE_RESULT;
            else if (board[0] != ' ' && board[1] != ' ' && board[2] != ' ' && board[3] != ' ' && board[4] != ' ' && board[5] != ' ' && board[6] != ' ' && board[7] != ' ' && board[8] != ' ')
                return GAME_STATE_DRAW;
            else
                return GAME_STATE_ONGOING;
        }
    private:
        static void clearBoard() {
            for (int i = 0; i < 9; i++)
                board[i] = ' ';
        }
};

void exitProgram(){
    Scores::saveHighScores();
    exit(0);
}

class Menus{
    public:
        static void select(int menu){
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
                    getline(std::cin, lineInput);
                    player1->setName(lineInput);
                    if(player1->isEmpty())
                        player1->setName("Player 1");
                }
                else{
                    std::cout << "Player 1: \n";
                    getline(std::cin, lineInput);
                    player1->setName(lineInput);
                    if(player1->isEmpty())
                        player1->setName("Player 1");
                    std::cout << "\nPlayer 2: \n";
                    getline(std::cin, lineInput);
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
};

void initProgram(){
    Scores::checkFile();
    Scores::readHighScores();
    Display::initDisplay();
    TicTacToe::initGame();
    Menus::select(START);
}

int main(){
    initProgram();
    system("pause");
    exitProgram();
}