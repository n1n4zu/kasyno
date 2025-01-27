#ifndef BACCARAT_H
#define BACCARAT_H
#include "../Players/Croupier.h"
#include "../Players/Player.h"

using namespace std;

class Baccarat {
    Player& player;
    Croupier& croupier;
    void reset();

    public:
    Baccarat(Player& player, Croupier& croupier) : player(player), croupier(croupier) {};
    void play();
};

#endif //BACCARAT_H
