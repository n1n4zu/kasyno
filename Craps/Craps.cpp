#include "Craps.h"
#include <iostream>

using namespace std;

void Craps::play() {

    cout << "Podaj warotść kości pierwszej: " << endl << "> ";
    cin >> guess1;

    cout << "Podaj wartość kości drugiej: " << endl << "> ";
    cin >> guess2;

    cout << "Wartości kości: " << endl;
    cout << "Kość pierwsza - " << roll1 << endl;
    cout << "Kość druga - " << roll2 << endl;

    if (roll1 == guess1 && roll2 == guess2) cout << "Wygrałeś!" << endl;
    else cout << "Przegrałeś" << endl;
}