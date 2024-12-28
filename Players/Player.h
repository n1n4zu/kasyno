#ifndef PLAYER_H
#define PLAYER_H
#include "Players.h"

using namespace std;

class Player : public Players{
    double cash = 500;
    bool insurance = false;
    double insuranceValue = 0;
    bool isFold = false;
    bool isCheck = false;
    bool isAllIn = false;
    double bet;

public:
    Player(string name);

    double getCash();
    void setCash(double money);

    bool getInsurance();
    void setInsurance(bool value);

    double getInsuranceValue();
    void setInsuranceValue(double value);
};

#endif
