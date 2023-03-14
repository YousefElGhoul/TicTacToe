#include <iostream>

using namespace std;

void playerNames();
void gamePlay();
void clearBoard();
void clearScore();
void printGame();
int checkCurrentPlayerNumber(int);
string checkCurrentPlayerName();
void turnPlay();
int play(int,int);
void logicCheck();
int logic();
void restartPrompt();

char table[3][3];
int score[2] = { 0, 0 };
int player = 1;
string player1 = "Player 1", player2 = "Player 2";
bool state = false;

int main(){
    int selector;
    system("color a");
    system("CLS");
    clearScore();
    player = 1;
    state = false;
    cout    << "\t\t\t\t\t\t"
            << "TICKTACTOE"
            << "\n1.Start"
            << "\n2.Exit\n\n";
    cin >> selector;
    if (selector == 1) {
        playerNames();
        gamePlay();
    }
    else
    if (selector == 2)
        exit;
    else
    if (selector != 1 || selector != 2){
        cout << "Please enter a valid menu number!\n";
        system("pause");
        main();
    }
}
void playerNames() {
    int selector;
    system("CLS");
    cout    << "\t\t\t\t\t\t"
            << "TICKTACTOE\n"
            << "Do you want to skip Player Names?\n\n1.Yes\n2.No\n\n";
    cin >> selector;
    if (selector == 1){
        return;
    } else
    if (selector == 2) {
        system("CLS");
        cout << "Player 1: \n\n";
        cin >> player1;
        system("CLS");
        cout << "Player 2: \n\n";
        cin >> player2;
    }
    if (selector != 1 && selector != 2) {
        cout << "Please enter a valid menu number!\n";
        system("pause");
        playerNames();
    }
}
void gamePlay() {
    if (state == false) {
        state = true;
        clearBoard();
    }
    printGame();
    turnPlay();
    logicCheck();
    gamePlay();
}
void clearBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            table[i][j] = ' ';
}
void clearScore() {
    for (int i = 0; i < 2; i++){
        score[i] = 0;
    }
}
void printGame() {
    system("CLS");
    cout    << "\t\t\t\t\t\t"
            << "TICKTACTOE\n"
            << "Turn: "
            << checkCurrentPlayerName()
            << "\n\nScore:"
            << " " << player1 << " = " << score[0]
            << " " << player2 << " = " << score[1] << "\n"
            << "\t\t\t\t\t\t" << "  1  2  3\n";
    for (int i = 0; i < 3; i++){
        cout << "\t\t\t\t\t\t" << i + 1;
        for (int j = 0; j < 3; j++)
            cout << '[' << table[i][j] << ']';
        cout << endl;
    }
}
int checkCurrentPlayerNumber(int x) {
    if (x % 2 == 0)
        return 2;
    else
        return 1;
}
string checkCurrentPlayerName() {
    if (checkCurrentPlayerNumber(player) == 2)
        return player2;
    else
        return player1;
}
void turnPlay() {
    int row, col;
    cout << "Enter the Row and Column you want to change: \n";
    cin >> row >> col;
    if (play(row, col) == 2)
        player++;
    else
    if (play(row, col) == 0) {
        cout << "\nThis place is already taken\n";
        system("pause");
    }
    else{
        cout << "\nUnexpected Error\n";
        system("pause");
    }
}
int play(int r,int c) {
    if (table[r - 1][c - 1] == 'O' || table[r - 1][c - 1] == 'X')
        return 0;
    if (checkCurrentPlayerNumber(player) == 1) {
        if (table[r - 1][c - 1] == ' '){
            table[r - 1][c - 1] = 'X';
            return 2;
        }
        else return 1;
    }
    if (checkCurrentPlayerNumber(player) == 2) {
        if (table[r - 1][c - 1] == ' ') {
            table[r - 1][c - 1] = 'O';
            return 2;
        }
        else return 1;
    }
    return 1;
}
    void logicCheck() {
        if (logic() == 1) {
            score[0]++;
            player = 2;
            printGame();
            cout << player1 << " Wins!\n";
            state = false;
            system("pause");
            restartPrompt();
            return;
        }
        if (logic() == 2) {
            score[1]++;
            player = 1;
            printGame();
            cout << player2 <<" Wins!\n";
            state = false;
            system("pause");
            restartPrompt();
            return;
        }
        if (logic() == 3) {
            cout << "DRAW!\n";
            state = false;
            system("pause");
            restartPrompt();
            return;
        }
}

int logic() {
    if ((table[2][0] == 'X' && table[2][1] == 'X') && table[2][2] == 'X')
        return 1;
    else
    if ((table[2][0] == 'O' && table[2][1] == 'O') && table[2][2] == 'O')
        return 2;
    else
    if ((table[0][2] == 'X' && table[1][2] == 'X') && table[2][2] == 'X')
        return 1;
    else
    if ((table[0][2] == 'O' && table[1][2] == 'O') && table[2][2] == 'O')
        return 2;
    else
    if ((table[1][0] == 'X' && table[1][1] == 'X') && table[1][2] == 'X')
        return 1;
    else
    if ((table[1][0] == 'O' && table[1][1] == 'O') && table[1][2] == 'O')
        return 2;
    else
    if ((table[0][1] == 'X' && table[1][1] == 'X') && table[2][1] == 'X')
        return 1;
    else
    if ((table[0][1] == 'O' && table[1][1] == 'O') && table[2][1] == 'O')
        return 2;
    else
    if ((table[0][0] == 'X' && table[0][1] == 'X') && table[0][2] == 'X')
        return 1;
    else
    if ((table[0][0] == 'O' && table[0][1] == 'O') && table[0][2] == 'O')
        return 2;
    else
    if ((table[0][0] == 'X' && table[1][0] == 'X') && table[2][0] == 'X')
        return 1;
    else
    if ((table[0][0] == 'O' && table[1][0] == 'O') && table[2][0] == 'O')
        return 2;
    else
    if ((table[0][2] == 'X' && table[1][1] == 'X') && table[2][0] == 'X')
        return 1;
    else
    if ((table[0][2] == 'O' && table[1][1] == 'O') && table[2][0] == 'O')
        return 2;
    else
    if ((table[0][0] == 'X' && table[1][1] == 'X') && table[2][2] == 'X')
        return 1;
    else
    if ((table[0][0] == 'O' && table[1][1] == 'O') && table[2][2] == 'O')
        return 2;
    if ((((table[0][0] != ' ' && table[0][1] != ' ') && (table[0][2] != ' ' && table[1][0] != ' ')) && (table[1][1] != ' ' && table[1][2] != ' ') && (table[2][0] != ' ' && table[2][1] != ' ')) && table[2][2] != ' ') {
        return 3;
    }
    return 0;
}

void restartPrompt() {
    if (state == false) {
        cout << "\nTo Exit the Game Close this Window . . .\nTo Restart the Game ";
        system("pause");
    }
    return;
 }
