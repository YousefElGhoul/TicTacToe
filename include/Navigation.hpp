#ifndef NAVIGATION_HPP
#define NAVIGATION_HPP

class MenuNavigation {
public:
    static void Nav(int button1, int button2);
};

class GameNavigation {
public:
    static void MoveUp();
    static void MoveDown();
    static void MoveLeft();
    static void MoveRight();
    static void removeSelector();
    static void Nav();
};

#endif