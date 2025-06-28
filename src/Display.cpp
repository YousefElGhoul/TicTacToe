#include"../include/Display.hpp"

std::vector<std::string> Display::arr;

void Display::initDisplay(){
    system("color a");
    clear();
}
void Display::refresh(){
    system("CLS");
    for (const auto& line : arr) {
        print(line);
    }
}
void Display::showMenu(int state) {
    clear();
    switch (state)
    {
    case START_MENU:
        addLogo();
        addButton(START_BUTTON_TEXT);
        addButton(EXIT_BUTTON_TEXT);
        break;
    case START_MENU_START_SELECTED:
        addLogo();
        addSelectedButton(START_BUTTON_TEXT);
        addButton(EXIT_BUTTON_TEXT);
        break;
    case START_MENU_EXIT_SELECTED:
        addLogo();
        addButton(START_BUTTON_TEXT);
        addSelectedButton(EXIT_BUTTON_TEXT);
        break;
    case RESTART_MENU:
        addLogo();
        addButton(RESTART_BUTTON_TEXT);
        addButton(EXIT_BUTTON_TEXT);
        break;
    case RESTART_MENU_RESTART_SELECTED:
        addLogo();
        addSelectedButton(RESTART_BUTTON_TEXT);
        addButton(EXIT_BUTTON_TEXT);
        break;
    case RESTART_MENU_EXIT_SELECTED:
        addLogo();
        addButton(RESTART_BUTTON_TEXT);
        addSelectedButton(EXIT_BUTTON_TEXT);
        break;
    default:
        break;
    }
    refresh();
}
void Display::showNameInput(int state) {
    if (state == NAME_INPUT_1) clear();
    switch (state)
    {
    case NAME_INPUT_1:
        addLogo();
        addLine(arr, "Player 1: \n");
        refresh();
        break;
    case NAME_INPUT_2:
        addLine(arr, "Player 2: \n");
        refresh();
        break;
    default:
        break;
    }
}
void Display::showBoard() {
    clear();
    addLogo();
    addBoard();
    refresh();
}
void Display::showScores() {
    clear();
    addLogo();
    addScores();
    refresh();
}

void Display::addLine(std::vector<std::string>& arr, const std::string& newLine) {
    arr.push_back(newLine);
}
void Display::addLogo(){
    addLine(arr, LOGO_1);
    addLine(arr, LOGO_2);
    addLine(arr, LOGO_3);
    addLine(arr, LOGO_4);
    addLine(arr, LOGO_5);
}
void Display::addButton(std::string buttonText) {
    addLine(arr, BUTTON_TEMPLATE_1);
    addLine(arr, BUTTON_TEMPLATE_2);
    addLine(arr, std::format(BUTTON_TEMPLATE_3, buttonText));
    addLine(arr, BUTTON_TEMPLATE_4);
}
void Display::addSelectedButton(std::string buttonText) {
    addLine(arr, SELECTED_BUTTON_TEMPLATE_1);
    addLine(arr, SELECTED_BUTTON_TEMPLATE_2);
    addLine(arr, std::format(SELECTED_BUTTON_TEMPLATE_3, buttonText));
    addLine(arr, SELECTED_BUTTON_TEMPLATE_4);
}
void Display::addBoard(){
    addLine(arr,  std::format("{} (X) Score [{}]  -  {} (O) Score [{}]\n\n", player1->getName(), player1->getScore(), player2->getName(), player2->getScore()));
    addLine(arr,  std::format("\t\t\t\t\t\tTurn: {}\n\n", getCurrentPlayersName(player)));
    addLine(arr,              "\t\t\t\t\t\t     |     |     \n");
    addLine(arr,  std::format("\t\t\t\t\t\t  {}  |  {}  |  {}\n", board[0], board[1], board[2]));
    addLine(arr,              "\t\t\t\t\t\t_____|_____|_____\n");
    addLine(arr,              "\t\t\t\t\t\t     |     |     \n");
    addLine(arr,  std::format("\t\t\t\t\t\t  {}  |  {}  |  {}\n", board[3], board[4], board[5]));
    addLine(arr,              "\t\t\t\t\t\t_____|_____|_____\n");
    addLine(arr,              "\t\t\t\t\t\t     |     |     \n");
    addLine(arr,  std::format("\t\t\t\t\t\t  {}  |  {}  |  {}\n", board[6], board[7], board[8]));
    addLine(arr,              "\t\t\t\t\t\t     |     |     \n");
}
void Display::addScores(){
    for (int i = 0; i < HIGH_SCORE_FILE_ARRAY_SIZE; i++){
        addLine(arr, "\t\t\t                |\n");
        addLine(arr, std::format("\t\t\t    {}\t|       {}\n", High_Scores[i].getName(), High_Scores[i].getScore()));
        if(i != HIGH_SCORE_FILE_ARRAY_SIZE - 1)
            addLine(arr, "\t\t\t________________|________________\n");
        else
            addLine(arr, "\t\t\t                |\n");
    }
}
void Display::clear() { arr.clear(); }
void Display::print(std::string str){std::cout << str;}