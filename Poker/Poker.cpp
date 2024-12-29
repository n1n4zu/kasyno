#include "Poker.h"
#include <iostream>
#include "../functions/functions.h"
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include "../Players/Bot.h"
#include "../Players/Player.h"

using namespace std;

void Poker::play() const {
    string option;
    array<Card, 52> deck;
    int index = 0;
    vector<Card> table;
    int actual_bet = 0;

    for (const auto& color : colors) {
        for (const auto& value : values) {
            deck[index].color = color;
            deck[index].value = value;
            index++;
        }
    }

    vector<Players*> line = {&player, &bob, &john, &tim};
    vector<Players*> check_line;

    for (int i = 0 ; i < 2; i++) {
        for (auto * j : line) {
            cout << "Krupier daje kartę graczowi " << j->name << endl;
            if (!player.deck.empty() && j->name != player.name) player.displayHand(table);
            if (j->name == player.name) {
                croupier.addCard(deck, player);
                player.displayHand(table);
                sleep();
                clear();
                continue;
            }
            croupier.addCard(deck, *j);
            sleep();
            clear();
        }
    }

    croupier.putCardOnTable(deck, table);
    croupier.displayTable(table);
    cout << endl;
    player.displayHand(table);
    sleep();
    clear();

    while (table.size() < 5) {
        if (player.getFold()) break;

        for (auto * i : line) if (i->getFold()) remove(line.begin(), line.end(), i);

        for (auto * i : line) i->setCheck(false);
        check_line.clear();

        croupier.putCardOnTable(deck, table);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand(table);
        sleep();
        clear();

        if (table.size() > 2) rotate(line.rbegin(), line.rbegin() + 1, line.rend());

        for (auto * i : line) {
            if (i->getAllIn()) continue;
            cout << "Teraz gra gracz " << i->name << endl;
            sleep();
            if (i->name == player.name) {
                while (true) {
                    clear();
                    croupier.displayTable(table);
                    cout << endl;
                    player.displayHand(table);
                    cout << "Podaj opcję [Fold/Check/Call/Raise/Bet/All-in]:" << endl;
                    cin >> option;
                    if (option == "Fold") {
                        i->setFold(true);
                        break;
                    } if (option == "Check") {
                        i->setCheck(true);
                        check_line.push_back(i);
                        break;
                    } if (option == "Call") break;
                    if (option == "Bet") break;
                    if (option == "Raise") break;
                    if (option == "All-in") {
                        i->setAllIn(true);
                        break;
                    }
                    clear();
                }
                continue;
            }

            Bot* bot = static_cast<Bot*>(i);
            option = bot->strategy(table);
            if (option == "Fold") i->setFold(true);
            else if (option == "Check") {
                i->setCheck(true);
                check_line.push_back(i);
            } else if (option == "Call") continue;
            else if (option == "Bet") continue;
            else if (option == "Raise") continue;
            else if (option == "All-in") i->setAllIn(true);
        }

        if (!check_line.empty()) {
            for (auto * i : check_line) {
                if (i->getAllIn()) continue;
                cout << "Teraz gra gracz " << i->name << endl;
                sleep();
                if (i->name == player.name) {
                    while (true) {
                        clear();
                        croupier.displayTable(table);
                        cout << endl;
                        player.displayHand(table);
                        cout << "Podaj opcję [Fold/Call/Raise/Bet/All-in]:" << endl;
                        cin >> option;
                        if (option == "Fold") {
                            i->setFold(true);
                            break;
                        } if (option == "Call") break;
                        if (option == "Bet") break;
                        if (option == "Raise") break;
                        if (option == "All-in") {
                            i->setAllIn(true);
                            break;
                        }
                        clear();
                    }
                    continue;
                }

                Bot* bot = static_cast<Bot*>(i);
                option = bot->strategy(table);
                if (option == "Fold") i->setFold(true);
                else if (option == "Call") continue;
                else if (option == "Bet") continue;
                else if (option == "Raise") continue;
                else if (option == "All-in") i->setAllIn(true);
            }
        }

        clear();
    }

    croupier.displayTable(table);
    cout << endl;
    player.displayHand(table);

    if (player.getFold()) cout << "Gracz " << player.name << " przegrał" << endl;
}
