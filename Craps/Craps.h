#include "../functions/functions.h"
#include "../Players/Player.h"

using namespace std;

#ifndef CRAPS_H
#define CRAPS_H

class Craps {

    // Losowanie wartości kości
    int roll1 = randomize(1, 6);
    int roll2 = randomize(1, 6);
    int guess1, guess2;
    void reset();
    Player player;
public:
    Craps(Player& player) : player(player) {}
    void play();
};

#endif //CRAPS_H
