#include "Bot.h"
#include <vector>
#include <map>
#include <algorithm>
#include "../functions/poker.h"

using namespace std;

Bot::Bot(const string& name, const double allInChance) : Players(name) {
    this->name = name;
    this->allInChance = allInChance;
}

bool Bot::isWorth(const vector<Card>& table) const {
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
