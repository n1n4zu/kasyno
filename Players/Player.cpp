#include "Player.h"
#include "Players.h"
#include <string>

using namespace std;

Player::Player(string name) : Players(name) {
    this->name = name;
}