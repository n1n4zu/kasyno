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
    switch (table.size()) {
        case 2:
            if (table[0].value == table[1].value)
                cout << "(Para)" << endl;
            else cout << endl;
            break;
        case 3:
            if (table[0].value == table[1].value && table[1].value == table[2].value)
                cout << "(Trójka)" << endl;
            else if (table[0].value == table[1].value ||
                table[0].value == table[2].value ||
                table[1].value == table[2].value)
                    cout << "(Para)" << endl;
        else cout << endl;
            break;
        case 4:
            if (table[0].value == table[1].value && table[1].value == table[2].value ||
                table[0].value == table[1].value && table[1].value == table[3]. value ||
                table[0].value == table[2].value && table[2].value == table[3]. value)
                    cout << "(Trójka)" << endl;
            else if (table[0].value == table[1].value && table[2].value == table[3].value ||
                     table[0].value == table[2].value && table[2].value == table[3].value)
                        cout << "(Dwie pary)" << endl;
            else if (table[0].value == table[1].value ||
                     table[0].value == table[2].value ||
                     table[0].value == table[3].value ||
                     table[1].value == table[2].value ||
                     table[1].value == table[3].value ||
                     table[2].value == table[3].value)
                        cout << "(Para)" << endl;
            else cout << endl;
            break;
        case 5:
            if (table[0].color == table[1].color &&
                table[1].color == table[2].color &&
                table[2].color == table[3].color &&
                table[3].color == table[4].color &&
                (table[0].value == "10" ||
                 table[1].value == "10" ||
                 table[2].value == "10" ||
                 table[3].value == "10" ||
                 table[4].value == "10") &&
                (table[0].value == "Walet" ||
                 table[1].value == "Walet" ||
                 table[2].value == "Walet" ||
                 table[3].value == "Walet" ||
                 table[4].value == "Walet") &&
                (table[0].value == "Dama" ||
                 table[1].value == "Dama" ||
                 table[2].value == "Dama" ||
                 table[3].value == "Dama" ||
                 table[4].value == "Dama") &&
                (table[0].value == "Król" ||
                 table[1].value == "Król" ||
                 table[2].value == "Król" ||
                 table[3].value == "Król" ||
                 table[4].value == "Król") &&
                (table[0].value == "As" ||
                 table[1].value == "As" ||
                 table[2].value == "As" ||
                 table[3].value == "As" ||
                 table[4].value == "As"))
                    cout << "(Poker królewski)" << endl;
        else if (table[0].color == table[1].color &&
                 table[1].color == table[2].color &&
                 table[2].color == table[3].color &&
                 table[3].color == table[4].color)
                    cout << "Poker" << endl;
        break;
        default:
            cout << endl;
            break;
    }
}
