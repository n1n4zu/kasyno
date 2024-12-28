#include "Poker.h"
#include <iostream>
#include "../functions/functions.h"
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include "../Players/Bot.h"

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

    for (int i = 0 ; i < 2; i++) {
        for (auto & j : line) {
            if (j.name == player.name) {
                croupier.addCard(deck, player);
                player.displayHand(table);
                cout << "Krupier daje kartę graczowi " << j.name;
                sleep();
                clear();
            }
            croupier.addCard(deck, j);
            cout << "Krupier daje kartę graczowi " << j.name;
            sleep();
            clear();
        }
    }

    for (int i = 0; i < 2; i++) {
        croupier.putCardOnTable(deck, table);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand(table);
        sleep();
        clear();
    }

    while (table.size() <= 5) {
        for (auto & i : line) {
            if (i.getFold()) remove(line.begin(), line.end(), i);
        }

        for (auto & i : line) {
            if (i.name == player.name) {
                cin.getline >> option;
                while (true) {
                    if (option == "Fold") {
                        i.setFold(true);
                        break;
                    } else if (option == "Check") {
                        i.setCheck(true);
                        break;
                    }
                    else if (option == "Call") break;
                    else if (option == "Bet") break;
                    else if (option == "Raise") break;
                    else if (option == "All in") {
                        i.setAllIn(true);
                        break;
                    }
                    else {
                        clear();
                        continue;
                    }
                }
                continue;
            }

            Bot* bot = static_cast<Bot*>(&i);
            if (bot) bot->strategy(table);
        }
    }
}
