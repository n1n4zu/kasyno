#include <string>
#include <array>
#include <iostream>

using namespace std;

#ifndef DECK_H
#define DECK_H

// Struktura talii
struct Card {
    string color;
    string value;
};

void displayDeck(const array<Card, 52>& deck);

void displayCard(const Card& card);

extern string colors[4];
extern string values[13];

#endif //DECK_H
