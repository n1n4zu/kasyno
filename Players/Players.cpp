#include "Players.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include "../functions/poker.h"

using namespace std;

Players::Players(const string&) : name(), points(0){}

void Players::displayDeck() const {
    cout << "Karty gracza " << name << ":" << endl;
    for (const auto& card : deck) cout << card.value << " " << card.color << endl;
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

    while (points > 9) points -= 10;
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
            if (points > 21) points -= 10;
        } else if (points > 21) points += 1;
    }
}

void Players::displayHand(const vector<Card>& table) const {
    cout << "Karty gracza " << name << ": ";
    checkCards(table);
    for (const auto& card : deck) cout << card.value << " " << card.color << endl;
}

void Players::checkCards(const vector<Card> &table) const {
    map<string, int> colorsDict;
    colorsDict["Karo"] = 1;
    colorsDict["Trefl"] = 2;
    colorsDict["Pik"] = 3;
    colorsDict["Kier"] = 4;

    vector<int> colors;

    for (const auto & i : deck) colors.push_back(colorsDict[i.color]);

    if (!table.empty()) for (const auto & i : table) colors.push_back(colorsDict[i.color]);

    sort(colors.begin(), colors.end());

    map<string, int> valuesDict;
    valuesDict["2"] = 2;
    valuesDict["3"] = 3;
    valuesDict["4"] = 4;
    valuesDict["5"] = 5;
    valuesDict["6"] = 6;
    valuesDict["7"] = 7;
    valuesDict["8"] = 8;
    valuesDict["9"] = 9;
    valuesDict["10"] = 10;
    valuesDict["Walet"] = 11;
    valuesDict["Dama"] = 12;
    valuesDict["Król"] = 13;
    valuesDict["As"] = 14;

    vector<int> values;

    for (const auto & i : deck) values.push_back(valuesDict[i.value]);

    if (!table.empty()) for (const auto & i : table) values.push_back(valuesDict[i.value]);

    sort(values.begin(), values.end());

    switch (values.size()) {
        case 2:
            if (repeated(values, 2)) cout << "(Para)" << endl;
            else cout << "(Wysoka karta)" << endl;
            break;
        case 3:
            if (repeated(values, 3)) cout << "(Trójka)" << endl;
            else if (repeated(values, 2)) cout << "(Para)" << endl;
            else cout << "(Wysoka karta)" << endl;
            break;
        case 4:
            if (repeated(values, 4)) cout << "(Kareta)" << endl;
            else if (repeated(values, 3)) cout << "(Trójka)" << endl;
            else if (repeatedPairs(values, 2)) cout << "(Dwie pary)" << endl;
            else if (repeated(values, 2)) cout << "(Para)" << endl;
            else cout << "(Wysoka karta)" << endl;
            break;
        case 5:
            if (isRoyalFlush(values, colors)) cout << "(Poker królewski) " << endl;
            else if (isStraightFlush(values, colors)) cout << "(Poker)" << endl;
            else if (repeated(values, 4)) cout << "(Kareta)" << endl;
            else if (isFull(values)) cout << "(Ful)" << endl;
            else if (repeated(colors, 5)) cout << "(Kolor)" << endl;
            else if (isStraight(values)) cout << "(Strit)" << endl;
            else if (repeated(values, 3)) cout << "(Trójka)" << endl;
            else if (repeatedPairs(values, 2)) cout << "(Dwie pary)" << endl;
            else if (repeated(values, 2)) cout << "(Para)" << endl;
            else cout << "(Wysoka karta)" << endl;
            break;
        case 6:
            if (isRoyalFlush(values, colors)) cout << "(Poker królewski) " << endl;
            else if (isStraightFlush(values, colors)) cout << "(Poker)" << endl;
            else if (repeated(values, 4)) cout << "(Kareta)" << endl;
            else if (isFull(values)) cout << "(Ful)" << endl;
            else if (repeated(colors, 5)) cout << "(Kolor)" << endl;
            else if (isStraight(values)) cout << "(Strit)" << endl;
            else if (repeated(values, 3)) cout << "(Trójka)" << endl;
            else if (repeatedPairs(values, 2)) cout << "(Dwie pary)" << endl;
            else if (repeated(values, 2)) cout << "(Para)" << endl;
            else cout << "(Wysoka karta)" << endl;
            break;
        case 7:
            if (isRoyalFlush(values, colors)) cout << "(Poker królewski) " << endl;
            else if (isStraightFlush(values, colors)) cout << "(Poker)" << endl;
            else if (repeated(values, 4)) cout << "(Kareta)" << endl;
            else if (isFull(values)) cout << "(Ful)" << endl;
            else if (repeated(colors, 5)) cout << "(Kolor)" << endl;
            else if (isStraight(values)) cout << "(Strit)" << endl;
            else if (repeated(values, 3)) cout << "(Trójka)" << endl;
            else if (repeatedPairs(values, 2)) cout << "(Dwie pary)" << endl;
            else if (repeated(values, 2)) cout << "(Para)" << endl;
            else cout << "(Wysoka karta)" << endl;
            break;
        default:
            cout << "(Wysoka karta)" << endl;
            break;
    }

    colors.clear();
    values.clear();
}