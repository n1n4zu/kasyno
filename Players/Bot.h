#ifndef BOT_H
#define BOT_H
#include "Players.h"
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
    bool isWorth(vector<int>& values, vector<int>& colors) const;

    // Strategia gry bota
    string strategy(const vector<Card>& table);
};

#endif //BOT_H
