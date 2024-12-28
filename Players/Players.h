#ifndef PLAYERS_H
#define PLAYERS_H
#include <string>
#include <vector>
#include <iostream>
#include "../deck/deck.h"

using namespace std;

class Players {
    double bet = 0;
    bool isFold = false;
    bool isCheck = false;
    bool isAllIn = false;

public:
    string name;
    int points;
    vector<Card> deck;
    Players(string name);

    bool operator==(const Players& other) const;

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

    // Pobiera wartość czy gracz spasował
    bool getFold() const;

    // Pobiera wartość czy gracz czeka
    bool getCheck() const;

    // Pobiera wartość czy gracz gra va banque
    bool getAllIn() const;

    // Ustawia czy gracz spasował
    void setFold(bool fold);

    // Ustawia czy gracz czeka
    void setCheck(bool check);

    // Ustawia czy gracz gra va banque
    void setAllIn(bool allIn);

    // Pobiera wartość zakładu
    double getBet();

    // Ustawia wartość zakładu
    void setBet(double money);
};

#endif //PLAYERS_H
