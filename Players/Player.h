#ifndef PLAYER_H
#define PLAYER_H
#include "Players.h"
#include <string>

using namespace std;

class Player : public Players{
    double cash = 500;
    public:
    Player(string name);


};

#endif //PLAYER_H
