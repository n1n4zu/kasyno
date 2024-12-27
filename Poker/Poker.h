#ifndef POCKER_H
#define POCKER_H
#include "../Players/Croupier.h"
#include "../Players/Player.h"
#include "../Players/Bot.h"
;

class Poker {
    Player& player;
    Croupier& croupier;
    Bot& bob;
    Bot& john;
    Bot& tim;

public:
    Poker(Player& player, Croupier& croupier, Bot& bob, Bot& john, Bot& tim) : player(player), croupier(croupier), bob(bob), john(john), tim(tim) {}
    void play() const;
};



#endif
