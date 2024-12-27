#include "Baccarat.h"
#include <iostream>
#include "../functions/functions.h"
#include <string>

using namespace std;

void Baccarat::play() {

    // Tworzenie talii
    array<Card, 52> deck;
    int index = 0;

    for (const auto& color : colors) {
        for (const auto& value : values) {
            deck[index].color = color;
            deck[index].value = value;
            index++;
        }
    }

    // Krupier daje graczom karty
    croupier.giveCards(deck, croupier);
    croupier.giveCards(deck, player);

    // Podliczanie punktów krupiera
    croupier.countPointsBaccarat();

    // Krupier dobiera kartę
    if (croupier.points < 5) croupier.addCard(deck, croupier, 0);

    // Podliczanie punktów krupiera
    croupier.countPointsBaccarat();

    // Wyświetlenie kart krupiera
    croupier.displayDeck();

    cout << endl;

    // Podliczenie punktów i wyświetlenie kart gracza
    player.countPointsBaccarat();
    player.displayDeck();

    // Gracz może dobrać kartę
    if (player.points < 5) {
        cout << endl;

        string option;
        cout << "Dobrać kartę? [t/n]" << endl << "> ";
        cin >> option;

        // Dodanie karty graczowi
        if (option == "t") croupier.addCard(deck, player, 0);
        else if (option == "T") croupier.addCard(deck, player, 0);
        else if (option == "tak") croupier.addCard(deck, player, 0);
        else if (option == "Tak") croupier.addCard(deck, player, 0);

        clear();

        // Podlicznie punktów i wyświetlenie kart krupiera
        croupier.countPointsBaccarat();
        croupier.displayDeck();

        cout << endl;

        // Podlicznie punktów i wyświetlenie kart gracza
        player.countPointsBaccarat();
        player.displayDeck();
    }
    cout << endl;

    // Krupier sprawdza i informuje kto wygrał
    croupier.whoWinsBlackjack(croupier, player);
}