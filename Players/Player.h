#ifndef PLAYER_H
#define PLAYER_H
#include "Players.h"

using namespace std;

class Player : public Players {
    double cash = 500;
    bool insurance = false;
    double insuranceValue = 0;
    bool isFold = false;
    bool isCheck = false;
    bool isAllIn = false;
    double bet = 0; // Dodanie zmiennej przechowującej aktualny zakład

public:
    Player(string name);

    double getCash();
    void setCash(double money);

    bool getInsurance();
    void setInsurance(bool value);

    double getInsuranceValue();
    void setInsuranceValue(double value);

    double getBet() const; // Dodanie funkcji zwracającej aktualny zakład
    void setBet(double bet); // Dodanie funkcji ustawiającej zakład

    void placeBet(double amount); // Dodanie funkcji do składania zakładu
    void winBet(double multiplier); // Dodanie funkcji do wygrywania zakładu

    string getName() const;
};

#endif