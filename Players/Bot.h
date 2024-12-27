#ifndef BOT_H
#define BOT_H
#include "Player.h"
#include "../deck/deck.h"
#include <vector>

using namespace std;

class Bot : public Players {
    double allInChance;
    bool isFold = false;
    bool isCheck = false;
    bool isAllIn = false;
    double money = 500;

public:
    Bot(const string& name, double allInChance);

    // Sprawdza czy warto obstawiać
    bool isWorth(const vector<Card>& table) const;
};

#endif //BOT_H
