#ifndef PLAYER_H
#define PLAYER_H
#include "Players.h"

using namespace std;

class Player : public Players{
    double cash = 500;
    bool insurance = false;
    double insuranceValue = 0;
    double bet = 0;
    bool isFold = false;
    bool isCheck = false;
    bool isAllIn = false;

public:
    explicit Player(string name);

    double getCash();
    void setCash(double money);

    bool getInsurance();
    void setInsurance(bool value);

    double getInsuranceValue();
    void setInsuranceValue(double value);

    double getBet();
    void setBet(double money);
};

#endif
