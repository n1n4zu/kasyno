#ifndef PLAYER_H
#define PLAYER_H
#include "Players.h"

class Player : public Players{
    double cash = 500;
    public:
    Player(std::string name) : Players(name) {
        this->name = name;
    }


};

#endif //PLAYER_H
