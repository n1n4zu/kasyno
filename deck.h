#include <string>
#include <array>

using namespace std;

#ifndef DECK_H
#define DECK_H

struct Karta {
    string kolor;
    string wartosc;
};

void wypiszTalie(const array<Karta, 52>& talia) {
    for (const auto& karta : talia) {
        cout << karta.wartosc << " " << karta.kolor << endl;
    }
}

void wypiszKarte(const Karta& karta) {
    cout << karta.wartosc << " " << karta.kolor << endl;
}

string kolory[] = {"Kier", "Karo", "Trefl", "Pik"};
string wartosci[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Walet", "Dama", "Król", "As"};

#endif //DECK_H
