#ifndef PLAYERDATA_HPP
#define PLAYERDATA_HPP

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

#endif