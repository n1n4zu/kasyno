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
            pairRank = max(pairRank, valuesDict[card.value]);
        }
        handRank = handRank * 100 + pairRank;
    }

    if (hand == "Dwie pary") {
        map<int, int> valueCounts;
        for (const auto& card : cards) {
            valueCounts[valuesDict[card.value]]++;
        }

        vector<int> pairs;
        int kicker = 0;
        for (const auto& [value, count] : valueCounts) {
            if (count == 2) pairs.push_back(value);
            if (count == 1) kicker = max(kicker, value);
        }

        if (pairs.size() >= 2) {
            sort(pairs.begin(), pairs.end(), greater<int>());
            handRank = handRank * 1000 + pairs[0] * 100 + pairs[1] * 10 + kicker;
        }
    }

    if (hand == "Trójka") {
        int tripletValue = 0;
        for (const auto& card : cards) {
            tripletValue += valuesDict[card.value];
        }
        handRank = handRank * 10000 + tripletValue;
    }

    if (hand == "Strit") {
        int straightRank = 0;
        for (const auto& card : cards) {
            straightRank = max(straightRank, valuesDict[card.value]);
        }
        handRank = handRank * 100000 + straightRank;
    }

    if (hand == "Kolor") {
        Card highestCard = cards.back();
        int highestValue = valuesDict[highestCard.value];
        handRank = handRank * 1000000 + highestValue;
    }

    if (hand == "Ful") {
        map<int, int> valueCounts;
        for (const auto& card : cards) {
            valueCounts[valuesDict[card.value]]++;
        }

        int threeOfAKindValue = 0, pairValue = 0;
        for (const auto& [value, count] : valueCounts) {
            if (count == 3) threeOfAKindValue = value;
            if (count == 2) pairValue = value;
        }

        if (threeOfAKindValue && pairValue) {
            handRank = handRank * 10000000 + threeOfAKindValue * 10 + pairValue;
        }
    }

    if (hand == "Kareta") {
        int karetaValue = 0;
        for (const auto& card : cards) {
            karetaValue += valuesDict[card.value];
        }
        handRank = handRank * 100000000 + karetaValue;
    }

    if (hand == "Poker") {
        int pokerRank = 0;
        for (const auto& card : cards) {
            pokerRank = max(pokerRank, valuesDict[card.value]);
        }
        handRank = handRank * 1000000000 + pokerRank;
    }

    if (hand == "Poker królewski") {
        handRank = handRank * 10000000000;
    }

    if (hand == "Wysoka karta") {
        vector<int> cardValues;
        for (const auto& card : cards) {
            cardValues.push_back(valuesDict[card.value]);
        }

        sort(cardValues.rbegin(), cardValues.rend());
        handRank = handRank * 10;
        for (int i = 0; i < min(5, (int)cardValues.size()); ++i) {
            handRank = handRank * 10 + cardValues[i];
        }
    }

    return handRank;
}
