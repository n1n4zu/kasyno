#include "Croupier.h"
#include "Players.h"
#include "Player.h"
#include "../functions/functions.h"
#include "../functions/poker.h"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

Croupier::Croupier(const string& name) : Players(name) {
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

void Croupier::checkTable(const vector<Card>& table) const {
    map<string, int> colorsDict;
    colorsDict["Karo"] = 1;
    colorsDict["Trefl"] = 2;
    colorsDict["Pik"] = 3;
    colorsDict["Kier"] = 4;

    vector<int> colors;

    for (int i = 0; i < table.size(); i++) colors.push_back(colorsDict[table[i].color]);

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

    for (int i = 0; i < table.size(); i++) values.push_back(valuesDict[table[i].value]);

    sort(values.begin(), values.end());

    switch (values.size()) {
        case 2:
            if (repeated(values, 2)) cout << "(Para)" << endl;
            else cout << "(Wysoka karta)" << endl;
        break;
        case 3:
            if (repeated(values, 3)) cout << "(Trójka)" << endl;
            else if (repeated(values, 2)) cout << "(Para)" << endl;
            else cout << "(Wysoka karta)" << endl;
        break;
        case 4:
            if (repeated(values, 4)) cout << "(Kareta)" << endl;
            else if (repeated(values, 3)) cout << "(Trójka)" << endl;
            else if (repeatedPairs(values, 2)) cout << "(Dwie pary)" << endl;
            else if (repeated(values, 2)) cout << "(Para)" << endl;
            else cout << "(Wysoka karta)" << endl;
        break;
        case 5:
            if (isRoyalFlush(values, colors)) cout << "(Poker królewski) " << endl;
            else if (isStraightFlush(values, colors)) cout << "(Poker)" << endl;
            else if (repeated(values, 4)) cout << "(Kareta)" << endl;
            else if (isFull(values)) cout << "(Ful)" << endl;
            else if (repeated(colors, 5)) cout << "(Kolor)" << endl;
            else if (isStraight(values)) cout << "(Strit)" << endl;
            else if (repeated(values, 3)) cout << "(Trójka)" << endl;
            else if (repeatedPairs(values, 2)) cout << "(Dwie pary)" << endl;
            else if (repeated(values, 2)) cout << "(Para)" << endl;
            else cout << "(Wysoka karta)" << endl;
        break;
        default:
            cout << "(Wysoka karta)" << endl;
            break;
    }

    colors.clear();
    values.clear();
}
