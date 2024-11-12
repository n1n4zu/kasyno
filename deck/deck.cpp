#include "deck.h"

void displayDeck(const array<Card, 52>& deck) {
    for (const auto& card : deck) {
        cout << card.value << " " << card.color << endl;
    }
}

void displayCard(const Card& card) {
    cout << card.value << " " << card.color << endl;
}

string colors[4] = {"Kier", "Karo", "Trefl", "Pik"};
string values[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Walet", "Dama", "Król", "As"};