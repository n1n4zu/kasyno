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

    vector<Players> line = {player, bob, john, tim};

    while (true) {
        // sleep();

        for (int i =0 ; i < 2; i++) {
            croupier.addCard(deck, player);
            player.displayHand(table);
            sleep();
            clear();
        }



        croupier.putCardOnTable(deck, table);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand(table);
        sleep();
        clear();

        break;
    }
}
