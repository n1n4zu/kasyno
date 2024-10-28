#ifndef CROUPIER_H
#define CROUPIER_H
#include "deck.h"
#include "Players.h"
#include "functions.h"
#include <set>
#include "Player.h"
using namespace std;

class Croupier : public Players {
    int tableIndex = 0;
    set<int> usedIndexes;
    public:
    Croupier(string name) : Players(name) {
        this->name = name;
    }

    void giveCardsBaccarat(const array<Karta, 52>& talia, Players& player) {
        while (player.deck.size() < 2) {
            int index = randomize(0, 51);
            if (usedIndexes.find(index) == usedIndexes.end()) {
                player.deck.push_back(talia[index]); // Dodajemy losową kartę z `talia`
                usedIndexes.insert(index);    // Dodajemy indeks do zbioru użytych
            }
        }
    }

    void addBaccaratCard(const array<Karta, 52>& talia, Players& player) {
        int index = randomize(0, 51);
        if (usedIndexes.find(index) == usedIndexes.end()) {
            player.deck.push_back(talia[index]); // Dodajemy losową kartę z `talia`
            usedIndexes.insert(index);    // Dodajemy indeks do zbioru użytych
        }
    }

    void whoWins(Croupier player1, Player player2) {
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
};

#endif //CROUPIER_H
