#include "Player.h"
#include "Players.h"
#include <string>

using namespace std;

Player::Player(string name) : Players(name) {
    this->name = name;
}

double Player::getCash(){
    return cash;
}

void Player::setCash(double money) {
    this->cash = money;
}

bool Player::getInsurance() {
    return insurance;
}

void Player::setInsurance(bool value) {
    this->insurance = value;
}

double Player::getInsuranceValue() {
    return insuranceValue;
}

void Player::setInsuranceValue(double value) {
    insuranceValue = value;
}