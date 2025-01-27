#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "../Players/Croupier.h"
#include "../Players/Player.h"


class Blackjack {
    Player& player;
    Croupier& croupier;
    void reset() const;

    public:
    Blackjack(Player& player, Croupier& croupier) : player(player), croupier(croupier) {}
    void play() const;
};



#endif //BLACKJACK_H
