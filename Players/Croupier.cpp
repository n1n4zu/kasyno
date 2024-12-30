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
    string winner;

    map<string, int> suitsDict;
    suitsDict["Wysoka karta"] = 1;
    suitsDict["Para"] = 2;
    suitsDict["Dwie pary"] = 3;
    suitsDict["Trójka"] = 4;
    suitsDict["Strit"] = 5;
    suitsDict["Kolor"] = 6;
    suitsDict["Ful"] = 7;
    suitsDict["Kareta"] = 8;
    suitsDict["Poker"] = 9;
    suitsDict["Poker królewski"] = 10;

    map<string, int> playersDict;

    for (auto * i : line) {
        map<string, int> colorsDict;
        colorsDict["Karo"] = 1;
        colorsDict["Trefl"] = 2;
        colorsDict["Pik"] = 3;
        colorsDict["Kier"] = 4;

        vector<int> colors;

        for (const auto & j : i->deck) colors.push_back(colorsDict[j.color]);

        sort(colors.begin(), colors.end());

        map<string, int> valuesDict;
        valuesDict["2"] = 2;
        valuesDict["3"] = 3;
        valuesDict["4"] = 4;
        valuesDict["5"] = 5;
        valuesDict["6"] = 6;
        valuesDict["7"] = 7;
        valuesDict["8"] = 8;
        valuesDict["9"] = 9;
        valuesDict["10"] = 10;
        valuesDict["Walet"] = 11;
        valuesDict["Dama"] = 12;
        valuesDict["Król"] = 13;
        valuesDict["As"] = 14;

        vector<int> values;

        for (const auto & j : i->deck) values.push_back(valuesDict[j.color]);

        sort(values.begin(), values.end());

        playersDict[i->name] = suitsDict[i->checkCards(table)];
    }


}
