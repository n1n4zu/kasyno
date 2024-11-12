#ifndef PLAYER_H
#define PLAYER_H
#include "Players.h"
#include <string>

using namespace std;

class Player : public Players{
    double cash = 500;
    bool insurance;
    double bet;

public:
    Player(string name);

    double getCash();
    void setCash(double money);

    bool getInsurance();
    void setInsurance(bool value);

    double getBet();
    void setBet(double money);
};

#endif //PLAYER_H
