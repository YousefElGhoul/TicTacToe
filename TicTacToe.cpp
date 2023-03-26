#include <iostream>
#include <conio.h>

using namespace std;

#define LOGO "\t\t\t      _____  _  ____      _____  ____  ____      _____  ____  _____\n\t\t\t     /__ __\\/ \\/   _\\    /__ __\\/  _ \\/   _\\    /__ __\\/  _ \\/  __/\n\t\t\t       / \\  | ||  /  _____ / \\  | / \\||  /  _____ / \\  | / \\||  \\  \n\t\t\t       | |  | ||  \\__\\____\\| |  | |-|||  \\__\\____\\| |  | \\_/||  /_ \n\t\t\t       \\_/  \\_/\\____/      \\_/  \\_/ \\|\\____/      \\_/  \\____/\\____\\\n\n"

#define START 0
#define START_MENU "\t\t\t      _____  _  ____      _____  ____  ____      _____  ____  _____\n\t\t\t     /__ __\\/ \\/   _\\    /__ __\\/  _ \\/   _\\    /__ __\\/  _ \\/  __/\n\t\t\t       / \\  | ||  /  _____ / \\  | / \\||  /  _____ / \\  | / \\||  \\  \n\t\t\t       | |  | ||  \\__\\____\\| |  | |-|||  \\__\\____\\| |  | \\_/||  /_ \n\t\t\t       \\_/  \\_/\\____/      \\_/  \\_/ \\|\\____/      \\_/  \\____/\\____\\\n\n  ________________________\n |                        |\n |         START          |\n |________________________|\n  ________________________\n |                        |\n |         EXIT           |\n |________________________|\n"
#define START_MENU_START_SELECTED "\t\t\t      _____  _  ____      _____  ____  ____      _____  ____  _____\n\t\t\t     /__ __\\/ \\/   _\\    /__ __\\/  _ \\/   _\\    /__ __\\/  _ \\/  __/\n\t\t\t       / \\  | ||  /  _____ / \\  | / \\||  /  _____ / \\  | / \\||  \\  \n\t\t\t       | |  | ||  \\__\\____\\| |  | |-|||  \\__\\____\\| |  | \\_/||  /_ \n\t\t\t       \\_/  \\_/\\____/      \\_/  \\_/ \\|\\____/      \\_/  \\____/\\____\\\n\n \t ________________________\n \t|                        |\n \t|         START          |\n \t|________________________|\n  ________________________\n |                        |\n |         EXIT           |\n |________________________|\n"
#define START_MENU_EXIT_SELECTED "\t\t\t      _____  _  ____      _____  ____  ____      _____  ____  _____\n\t\t\t     /__ __\\/ \\/   _\\    /__ __\\/  _ \\/   _\\    /__ __\\/  _ \\/  __/\n\t\t\t       / \\  | ||  /  _____ / \\  | / \\||  /  _____ / \\  | / \\||  \\  \n\t\t\t       | |  | ||  \\__\\____\\| |  | |-|||  \\__\\____\\| |  | \\_/||  /_ \n\t\t\t       \\_/  \\_/\\____/      \\_/  \\_/ \\|\\____/      \\_/  \\____/\\____\\\n\n  ________________________\n |                        |\n |         START          |\n |________________________|\n \t ________________________\n \t|                        |\n \t|         EXIT           |\n \t|________________________|\n"
#define GAME 1
#define VS 2
// #define VS_MENU
#define WIN 3
#define LOSE 4
#define DRAW 5
#define NAME 6
#define HIGH_SCORES 7
// #define HIGH_SCORES_MENU
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

char board[9] = {};
char arrow;
int selector, vs_state = 1, player = 1;
string player1 = "Player 1", player2 = "Player 2";
int score1 = 0, score2 = 0;

int isEven(int x){return x % 2 == 0 ? 2 : 1;}

void exitProgram(){
    exit(0);
}

class Game{
    public:
        static void initDisplay(){
            system("color a");
            clear();
        }
        static void initGame(){
            clearBoard();
        }
        static void menu(int menu){
            switch (menu){
            case START:
                refresh(START_MENU);
                arrow = getch();
                do{
                    switch (arrow){
                    case KEY_ESC:
                        exitProgram();
                    default:
                        arrow = getch();
                        switch (arrow){
                        case KEY_UP:
                            refresh(START_MENU_START_SELECTED);
                            selector = 'S';
                            break;
                        case KEY_DOWN:
                            refresh(START_MENU_EXIT_SELECTED);
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
                    Game::menu(VS);
                    break;
                case 'E':
                    exitProgram();
                default:
                    break;
                }
                break;
            case VS:
                cout << "\nVS Screen\n";
                Game::menu(NAME);
                break;
            case NAME:
                refresh(LOGO);
                if(vs_state == VS_STATE_COM){
                    cout << "Player 1: \n";
                    getline(cin, player1);
                    if(player1.empty())
                        player1 = "Player 1";
                }
                else{
                    cout << "Player 1: \n";
                    getline(cin, player1);
                    if(player1.empty())
                        player1 = "Player 1";
                    cout << "\nPlayer 2: \n";
                    getline(cin, player2);
                    if(player2.empty())
                        player2 = "Player 2";
                }
                Game::menu(GAME);
                break;
            case GAME:
                selector = 0;
                refresh(LOGO);
                printBoard();
                arrow = getch();
                do{
                    switch (arrow){
                    case KEY_ESC:
                        exitProgram();
                    default:
                        arrow = getch();
                        switch (arrow){
                        case KEY_UP:
                            MoveUp();
                            break;
                        case KEY_DOWN:
                            MoveDown();
                            break;
                        case KEY_LEFT:
                            MoveLeft();
                            break;
                        case KEY_RIGHT:
                            MoveRight();
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
                refresh(LOGO);
                printBoard();
                switch (checkWin()){
                case GAME_STATE_ONGOING:
                    player++;
                    Game::menu(GAME);
                    break;
                case GAME_STATE_RESULT:
                    Game::menu(WIN);
                    break;
                case GAME_STATE_DRAW:
                    Game::menu(DRAW);
                default:
                    break;
                }
                break;
            case WIN:
                cout << "\t\t\t\t\t\t" << getName(player) << " Wins!\n";
                switch (isEven(player)){
                case 1:
                    score1++;
                    break;
                case 2:
                    score2++;
                default:
                    break;
                }
                system("pause");
                Game::menu(RESTART);
                break;
            case DRAW:
                cout << "\t\t\t\t\t\tGame is a Draw!\n";
                system("pause");
                Game::menu(RESTART);
                break;
            case RESTART:
                refresh(RESTART_MENU);
                arrow = getch();
                do{
                    switch (arrow){
                    case KEY_ESC:
                        exitProgram();
                    default:
                        arrow = getch();
                        switch (arrow){
                        case KEY_UP:
                            refresh(RESTART_MENU_RESTART_SELECTED);
                            selector = 'R';
                            break;
                        case KEY_DOWN:
                            refresh(RESTART_MENU_EXIT_SELECTED);
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
                    initGame();
                    Game::menu(VS);
                    break;
                case 'E':
                    exitProgram();
                default:
                    break;
                }
                break;
            default:
                cout << "\nMissing Screen\n";
                break;
            }
        }
    private:
        static void clear(){
            system("CLS");
        }
        static void print(string str){
            cout << str;
        }
        static void refresh(string str){
            clear();
            print(str);
        }
        static void printBoard(){
            cout << player1 << " (X) Score [" << score1 << "]  -  " << player2 << " (O) Score [" << score2 << "]" << endl << endl
                 << "\t\t\t\t\t\tTurn: " << getName(player) << endl << endl
                 << "\t\t\t\t\t\t     |     |     " << endl
                 << "\t\t\t\t\t\t  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl
                 << "\t\t\t\t\t\t_____|_____|_____" << endl
                 << "\t\t\t\t\t\t     |     |     " << endl
                 << "\t\t\t\t\t\t  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl
                 << "\t\t\t\t\t\t_____|_____|_____" << endl
                 << "\t\t\t\t\t\t     |     |     " << endl
                 << "\t\t\t\t\t\t  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl
                 << "\t\t\t\t\t\t     |     |     " << endl << endl;
        }
        static void removeSelector() {
            for (int i = 0; i < 9; i++)
                if (board[i] == '^')
                    board[i] = ' ';
        }
        static void clearBoard() {
            for (int i = 0; i < 9; i++)
                board[i] = ' ';
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
        static void MoveUp(){
            selector -= 3;
            selector = selector <= 0 ? selector + 9 : selector;
            if (board[selector - 1] == 'X' || board[selector - 1] == 'O')
                MoveUp();
            else{
                removeSelector();
                board[selector - 1] = '^';
                refresh(LOGO);
                printBoard();
            }
        }
        static void MoveDown(){
            selector += 3;
            selector = selector > 9 ? selector - 9 : selector;
            if (board[selector - 1] == 'X' || board[selector - 1] == 'O')
                MoveDown();
            else{
                removeSelector();
                board[selector - 1] = '^';
                refresh(LOGO);
                printBoard();
            }
        }
        static void MoveLeft(){
            selector -= 1;
            selector = selector <= 0 ? selector + 9 : selector;
            if (board[selector - 1] == 'X' || board[selector - 1] == 'O')
                MoveLeft();
            else{
                removeSelector();
                board[selector - 1] = '^';
                refresh(LOGO);
                printBoard();
            }
        }
        static void MoveRight(){
            selector += 1;
            selector = selector > 9 ? selector - 9 : selector;
            if (board[selector - 1] == 'X' || board[selector - 1] == 'O')
                MoveRight();
            else{
                removeSelector();
                board[selector - 1] = '^';
                refresh(LOGO);
                printBoard();
            }
        }
        static string getName(int player){
            return isEven(player) == 1 ? player1 : player2;
        }
};

void initProgram(){
    Game::initDisplay();
    Game::initGame();
    Game::menu(START);
}

int main(){
    initProgram();
    system("pause");
    exitProgram();
}