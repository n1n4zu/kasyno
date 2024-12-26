#include "Croupier.h"
#include "Players.h"
#include "Player.h"
#include "../functions/functions.h"
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

void Croupier::putCardOnTable(const array<Card, 52>& talia, vector<Card>& table, int licznik) {
    while (true) {
        int index = randomize(0, 51);
        if (usedIndexes.find(index) == usedIndexes.end()) {
            table.push_back(talia[licznik]);
            usedIndexes.insert(index);
            break;
        }
    }
}

void Croupier::displayTable(const vector<Card>& table) const {
    cout << "Karty na stole: ";
    checkTable(table);
    for (const auto& card : table) {
        cout << card.value << " " << card.color << endl;
    }
}

void Croupier::checkTable(const vector<Card>& table) const {
    map<string, int> colorsDict;
    colorsDict["Karo"] = 1;
    colorsDict["Trefl"] = 2;
    colorsDict["Pik"] = 3;
    colorsDict["Kier"] = 4;

    vector<int> colors;

    for (int i = 0; i < table.size(); i++) {
        colors.push_back(colorsDict[table[i].color]);
    }

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

    for (int i = 0; i < table.size(); i++) {
        values.push_back(valuesDict[table[i].value]);
    }

    sort(values.begin(), values.end());

    switch (table.size()) {
        case 2:
            if (values[0] == values[1])
                cout << "(Para)" << endl;
            else cout << endl;
            break;
        case 3:
            if (values[0] == values[1] == values[2])
                cout << "(Trójka)" << endl;
            else if (values[0] == values[1])
                        cout << "(Para)" << endl;
            else cout << endl;
            break;
        case 4:
            if (values[0] == values[1] == values[2] == values[3])
                    cout << "(Kareta)" << endl;
            else if (values[0] == values[1] == values[2])
                cout << "(Trójka)" << endl;
            else if (values[0] == values[1] &&
                     values[2] == values[3])
                        cout << "(Dwie pary)" << endl;
            else if (values[0] == values[1])
                        cout << "(Para)" << endl;
            else cout << endl;
            break;
        case 5:
            if (colors[0] == colors[1] &&
                colors[1] == colors[2] &&
                colors[2] == colors[3] &&
                colors[3] == colors[4] &&
                values[0] + 1 == values[1] &&
                values[1] + 1 == values[2] &&
                values[2] + 1 == values[3] &&
                values[3] + 1 == values[4] &&
                values[4] == 14)
                    cout << "(Poker królewski) " << endl;
            else if (colors[0] == colors[1] &&
                     colors[1] == colors[2] &&
                     colors[2] == colors[3] &&
                     colors[3] == colors[4] &&
                     values[0] + 1 == values[1] &&
                     values[1] + 1 == values[2] &&
                     values[2] + 1 == values[3] &&
                     values[3] + 1 == values[4])
                        cout << "(Poker)" << endl;
            else if (values[0] == values[1] == values[2] == values[3])
                        cout << "(Kareta)" << endl;
            else if (values[0] == values[1] == values[2] &&
                     values[3] == values[4])
                        cout << "(Ful)" << endl;
            break;
        default:
            cout << endl;
            break;
    }
}
