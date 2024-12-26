#ifndef POCKER_H
#define POCKER_H
#include "../Players/Croupier.h"
#include "../Players/Player.h"


class Poker {
    Player& player;
    Croupier& croupier;
    Player& player2;

public:
    Poker(Player& player, Croupier& croupier, Player& player2) : player(player), croupier(croupier), player2(player2) {}
    void play() const;
};



#endif
