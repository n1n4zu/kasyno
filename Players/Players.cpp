#include "Players.h"
#include <string>
#include <iostream>

using namespace std;

Players::Players(string name) : name(), points(0){}

void Players::displayDeck() const {
    cout << "Karty gracza " << name << ":" << endl;
    for (const auto& card : deck) {
        cout << card.value << " " << card.color << endl;
    }
    cout << "Ilość punktów gracza " << name << ": " << points << endl;
}

void Players::countPointsBaccarat() {
    points = 0;

    for (auto& card : deck) {
        if (card.value == "As") points += 1;
        else if (card.value == "2") points += 2;
        else if (card.value == "3") points += 3;
        else if (card.value == "4") points += 4;
        else if (card.value == "5") points += 5;
        else if (card.value == "6") points += 6;
        else if (card.value == "7") points += 7;
        else if (card.value == "8") points += 8;
        else if (card.value == "9") points += 9;
        else if (card.value == "10"
                || card.value == "Walet"
                || card.value == "Dama"
                || card.value == "Król") points += 0;
    }

    while (points > 9) {
        points -= 10;
    }
}

void Players::countPointsBlackjack() {
    points = 0;
    int as = 0; // Ilość asów w talii

    // Liczenie punktów
    for (auto& card : deck) {
        if (card.value == "2") points += 2;
        else if (card.value == "3") points += 3;
        else if (card.value == "4") points += 4;
        else if (card.value == "5") points += 5;
        else if (card.value == "6") points += 6;
        else if (card.value == "7") points += 7;
        else if (card.value == "8") points += 8;
        else if (card.value == "9") points += 9;
        else if (card.value == "10"
                || card.value == "Walet"
                || card.value == "Dama"
                || card.value == "Król") points += 10;
        else if (card.value == "As") as++;
    }

    // Dodawanie punktów asów
    for (int i = 0; i < as; i++) {
        if (points < 21) {
            points += 11;
            if (points > 21) {
                points -= 10;
            }
        } else if (points > 21) points += 1;
    }
}