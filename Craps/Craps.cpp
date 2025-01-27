#include "Craps.h"
#include <iostream>

using namespace std;

void Craps::play() {
    reset();

    double betAmount;
    cout << "Podaj kwotę zakładu: ";
    cin >> betAmount;
    player.placeBet(betAmount);

    cout << "Podaj wartość kości pierwszej: " << endl << "> ";
    cin >> guess1;

    cout << "Podaj wartość kości drugiej: " << endl << "> ";
    cin >> guess2;

    cout << "Wartości kości: " << endl;
    cout << "Kość pierwsza - " << roll1 << endl;
    cout << "Kość druga - " << roll2 << endl;

    if (roll1 == guess1 && roll2 == guess2) {
        player.winBet(2); // Wygrana 2:1
    } else {
        cout << "Przegrałeś zakład!" << endl;
        player.setBet(0); // Resetowanie zakładu po przegranej
    }

    cout << endl << "Wciśnij Enter by kontynuować";
    cin.ignore();
    cin.get();
}

void Craps::reset() {
    roll1 = randomize(1, 6);
    roll2 = randomize(1, 6);
    guess1 = 0;
    guess2 = 0;
}