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

        croupier.putCardOnTable(deck, table, 0);
        croupier.displayTable(table);
        sleep();
        clear();

//        croupier.addCard(deck, player);
//        croupier.displayTable(table);
//        cout << endl;
//        player.displayHand();
//        sleep();
//        clear();

////        croupier.addCard(deck, player2);
//        croupier.displayTable(table);
//        cout << endl;
//        player.displayHand();
//        cout << endl;
////        player2.displayHand();
//        sleep();
//        clear();

        croupier.putCardOnTable(deck, table, 50);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand();
        sleep();
        clear();

//        croupier.addCard(deck, player);
//        croupier.displayTable(table);
//        cout << endl;
//        player.displayHand();
//        sleep();
//        clear();

////        croupier.addCard(deck, player2);
//        croupier.displayTable(table);
//        cout << endl;
//        player.displayHand();
//        cout << endl;
////        player2.displayHand();
//        sleep();
//        clear();

        croupier.putCardOnTable(deck, table, 2);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand();
        sleep();
        clear();

        croupier.putCardOnTable(deck, table, 14);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand();
        sleep();
        clear();

        croupier.putCardOnTable(deck, table, 13);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand();
        //sleep();
//        clear();

        break;
    }
}