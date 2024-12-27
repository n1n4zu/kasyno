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

        croupier.addCard(deck, player, 13);
        player.displayHand(table);
        sleep();
        clear();

        croupier.addCard(deck, player, 1);
        player.displayHand(table);
        sleep();
        clear();

        croupier.putCardOnTable(deck, table, 2);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand(table);
        sleep();
        clear();

        croupier.putCardOnTable(deck, table, 3);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand(table);
        sleep();
        clear();

        croupier.putCardOnTable(deck, table, 4);
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

        croupier.putCardOnTable(deck, table, 38);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand(table);
//        sleep();
//        clear();

        break;
    }
}
