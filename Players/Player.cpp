#include "Player.h"
#include "Players.h"
#include <string>

using namespace std;

Player::Player(string name) : Players(name) {
    this->name = name;
}

double Player::getCash() {
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

double Player::getBet() const {
    return bet;
}

void Player::setBet(double bet) {
    this->bet = bet;
}

void Player::placeBet(double amount) {
    if (amount > cash) {
        cout << "Nie masz wystarczająco gotówki!" << endl;
        return;
    }
    cash -= amount;
    bet = amount;
    cout << "Postawiłeś zakład w wysokości: " << amount << endl;
}

void Player::winBet(double multiplier) {
    double winnings = bet * multiplier;
    cash += winnings;
    cout << "Wygrałeś: " << winnings << "! Twoja gotówka: " << cash << endl;
    bet = 0; // Resetowanie zakładu po wygranej
}

string Player::getName() const {
    return name;
}