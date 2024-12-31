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
        if (line.size() == 1) break;

        for (auto * i : line) i->setCheck(false);
        check_line.clear();

        croupier.putCardOnTable(deck, table);
        croupier.displayTable(table);
        cout << endl;
        player.displayHand(table);
        sleep();
        clear();

        if (table.size() > 2) rotate(line.rbegin(), line.rbegin() + 1, line.rend());

        cout << "Gracze: ";
        for (auto * i : line) cout << i->name << " ";
        cout << endl;

        for (auto * i : line) {
            if (i->getAllIn()) continue;
            clear();
            if (i->name != player.name) cout << "Teraz gra gracz " << i->name << endl;
            if (i->name != player.name) {
                croupier.displayTable(table);
                cout << endl;
                player.displayHand(table);
                sleep();
            }
            if (i->name == player.name) {
                while (true) {
                    cout << "Teraz gra gracz " << i->name << endl;
                    croupier.displayTable(table);
                    cout << endl;
                    player.displayHand(table);
                    cout << "Podaj opcję [Fold/Check/Call/Bet/All-in]:" << endl << "> ";
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
                    if (option == "All-in") {
                        i->setAllIn(true);
                        break;
                    }
                    clear();
                }
                continue;
            }

            Bot* bot = static_cast<Bot*>(i);
            option = bot->strategy(table, actual_bet);
            if (option == "Fold") {
                i->setFold(true);
                cout << endl << "Gracz " << i->name << " spasował" << endl;
                sleep();
            } else if (option == "Check") {
                i->setCheck(true);
                check_line.push_back(i);
            } else if (option == "Call") continue;
            else if (option == "Bet") continue;
            else if (option == "All-in") {
                i->setAllIn(true);
                cout << endl << "Gracz " << i->name << " spasował" << endl;
            }
        }

        if (!check_line.empty()) {
            for (auto * i : check_line) {
                if (i->getAllIn()) continue;
                clear();
                if (i->name != player.name) cout << "Teraz gra gracz " << i->name << endl;
                if (i->name != player.name) {
                    croupier.displayTable(table);
                    cout << endl;
                    player.displayHand(table);
                    sleep();
                }
                if (i->name == player.name) {
                    while (true) {
                        cout << "Teraz gra gracz " << i->name << endl;
                        croupier.displayTable(table);
                        cout << endl;
                        player.displayHand(table);
                        cout << "Podaj opcję [Fold/Call/Bet/All-in]:" << endl << "> ";
                        cin >> option;
                        if (option == "Fold") {
                            i->setFold(true);
                            break;
                        } if (option == "Call") break;
                        if (option == "Bet") break;
                        if (option == "All-in") {
                            i->setAllIn(true);
                            break;
                        }
                        clear();
                    }
                    continue;
                }

                Bot* bot = static_cast<Bot*>(i);
                option = bot->strategy(table, actual_bet);
                if (option == "Fold") {
                    i->setFold(true);
                    cout << endl << "Gracz " << i->name << " spasował" << endl;
                    sleep();
                } else if (option == "Call") continue;
                else if (option == "Bet") continue;
                else if (option == "All-in") {
                    i->setAllIn(true);
                    cout << endl << "Gracz " << i->name << " gra va banque" << endl;
                }
            }
        }

        line.erase(remove_if(line.begin(), line.end(), [](Players* player) {
            return player->getFold();
        }), line.end());

        if (player.getFold()) break;

        clear();
    }

    croupier.displayTable(table);
    cout << endl;
    player.displayHand(table);
    cout << endl;

    if (player.getFold()) cout << "Gracz " << player.name << " przegrał" << endl;
    else {
        if (line.size() == 1) cout << "Wygrał gracz " << player.name << endl;
        else croupier.whoWinsPoker(line, table);
    }

    bob.displayHand(table);
    john.displayHand(table);
    tim.displayHand(table);

    cout << endl;
    for (auto * i : line) cout << i-> name << " ";
    cout << endl;
}
