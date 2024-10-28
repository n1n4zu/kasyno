#ifndef PLAYERS_H
#define PLAYERS_H
#include <string>
#include <vector>
using namespace std;

class Players {
    public:
    string name;
    int points;
    vector<Karta> deck;
    Players(string name) : name(), points(0){}

    void displayDeck() const {
        cout << "Karty gracza " << name << ":" << endl;
        for (const auto& karta : deck) {
            cout << karta.wartosc << " " << karta.kolor << endl;
        }
        cout << "Ilość punktów gracza " << name << ": " << points << endl;
    }

    void countPoints() {
        points = 0;

        for (auto& karta : deck) {
            if (karta.wartosc == "As") points += 1;
            else if (karta.wartosc == "2") points += 2;
            else if (karta.wartosc == "3") points += 3;
            else if (karta.wartosc == "4") points += 4;
            else if (karta.wartosc == "5") points += 5;
            else if (karta.wartosc == "6") points += 6;
            else if (karta.wartosc == "7") points += 7;
            else if (karta.wartosc == "8") points += 8;
            else if (karta.wartosc == "9") points += 9;
            else if (karta.wartosc == "10") points += 10;
            else if (karta.wartosc == "Walet") points += 0;
            else if (karta.wartosc == "Dama") points += 0;
            else if (karta.wartosc == "Król") points += 0;
        }

        while (points > 9) {
            points -= 10;
        }
    }

};

#endif //PLAYERS_H
