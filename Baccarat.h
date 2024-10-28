#ifndef BACCARAT_H
#define BACCARAT_H
#include <iostream>
#include "Croupier.h"
#include "Player.h"

using namespace std;

class Baccarat {
    Player& player;
    Croupier& croupier;

    public:
    Baccarat(Player& player, Croupier& croupier) : player(player), croupier(croupier) {};
    void play() {
        array<Karta, 52> talia;
        int index = 0;

        for (const auto& kolor : kolory) {
            for (const auto& wartosc : wartosci) {
                talia[index].kolor = kolor;
                talia[index].wartosc = wartosc;
                index++;
            }
        }

        croupier.giveCardsBaccarat(talia, croupier);
        croupier.giveCardsBaccarat(talia, player);

        croupier.countPoints();

        if (croupier.points < 5) croupier.addBaccaratCard(talia, croupier);

        croupier.countPoints();

        croupier.displayDeck();

        cout << endl;

        player.countPoints();
        player.displayDeck();

        if (player.points < 5) {
            cout << endl;

            string option;
            cout << "Dobrać kartę? [t/n]" << endl << ">";
            cin >> option;

            if (option == "t") croupier.addBaccaratCard(talia, player);
            else if (option == "T") croupier.addBaccaratCard(talia, player);
            else if (option == "tak") croupier.addBaccaratCard(talia, player);
            else if (option == "Tak") croupier.addBaccaratCard(talia, player);

            clear();

            croupier.countPoints();
            croupier.displayDeck();

            cout << endl;

            player.countPoints();
            player.displayDeck();
        }
        cout << endl;

        croupier.whoWins(croupier, player);
    }
};

#endif //BACCARAT_H
