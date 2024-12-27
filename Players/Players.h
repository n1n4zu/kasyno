#ifndef PLAYERS_H
#define PLAYERS_H
#include <string>
#include <vector>
#include <iostream>
#include "../deck/deck.h"

using namespace std;

class Players {
    public:
    string name;
    int points;
    vector<Card> deck;
    Players(const string& name);

    // Wyświetla karty w ręce gracza
    void displayDeck() const;

    // Podlicza punkty kart w ręce gracza w grze Bakarat
    void countPointsBaccarat();

    // Podlicza punkty kart w ręce gracza w grze Blackjack
    void countPointsBlackjack();

    // Wyświetla karty w ręce gracza
    void displayHand(const vector<Card>& table) const;

    // Sprawdza karty w ręce i na stole
    void checkCards(const vector<Card>& table) const;
};

#endif //PLAYERS_H
