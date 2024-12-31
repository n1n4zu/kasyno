#include "Croupier.h"
#include "Players.h"
#include "Player.h"
#include "../functions/functions.h"
#include "../functions/poker.h"
#include <iostream>
#include <map>
#include <algorithm>

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
    if (usedIndexes.size() == 52) {
        throw runtime_error("Brak kart w talii!");
    }

    int index;
    do {
        index = randomize(0, 51);
    } while (usedIndexes.find(index) != usedIndexes.end());

    player.deck.push_back(talia[index]);
    usedIndexes.insert(index);
}


void Croupier::whoWinsBaccarat(Croupier player1, Player player2) {
    if (9 - player1.points < 9 - player2.points) cout << "Wygrał gracz " << player1.name << endl;
    else if (9 - player1.points > 9 - player2.points) cout << "Wygrał gracz " << player2.name << endl;
    else if (9 - player1.points ==  9 - player2.points) {
        if (player1.deck.size() == player2.deck.size()) cout << "Remis" << endl;
        else if (player1.deck.size() < player2.deck.size()) cout << "Wygrał gracz " << player1.name << endl;
        else cout << "Wygrał gracz " << player2.name << endl;
    }
}

void Croupier::whoWinsBlackjack(Croupier croupier, Player player) {
        if (player.points <= 21 && (player.points > croupier.points || croupier.points > 21)) {
            cout << "Wygrał gracz " << player.name << endl;
            player.setCash(player.getCash() + player.getBet() * 2);
        } else if (croupier.points <= 21 && (croupier.points > player.points || player.points > 21)) cout << "Wygrał gracz " << croupier.name << endl;
        else if (croupier.points > 21 && player.points > 21) {
            cout << "Nikt nie wygrał" << endl;
            player.setCash(player.getCash() + player.getBet());
        } else if (croupier.points ==  player.points) {
            cout << "Remis" << endl;
            player.setCash(player.getCash() + player.getBet());
        }
}

bool Croupier::checkBlackjack(Players player) {
    if (player.points == 21 && player.deck.size() == 2) return true;
    return false;
}

void Croupier::putCardOnTable(const array<Card, 52>& talia, vector<Card>& table) {
    while (true) {
        int index = randomize(0, 51);
        if (usedIndexes.find(index) == usedIndexes.end()) {
            table.push_back(talia[index]);
            usedIndexes.insert(index);
            break;
        }
    }
}

void Croupier::displayTable(const vector<Card>& table) const {
    cout << "Karty na stole:" << endl;
    for (const auto& card : table) cout << card.value << " " << card.color << endl;
}

void Croupier::whoWinsPoker(vector<Players*> line, vector<Card>& table) {
    vector<string> winners;
    int bestHand = 0;

    for (auto * player : line) {
        vector<Card> combinedCards = player->deck;
        combinedCards.insert(combinedCards.end(), table.begin(), table.end());

        string hand = player->checkCards(table);
        int handValue = getHandValue(hand, combinedCards);

        if (handValue > bestHand) {
            bestHand = handValue;
            winners = {player->name}; // Resetuj listę zwycięzców
        } else if (handValue == bestHand) {
            winners.push_back(player->name); // Dodaj gracza do listy zwycięzców
        }

    }

    cout << "Wygrał gracz: ";
    for (const auto& winner : winners) {
        cout << winner << " ";
    }
    cout << endl;
}
