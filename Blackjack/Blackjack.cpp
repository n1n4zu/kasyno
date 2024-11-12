#include "Blackjack.h"
#include <iostream>
#include "../functions/functions.h"
#include <string>


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

    while(true) {
        sleep();

        croupier.addCard(deck, player);

        player.countPointsBlackjack();
        player.displayDeck();

        cout << endl;

        sleep();

        croupier.addCard(deck, croupier);

        clear();

        player.countPointsBlackjack();
        player.displayDeck();

        cout << endl;

        croupier.countPointsBlackjack();
        croupier.displayDeck();

        sleep();

        clear();

        croupier.addCard(deck, player);

        player.countPointsBlackjack();
        player.displayDeck();

        cout << endl;

        croupier.countPointsBlackjack();
        croupier.displayDeck();

        cout << endl;

        sleep();

        croupier.addCard(deck, croupier);

        clear();

        player.countPointsBlackjack();
        player.displayDeck();

        cout << endl;

        if (croupier.deck[0].value == "As") {
            cout << croupier.deck[0].value << " " << croupier.deck[0].color << endl;
            cout << "????? ??????" << endl;
            cout << "Punkty gracza " << croupier.name << ": ????" << endl;
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
            break;
        }

        while (true) {
            cout << "Dobrać kartę? [hit/stand]" << endl << "> ";
            cin >> option;

            if (option == "hit") {
                sleep();
                croupier.addCard(deck, player);
            }
            else if (option == "stand") break;
            else {
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
                croupier.addCard(deck, croupier);

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
