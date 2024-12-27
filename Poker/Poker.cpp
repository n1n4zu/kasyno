#include "Poker.h"
#include <iostream>
#include "../functions/functions.h"
#include <string>
#include <array>
#include <vector>

using namespace std;

void Poker::play() const {
    string option;
    array<Card, 52> deck;
    int index = 0;
    vector<Card> table;

    for (const auto& color : colors) {
        for (const auto& value : values) {
            deck[index].color = color;
            deck[index].value = value;
            index++;
        }
    }

    while (true) {
        // sleep();

        croupier.addCard(deck, player, 11);
        player.displayHand(table);
        sleep();
        clear();

        croupier.addCard(deck, player, 10);
        player.displayHand(table);
        sleep();
        clear();

        croupier.putCardOnTable(deck, table, 9);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand(table);
        sleep();
        clear();

        croupier.putCardOnTable(deck, table, 8);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand(table);
        sleep();
        clear();

        croupier.putCardOnTable(deck, table, 7);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand(table);
        sleep();
        clear();

        croupier.putCardOnTable(deck, table, 20);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand(table);
        sleep();
        clear();

        croupier.putCardOnTable(deck, table, 39);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand(table);
//        sleep();
//        clear();

        break;
    }
}
