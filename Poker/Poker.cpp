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
    reset();
    croupier.clearUsedIndexes();

    string option;
    double money = 0;
    array<Card, 52> deck;
    int index = 0;
    vector<Card> table;
    double actual_bet = 0;
    double bet;

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
                    } if (option == "Call") {
                        bet = actual_bet;
                        i->setBet(bet);
                        money += bet;
                        break;
                    } if (option == "Bet") {
                        cout << "Podaj kwotę:" << endl << "> ";
                        if (bet > actual_bet) {
                            if (actual_bet == 0) actual_bet = bet;
                            cin >> bet;
                            money += bet;
                            i->setBet(bet);
                        } else {
                            cout << "Niepoprawna kwota zakłdadu" << endl;
                            cout << "Podaj kwotę:" << endl << "> ";
                            cin >> bet;
                            money += bet;
                            i->setBet(bet);
                        }
                        break;
                    } if (option == "All-in") {
                        i->setAllIn(true);
                        actual_bet = player.getCash();
                        money += player.getCash();
                        break;
                    }
                    clear();
                }
                if (i->getFold() && i->name == player.name) break;
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
                        } if (option == "Call") {
                            bet = actual_bet;
                            i->setBet(bet);
                            money += bet;
                            break;
                        } if (option == "Bet") {
                            cout << "Podaj kwotę:" << endl << "> ";
                            if (bet > actual_bet) {
                                if (actual_bet == 0) actual_bet = bet;
                                cin >> bet;
                                money += bet;
                                i->setBet(bet);
                            } else {
                                cout << "Niepoprawna kwota zakłdadu" << endl;
                                cout << "Podaj kwotę:" << endl << "> ";
                                cin >> bet;
                                money += bet;
                                i->setBet(bet);
                            }
                            break;
                        } if (option == "All-in") {
                            i->setAllIn(true);
                            actual_bet = player.getCash();
                            money += player.getCash();
                            break;
                        }
                        clear();
                    }
                    if (i->getFold() && i->name == player.name) break;
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

        if (table.size() > 2) rotate(line.rbegin(), line.rbegin() + 1, line.rend());

        if (player.getFold()) break;

        clear();
    }

    croupier.displayTable(table);
    cout << endl;
    player.displayHand(table);
    cout << endl;

    if (player.getFold()) {
        cout << "Wygrał gracz " << player.name << endl;
        player.setCash(player.getCash() + money);
    } else {
        if (line.size() == 1) {
            cout << "Wygrał gracz " << player.name << endl;
            player.setCash(player.getCash() + money);
        } else croupier.whoWinsPoker(line, table);
    }
}

void Poker::reset() const {
    player.deck.clear();
    bob.deck.clear();
    john.deck.clear();
    tim.deck.clear();
    player.setFold(false);
    bob.setFold(false);
    john.setFold(false);
    tim.setFold(false);
    player.setAllIn(false);
    bob.setAllIn(false);
    john.setAllIn(false);
    tim.setAllIn(false);
    player.setCheck(false);
    bob.setCheck(false);
    john.setCheck(false);
    tim.setCheck(false);
}