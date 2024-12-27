#include "Blackjack.h"
#include <iostream>
#include "../functions/functions.h"
#include <string>
#include <array>

using namespace std;

void Blackjack::play() const {
    string option;
    array<Card, 52> deck;
    int index = 0;

    for (const auto& color : colors) {
        for (const auto& value : values) {
            deck[index].color = color;
            deck[index].value = value;
            index++;
        }
    }

    while (true) {
        sleep();

        croupier.addCard(deck, player, 0);

        player.countPointsBlackjack();
        player.displayDeck();

        cout << endl;

        sleep();

        croupier.addCard(deck, croupier, 0);

        clear();

        player.countPointsBlackjack();
        player.displayDeck();

        cout << endl;

        croupier.countPointsBlackjack();
        croupier.displayDeck();

        sleep();

        clear();

        croupier.addCard(deck, player, 0);

        player.countPointsBlackjack();
        player.displayDeck();

        cout << endl;

        croupier.countPointsBlackjack();
        croupier.displayDeck();

        cout << endl;

        sleep();

        croupier.addCard(deck, croupier, 0);

        clear();

        player.countPointsBlackjack();
        player.displayDeck();

        cout << endl;

        if (croupier.deck[0].value == "As") {
            string option;

            cout << "Karty gracza " << croupier.name << ":" << endl;
            cout << croupier.deck[0].value << " " << croupier.deck[0].color << endl;
            cout << "????? ??????" << endl;
            cout << "Punkty gracza " << croupier.name << ": ????" << endl;

            cout << endl;

            cout << "Ubezpieczyć? [tak/nie]" << endl << "> ";
            cin >> option;

            if (option == "tak") {
                player.setInsurance(true);
                player.setInsuranceValue(player.getBet() / 2);
                player.setCash(player.getCash() - player.getInsuranceValue());
            }

            sleep();

            clear();

            player.countPointsBlackjack();
            player.displayDeck();

            cout << endl;

            croupier.countPointsBlackjack();
            croupier.displayDeck();

            if ((croupier.deck[1].value != "10"
                || croupier.deck[1].value != "Walet"
                || croupier.deck[1].value != "Dama"
                || croupier.deck[1].value != "Król")
                && player.getInsurance()) {
                cout << endl << "Straciłeś ubezpieczenie!" << endl;
                player.setInsuranceValue(0);
            }
        } else {
            croupier.countPointsBlackjack();
            croupier.displayDeck();
        }

        cout << endl;

        if (croupier.checkBlackjack(croupier) && croupier.checkBlackjack(player)) {
            cout << "Remis!" << endl;
            break;
        }

        if (croupier.checkBlackjack(croupier)) {
            cout << croupier.name << " ma Blackjack'a!" << endl;
            break;
        }

        if (croupier.checkBlackjack(player)) {
            cout << player.name << " ma Blackjack'a!" << endl;
            player.setCash(player.getCash() + player.getBet() * 1.5);
            break;
        }

        while (true) {
            if (player.deck.size() == 2) {
                cout << "Dobrać kartę? [hit/stand/double]" << endl << "> ";
                cin >> option;
            } else {
                cout << "Dobrać kartę? [hit/stand]" << endl << "> ";
                cin >> option;
            }

            if (option == "hit") {
                sleep();
                croupier.addCard(deck, player, 0);
            } else if (option == "stand") break;
            else if (option == "double" && player.deck.size() == 2) {
                player.setCash(player.getCash() - player.getBet());
                player.setBet(player.getBet() * 2);

                croupier.addCard(deck, player, 0);

                sleep();

                clear();

                player.countPointsBlackjack();
                player.displayDeck();

                cout << endl;

                croupier.countPointsBlackjack();
                croupier.displayDeck();

                cout << endl;

                break;
            } else {
                clear();

                player.countPointsBlackjack();
                player.displayDeck();

                cout << endl;

                croupier.countPointsBlackjack();
                croupier.displayDeck();

                cout << endl;

                continue;
            }

            clear();

            player.countPointsBlackjack();
            player.displayDeck();

            cout << endl;

            croupier.countPointsBlackjack();
            croupier.displayDeck();

            cout << endl;

            if (player.points >= 21) break;
        }

        if (player.points <= 21) {
            while (croupier.points < 17) {
                croupier.addCard(deck, croupier, 0);

                sleep();

                clear();

                player.countPointsBlackjack();
                player.displayDeck();

                cout << endl;

                croupier.countPointsBlackjack();
                croupier.displayDeck();

                cout << endl;
            }
        }

        croupier.whoWinsBlackjack(croupier, player);
        break;
    }
}