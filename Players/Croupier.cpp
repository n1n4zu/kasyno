#include "Croupier.h"
#include "Players.h"
#include "Player.h"
#include "../functions/functions.h"
#include <iostream>

using namespace std;

Croupier::Croupier(string name) : Players(name) {
    this->name = name;
}

void Croupier::giveCards(const array<Card, 52>& talia, Players& player) {
    while (player.deck.size() < 2) {
        int index = randomize(0, 51);
        if (usedIndexes.find(index) == usedIndexes.end()) {
            player.deck.push_back(talia[index]); // Dodajemy losową kartę z `talia`
            usedIndexes.insert(index);    // Dodajemy indeks do zbioru użytych
        }
    }
}

void Croupier::addCard(const array<Card, 52>& talia, Players& player) {
    int index = randomize(0, 51);
    if (usedIndexes.find(index) == usedIndexes.end()) {
        player.deck.push_back(talia[index]); // Dodajemy losową kartę z `talia`
        usedIndexes.insert(index);    // Dodajemy indeks do zbioru użytych
    }
}

void Croupier::whoWinsBaccarat(Croupier player1, Player player2) {
    if (9 - player1.points < 9 - player2.points) cout << "Wygrał gracz " << player1.name << endl;
    else if (9 - player1.points > 9 - player2.points) cout << "Wygrał gracz " << player2.name << endl;
    else if (9 - player1.points ==  9 - player2.points) {
        if (player1.deck.size() == player2.deck.size()) {
            cout << "Remis" << endl;
        } else if (player1.deck.size() < player2.deck.size()) {
            cout << "Wygrał gracz " << player1.name << endl;
        } else {
            cout << "Wygrał gracz " << player2.name << endl;
        }
    }
}

void Croupier::whoWinsBlackjack(Croupier croupier, Player player) {
        if (player.points <= 21 && (player.points > croupier.points || croupier.points > 21)) cout << "Wygrał gracz " << player.name << endl;
        else if (croupier.points <= 21 && (croupier.points > player.points || player.points > 21)) cout << "Wygrał gracz " << croupier.name << endl;
        else if (croupier.points > 21 && player.points > 21) cout << "Nikt nie wygrał" << endl;
        else if (croupier.points ==  player.points) cout << "Remis" << endl;
}

bool Croupier::checkBlackjack(Players player) {
    if (player.points == 21 && player.deck.size() == 2) return true;
    return false;
}
