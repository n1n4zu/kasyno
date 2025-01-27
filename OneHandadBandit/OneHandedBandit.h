#ifndef ONEHANDEDBANDIT_H
#define ONEHANDEDBANDIT_H
#include "../functions/functions.h"
#include "../Players/Player.h"

using namespace std;

class OneHandedBandit {
    // Losowanie wartości na automacie
    mutable int var1 = randomize(1, 5);
    mutable int var2 = randomize(1, 5);
    mutable int var3 = randomize(1, 5);
    mutable Player player;

    void reset() const;

public:
    OneHandedBandit(Player& player) : player(player){}
    void play() const;
};



#endif //ONEHANDEDBANDIT_H
