#include "Players.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include "../functions/poker.h"

using namespace std;

Players::Players(string name) : name(), points(0){}

bool Players::operator==(const Players& other) const {
    return name == other.name;
}

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
    cout << "Karty gracza " << name << ": (" << checkCards(table) << ")" << endl;
    for (const auto& card : deck) cout << card.value << " " << card.color << endl;
}

string Players::checkCards(const vector<Card> &table) const {
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
            return repeated(values, 2) ? "Para" : "Wysoka karta";
        case 3:
            if (repeated(values, 3)) return "Trójka";
            if (repeated(values, 2)) return "Para";
            return  "Wysoka karta";
        case 4:
            if (repeated(values, 4)) return "Kareta";
            if (repeated(values, 3)) return "Trójka";
            if (repeatedPairs(values, 2)) return "Dwie pary";
            if (repeated(values, 2)) return "Para";
            return "Wysoka karta";
        case 5:
            if (isRoyalFlush(values, colors)) return "Poker królewski";
            if (isStraightFlush(values, colors)) return "Poker";
            if (repeated(values, 4)) return "Kareta";
            if (isFull(values)) return "Ful";
            if (repeated(colors, 5)) return "Kolor";
            if (isStraight(values)) return "Strit";
            if (repeated(values, 3)) return "Trójka";
            if (repeatedPairs(values, 2)) return "Dwie pary";
            if (repeated(values, 2)) return "Para";
            return "Wysoka karta";
        case 6:
            if (isRoyalFlush(values, colors)) return "Poker królewski";
            if (isStraightFlush(values, colors)) return "Poker";
            if (repeated(values, 4)) return "Kareta";
            if (isFull(values)) return "Ful";
            if (repeated(colors, 5)) return "Kolor";
            if (isStraight(values)) return "Strit";
            if (repeated(values, 3)) return "Trójka";
            if (repeatedPairs(values, 2)) return "Dwie pary";
            if (repeated(values, 2)) return "Para";
            return "Wysoka karta";
        case 7:
            if (isRoyalFlush(values, colors)) return "Poker królewski";
            if (isStraightFlush(values, colors)) return "Poker";
            if (repeated(values, 4)) return "Kareta";
            if (isFull(values)) return "Ful";
            if (repeated(colors, 5)) return "Kolor";
            if (isStraight(values)) return "Strit";
            if (repeated(values, 3)) return "Trójka";
            if (repeatedPairs(values, 2)) return "Dwie pary";
            if (repeated(values, 2)) return "Para";
            return "Wysoka karta";
        default:
            return "Wysoka karta";
    }

    colors.clear();
    values.clear();
    return "Wysoka karta";
}

bool Players::getFold() const {
    return isFold;
}

bool Players::getCheck() const {
    return isCheck;
}

bool Players::getAllIn() const {
    return isAllIn;
}

void Players::setFold(bool fold) {
    isFold = fold;
}

void Players::setCheck(bool check) {
    isCheck = check;
}

void Players::setAllIn(bool allIn) {
    isAllIn = allIn;
}

double Players::getBet() {
    return bet;
}

void Players::setBet(double money) {
    bet = money;
}