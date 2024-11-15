#ifndef CROUPIER_H
#define CROUPIER_H
#include "../deck/deck.h"
#include "Players.h"
#include <set>
#include "Player.h"

using namespace std;

class Croupier : public Players {
    int tableIndex = 0;
    set<int> usedIndexes;
public:
    Croupier(string name);

    // Daje na start 2 karty do ręki gracza
    void giveCards(const array<Card, 52>& talia, Players& player);

    // Dodaje kartę do ręki gracza
    void addCard(const array<Card, 52>& talia, Players& player);

    // Sprawdza kto wygrał partię bakarat
    void whoWinsBaccarat(Croupier player1, Player player2);

    // Sprawdza kto wygrał partię Balckjack
    void whoWinsBlackjack(Croupier player1, Player player2);

    // Sprawdza, czy gracz ma Blackjack'a
    bool checkBlackjack(Players player);
};

#endif //CROUPIER_H
