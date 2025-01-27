#include "OneHandedBandit.h"
#include <iostream>

using namespace std;

void OneHandedBandit::play() const {
    reset();

    double betAmount;
    cout << "Podaj kwotę zakładu: ";
    cin >> betAmount;
    player.placeBet(betAmount);

    cout << var1 << " " << var2 << " " << var3 << endl;

    if (var1 == var2 && var2 == var3) {
        player.winBet(3); // Wygrana 3:1
    } else {
        cout << "Przegrałeś zakład!" << endl;
        player.setBet(0); // Resetowanie zakładu po przegranej
    }

    cout << endl << "Wciśnij Enter by kontynuować";
    cin.ignore();
    cin.get();
}

void OneHandedBandit::reset() const{
    var1 = randomize(1, 5);
    var2 = randomize(1, 5);
    var3 = randomize(1, 5);
}