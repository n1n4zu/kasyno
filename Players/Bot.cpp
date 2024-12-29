#include "Bot.h"
#include <vector>
#include <map>
#include <algorithm>
#include "../functions/poker.h"
#include "../functions/functions.h"

using namespace std;

Bot::Bot(const string& name, const double allInChance) : Players(name) {
    this->name = name;
    this->allInChance = allInChance;
}

bool Bot::isWorth(vector<int>& values, vector<int>& colors) const {

    return isRoyalFlush(values, colors) ||
        isRoyalFlush(values, colors) ||
        repeated(values, 4) ||
        isFull(values) ||
        repeated(colors, 5) ||
        isStraight(values) ||
        repeated(values, 3) ||
        repeatedPairs(values, 2) ||
        repeated(values, 2);
}


string Bot::strategy(const vector<Card>& table, int actual_bet) {
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

    int number = randomize(1, 10000);

    if (isWorth(values, colors)) {
        for (int i = 0; i < 10; i++) {
            number = randomize(1, 10000);
            if (isRoyalFlush(values, colors)) {
                if (number % 6 == 0 && static_cast<int> (number * 2 * allInChance) % 10 == 0) {
                    if (2 * allInChance > 1) return "All-in";
                    return "Raise";
                }
            } else if (isStraightFlush(values, colors)) {
                if (number % 6 == 0 && static_cast<int> (number * 1.5 * allInChance) % 10 == 0) {
                    if (1.5 * allInChance > 1) return "All-in";
                    return "Raise";
                }
            } else if (repeated(values, 4)) {
                if (number % 6 == 0 && static_cast<int> (number * allInChance) % 10 == 0)
                    return "Call";
            } else if (isFull(values)) {
                if (number % 6 == 0 && static_cast<int> (number * 0.75 * allInChance) % 10 == 0)
                    return "Call";
            } else if (repeated(colors, 5)) {
                if (number % 6 == 0 && static_cast<int> (number * 0.5 * allInChance) % 10 == 0)
                    return "Call";
            } else if (isStraight(values)) {
                if (number % 6 == 0 && static_cast<int> (number * 0.25 * allInChance) % 10 == 0)
                    return "Call";
            } else if (repeated(values, 3)) {
                if (number % 6 == 0 && static_cast<int> (number * 0.15 * allInChance) % 10 == 0)
                    return "Call";
            } else if (repeatedPairs(values, 2)) {
                if (number % 6 == 0 && static_cast<int> (number * 0.10 * allInChance) % 10 == 0)
                    return "Call";
            } else if (repeated(values, 2)) {
                if (number % 6 == 0 && static_cast<int> (number * 0.05 * allInChance) % 10 == 0)
                    return "Call";
            } else return "Fold";
        }
    } else {
        if (isRoyalFlush(values, colors)) {
            if (number % 6 == 0 && static_cast<int> (number * 0.01 * allInChance) % 10 == 0) return "Raise";
        } else if (isStraightFlush(values, colors)) {
            if (number % 6 == 0 && static_cast<int> (number * 0.01 * allInChance) % 10 == 0) return "Raise";
        } else if (repeated(values, 4)) {
            if (number % 6 == 0 && static_cast<int> (number * 0.01 * allInChance) % 10 == 0)
                return "Call";
        } else if (isFull(values)) {
            if (number % 6 == 0 && static_cast<int> (number * 0.01 * allInChance) % 10 == 0)
                return "Call";
        } else if (repeated(colors, 5)) {
            if (number % 6 == 0 && static_cast<int> (number * 0.01 * allInChance) % 10 == 0)
                return "Call";
        } else if (isStraight(values)) {
            if (number % 6 == 0 && static_cast<int> (number * 0.01 * allInChance) % 10 == 0)
                return "Call";
        } else if (repeated(values, 3)) {
            if (number % 6 == 0 && static_cast<int> (number * 0.01 * allInChance) % 10 == 0)
                return "Call";
        } else if (repeatedPairs(values, 2)) {
            if (number % 6 == 0 && static_cast<int> (number * 0.01 * allInChance) % 10 == 0)
                return "Call";
        } else if (repeated(values, 2)) {
            if (number % 6 == 0 && static_cast<int> (number * 0.01 * allInChance) % 10 == 0)
                return "Call";
        } else return "Fold";
    }

    return "Fold";
}