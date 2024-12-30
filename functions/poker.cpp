#include "poker.h"
#include "../deck/deck.h"
#include <unordered_map>
#include <map>
#include <string>
#include <algorithm>

bool repeated(vector<int>& values, const int n) {
    unordered_map<int, int> count;

    for (int num : values) if (++count[num] == n) return true;

    return false;
}

bool repeatedPairs(vector<int>& values, int n) {
    unordered_map<int, int> count;

    for (int num : values) ++count[num];

    int pair_count = 0;

    for (const auto& [key, value] : count) if (value == n) ++pair_count;

    return pair_count >= 2;
}

bool isFull(vector<int>& values) {
    unordered_map<int, int> count;
    const bool isThree = repeated(values, 3);

    for (int num : values) ++count[num];

    int counter = 0;

    for (const auto& [key, value] : count) {
        if (value == 2) ++counter;
        else if (value == 3) ++counter;
    }

    return isThree && counter == 2;
}

bool isRoyalFlush(const vector<int>& values, vector<int>& colors) {
    const bool isFlush = repeated(colors, 5);

    for (int i = 0; i < values.size(); i++)
        if (values[i] + 1 == values[i + 1] &&
            values[i + 1] + 1 == values[i + 2] &&
            values[i + 2] + 1 == values[i + 3] &&
            values[i + 3] + 1 == values[i + 4] &&
            values[i + 4] == 14 &&
            isFlush) return true;

    return false;
}

bool isStraight(const vector<int>& values) {
    for (int i = 0; i < values.size(); i++)
        if ((values[i] + 1 == values[i + 1] &&
            values[i + 1] + 1 == values[i + 2] &&
            values[i + 2] + 1 == values[i + 3] &&
            values[i + 3] + 1 == values[i + 4]) ||
            (values[values.size() - 1] == 14 &&
            values[i] + 1 == values[i + 1] &&
            values[i + 1] + 1 == values[i + 2] &&
            values[i + 2] + 1 == values[i + 3])) return true;

    return false;
}

bool isStraightFlush(const vector<int>& values, vector<int> &colors) {
    return repeated(colors, 5) && isStraight(values);
}

int getHandValue(string hand, vector<Card> cards) {
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

    map<string, int> handValues;
    handValues["Wysoka karta"] = 1;
    handValues["Para"] = 2;
    handValues["Dwie pary"] = 3;
    handValues["Trójka"] = 4;
    handValues["Strit"] = 5;
    handValues["Kolor"] = 6;
    handValues["Ful"] = 7;
    handValues["Kareta"] = 8;
    handValues["Poker"] = 9;
    handValues["Poker królewski"] = 10;

    int handRank = handValues[hand];

    if (hand == "Para") {
        int pairRank = 0;
        for (const auto& card : cards) {
            if (valuesDict[card.value] > pairRank) {
                pairRank = valuesDict[card.value];
            }
        }

        // Combine the hand rank with the pair rank
        handRank = handRank * 100 + pairRank;
    }

    if (hand == "Strit") {

        int straightRank = 0;
        for (const auto& card : cards) {
            if (valuesDict[card.value] > straightRank) {
                straightRank = valuesDict[card.value];
            }
        }

        // Combine the hand rank with the straight rank
        handRank = handRank * 100 + straightRank;
    }

    if (hand == "Poker") {
        int pokerRank = 0;
        for (const auto& card : cards) {
            if (valuesDict[card.value] > pokerRank) {
                pokerRank = valuesDict[card.value];
            }
        }

        // Combine the hand rank with the poker rank
        handRank = handRank * 100 + pokerRank;
    }

    if (hand == "Kolor") {
        Card lastCard = cards.back();

        int lastCardValue = valuesDict[lastCard.value];

        // Połącz rangę koloru z wartością ostatniej karty
        handRank = handRank * 100 + lastCardValue;
    }

    if (hand == "Kareta") {
        int karetaValue = 0;
        for (const auto& card : cards) {
            karetaValue += valuesDict[card.value];
        }

        // Połącz rangę karety z wartością kart w karecie
        handRank = handRank * 100 + karetaValue;
    }

    if (hand == "Trójka") {
        int trójkaValue = 0;
        for (const auto& card : cards) {
            trójkaValue += valuesDict[card.value];
        }

        // Połącz rangę trójki z wartością kart w trójce
        handRank = handRank * 100 + trójkaValue;
    }

    if (hand == "Ful") {
        // Sprawdź czy trójki są takie same
        int trójkaValue = 0;
        for (const auto& card : cards) {
            if (card.value == "3") {
                trójkaValue = valuesDict[card.value];
                break;
            }
        }

        // Jeśli trójki są takie same, sprawdź pary
        if (trójkaValue == 0) {
            int paraValue = 0;
            for (const auto& card : cards) {
                if (card.value == "2") {
                    paraValue = valuesDict[card.value];
                    break;
                }
            }

            handRank = handRank * 100 + paraValue;
        } else {
            handRank = handRank * 100 + trójkaValue;
        }
    }

    if (hand == "Dwie pary") {
        vector<int> paraValues;
        for (const auto& card : cards) {
            if (card.value == "2" || card.value == "3" || card.value == "4" || card.value == "5" || card.value == "6" || card.value == "7" || card.value == "8" || card.value == "9" || card.value == "10" || card.value == "Walet" || card.value == "Dama" || card.value == "Król" || card.value == "As") {
                paraValues.push_back(valuesDict[card.value]);
            }
        }

        // Posortuj wartości kart w parach
        sort(paraValues.begin(), paraValues.end());

        // Połącz rangę dwóch par z wartościami kart w parach
        handRank = handRank * 100 + paraValues[3] * 10 + paraValues[2];
    }

    if (hand == "Wysoka karta") {
        vector<int> cardValues;
        for (const auto& card : cards) {
            cardValues.push_back(valuesDict[card.value]);
        }

        // Posortuj wartości kart w wysokiej karcie
        sort(cardValues.begin(), cardValues.end());

        // Połącz rangę wysokiej karty z wartościami kart w wysokiej karcie
        handRank = handRank * 100 + cardValues[4] * 10 + cardValues[3] * 10 + cardValues[2] * 10 + cardValues[1] * 10 + cardValues[0];
    }

    return handRank;
}